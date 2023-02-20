#include "stdafx.h"
// #include "testing.h"


using namespace std;

/* The Vector interface states the methods and attributes all forms of vector should include */

class Vector
{
private:
    int nn; // size of array; upper index is nn - 1
    double *v;

    void set_n(int n)
    {
        if (n < 0)
        {
            throw std::invalid_argument("n must be positive");
        }
        nn = n;
    }

public:
    Vector();                             // empty
    explicit Vector(int n);               // zero-based array
    Vector(int n, double a);              // initialize to constant value
    Vector(int n, const double *a);       // initialize to array
    Vector(const Vector &rhs);            // copy constructor
    Vector &operator=(const Vector &rhs); // assignment

    inline double &operator[](const int i); // i'th element
    inline const double &operator[](const int i) const;
    inline int size() const;
    void resize(int newn);           // resize (contents not preserved)
    void assign(int newn, double a); // resize and assign a constant value

    ~Vector();
};

Vector::Vector() : nn{0}, v{NULL} {}

Vector::Vector(int n)
{
    set_n(n);
    v = new double[nn];
}

// Should we check size again? Not as nice but maybe
Vector::Vector(int n, double a)
{
    set_n(n);
    v = new double[nn];
    std::fill_n(v, nn, a);
}

Vector::Vector(int n, const double *a)
{
    set_n(n);
    v = new double[nn];
    for (int i = 0; i < nn; i++)
    {
        v[i] = a[i];
    }
}

Vector::Vector(const Vector &rhs)
{
    set_n(rhs.nn);
    v = new double[nn];

    for (int i = 0; i < nn; i++)
    {
        v[i] = rhs.v[i];
    }
}

Vector &Vector::operator=(const Vector &rhs)
{

    // Checking for self assignment. If we self assign then
    // we can not use the standard delete method as we will
    // delete what we need to assign
    if (this == &rhs)
    {
        return *this;
    }

    // If we already have something in the current vector then get rid of it
    // we always need to delete the current vector
    delete[] v;

    // Assign the length
    set_n(rhs.nn);
    v = rhs.v;

    // return the object
    return *this;
}

inline double &Vector::operator[](const int i)
{
    if ((i >= nn) || (i < 0))
    {
        throw std::out_of_range("Index out of bounds");
    }
    return v[i];
}

inline const double &Vector::operator[](const int i) const
{
    if ((i >= nn) || (i < 0))
    {
        throw std::out_of_range("Index out of bounds");
    }

    return v[i];
}

inline int Vector::size() const
{
    return nn;
}

void Vector::resize(int newn)
{
    set_n(newn);
    delete[] v;
    v = new double[nn];
}

void Vector::assign(int newn, double a)
{
    set_n(newn);
    delete[] v;
    v = new double[nn];
    std::fill_n(v, nn, a);
}

Vector::~Vector()
{
    delete[] v;
}

void ASSERT_EQUAL(const Vector &a, const vector<double> &b, std::string name_a, std::string name_b)
{

    // size check
    if (a.size() != b.size())
    {
        cout << "Vector " << name_a << " and vector " << name_b << " are not equal \n";
        return;
    }

    // empty check
    if (a.size() == 0)
    {
        if (b.empty())
        {
            cout << "Vector " << name_a << " and vector " << name_b << " are both empty \n";
        }
        else
        {
            cout << "Vector " << name_a << " is empty but vector " << name_b << " is not \n";
        }
        return;
    }

    // check for float equality within tolerace
    for (int i = 0; i < a.size(); i++)
    {
        if (abs(a[i] - b[i]) > 1e-10)
        {
            cout << "Vector " << name_a << " and vector " << name_b << " are not equal \n";
            return;
        }
    }
    cout << "Vector " << name_a << " and vector " << name_b << " are equal \n";
}

void ASSERT_EQUAL(const Vector &a, const Vector &b, std::string name_a, std::string name_b)
{
    // size check
    if (a.size() != b.size())
    {
        cout << "Vector " << name_a << " and vector " << name_b << " are not equal \n";
        return;
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (abs(a[i] - b[i]) > 1e-10)
        {
            cout << "Vector " << name_a << " and vector " << name_b << " are not equal \n";
            return;
        }
    }

    cout << "Vector " << name_a << " and vector " << name_b << " are equal \n";
}

void ASSERT_EQUAL_SIZE(int vector_size, int correct_vector_size, std::string name_vector)
{
    if (vector_size != correct_vector_size)
    {
        cout << "The size of vector " << name_vector << " is not correct \n";
    }
    else
    {
        cout << "The size of vector " << name_vector << " is correct \n";
    }
}

void ASSERT_EQUAL_INDEX(int vector_index, double &vector_element, double correct_element, std::string name_vector)
{
    if (vector_element != correct_element)
    {
        cout << "The element at index " << vector_index << " (" << vector_element << ") of vector " << name_vector << " is not correct \n";
    }
    else
    {
        cout << "The element at index " << vector_index << " (" << vector_element << ") of vector " << name_vector << " is correct \n";
    }
}

int main()
{
    // Initialise some test vectors using the C++ vector library
    std::vector<double> VEC0 = {};
    std::vector<double> VEC1 = {0., 0., 0.};
    std::vector<double> VEC2 = {2., 2., 2.};
    std::vector<double> VEC3 = {1.1, 2.1, 3.1};
    std::vector<double> VEC4 = {0., 0., 0., 0.};
    std::vector<double> VEC5 = {4., 4., 4., 4., 4., 4.};

    // Initialise some vectors from our new vector class
    Vector vec0;         // Empty vector
    Vector vec1(3);      // Zero based vector of size 3
    Vector vec2(3, 2.0); // Vector of size 3 with elements all equal to 2

    double temp1[3] = {1.1, 2.1, 3.1};

    Vector vec3(3, temp1); // Vector initialised to array temp1

    Vector vec4(vec3); // Vector copied from vec3
    Vector vec5(3);
    vec5 = vec3; // Vector equal to vec3

    double &double6 = vec5[1]; // Double set to the 1st element of vec5

    ASSERT_EQUAL(vec0, VEC0, "vec0", "VEC0");    // Check the empty vector is initialised correctly in our new class
    ASSERT_EQUAL(vec1, VEC1, "vec1", "VEC1");    // Check the zero-based vector is initialised correctly in our new class
    ASSERT_EQUAL(vec2, VEC2, "vec2", "VEC2");    // Check the constant value vector is initialised correctly in our new class
    ASSERT_EQUAL(vec3, VEC3, "vec3", "VEC3");    // Check vector initialised to an array is correct in our new class
    ASSERT_EQUAL(vec4, vec3, "vec4", "vec3");    // Check the copy constructor is correct in our new class
    ASSERT_EQUAL(vec5, vec3, "vec5", "vec3");    // Check the assignment constructor is correct in our new class
    ASSERT_EQUAL_INDEX(1, double6, 2.1, "vec5"); // Check the i-th element retriever is correct in our new class
    ASSERT_EQUAL_SIZE(vec5.size(), 3, "vec5");   // Check the size method is correct in our new class

    vec5.resize(4);                           // vec5 resized to 4
    ASSERT_EQUAL(vec5, VEC4, "vec5", "VEC4"); // Check the resize method is correct in our new class

    vec5.assign(6, 4);                        // vec5 resized to 6 with constant elements 4
    ASSERT_EQUAL(vec5, VEC5, "vec5", "VEC5"); // Check the assign method is correct in our new class

    return 0;
}
