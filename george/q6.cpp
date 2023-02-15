#include <stdlib.h>
#include <iostream >
using namespace std;

class Vector
{

private:
    int nn; // size of array; upper index is nn - 1
    double *v;

public:
    Vector();                               // empty
    explicit Vector(int n);                 // zero -based array
    Vector(int n, double a);                // initialize to constant value
    Vector(int n, const double *a);         // initialize to array
    Vector(const Vector &rhs);              // copy constructor
    Vector &operator=(const Vector &rhs);   // assignment
    inline double &operator[](const int i); // i’th element
    inline const double &operator[](const int i) const;
    inline int size() const;
    void resize(int newn);           // resize (contents not preserved )
    void assign(int newn, double a); // resize and assign a constant value
    ~Vector();
};

Vector::Vector(){
    nn = 0;
    v = NULL;
};
Vector::Vector(int n)
{
    v = new double[n];
    nn = n;
};

Vector::Vector(int n, double a)
{
    v = new double[n];
    std::fill_n(v, n, a);
};

Vector::Vector(int n, const double *a)
{
    // we do not check for under or overflow of accessing a
    // we can not calculate the length as we only have a pointer

    v = new double[n];
    nn = n;

    for (int i = 0; i < n; i++)
    {
        *(v + i) = *(a + i);
    }
};

Vector::Vector(const Vector &rhs)
{

    nn = rhs.nn;
    v = new double[nn];

    int i = 0;
    // for some reason when i declare i=0 in the () it acutally initialises to 4 (???)
    for (i; i < nn; i++)
    {
        *(v + i) = *(rhs.v + i);
    }
}; // copy constructor

Vector &Vector::operator=(const Vector &rhs)
{
    // assignment

    nn = rhs.nn;

    int i = 0;
    // for some reason when i declare i=0 in the () it acutally initialises to 4 (???)
    for (i; i < nn; i++)
    {
        *(v + i) = *(rhs.v + i);
    }

    return *this;
};

inline double &Vector::operator[](const int i)
{
    if (i >= nn)
    {
        cout << "Out of bounds error. Trying to access index " << i << " of Vector of length " << nn << endl;
    }
    double &return_val = *(v + i);
    return return_val;
};

inline const double &Vector::operator[](const int i) const
{
    if (i >= nn)
    {
        cout << "Out of bounds error. Trying to access index " << i << " of Vector of length " << nn << endl;
    }
    double &return_val = *(v + i);
    return return_val;
};

inline int Vector::size() const
{
    int size = nn;
    return size;
};

void Vector::resize(int newn)
{
    nn = newn;
    delete[] v;
    v = new double[nn];
};

void Vector::assign(int newn, double a)
{
    this->resize(newn);
    std::fill_n(v, nn, a);
};

Vector::~Vector()
{
    cout << "In destructor " << endl;
    delete[] v;
};

int main()
{
    Vector vec0; // empty vector
    Vector vec(3);
    Vector vec2(3, 2.0);

    double temp1[3] = {1.1, 2.1, 3.1};

    Vector vec31(2, temp1);
    Vector vec32(3, temp1);
    Vector vec33(4, temp1);

    Vector vec4(vec33);

    Vector vec5(3);
    vec5 = vec32;

    double &double6 = vec5[1];
    cout << double6 << endl;

    cout << "Size of vec5: " << vec5.size() << endl;

    cout << "end of file" << endl;

    return 0;
}