#include "header.h"

using namespace std;

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
            cout << "PASSED: Vector " << name_a << " and vector " << name_b << " are both empty \n";
        }
        else
        {
            cout << "FAILED: Vector " << name_a << " is empty but vector " << name_b << " is not \n";
        }
        return;
    }

    // check for float equality within tolerace
    for (int i = 0; i < a.size(); i++)
    {
        if (abs(a[i] - b[i]) > 1e-10)
        {
            cout << "FAILED: Vector " << name_a << " and vector " << name_b << " are not equal \n";
            return;
        }
    }
    cout << "PASSED: Vector " << name_a << " and vector " << name_b << " are equal \n";
}

void ASSERT_EQUAL(const Vector &a, const Vector &b, std::string name_a, std::string name_b)
{
    // size check
    if (a.size() != b.size())
    {
        cout << "FAILED: Vector " << name_a << " and vector " << name_b << " are not equal \n";
        return;
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (abs(a[i] - b[i]) > 1e-10)
        {
            cout << "FAILED: Vector " << name_a << " and vector " << name_b << " are not equal \n";
            return;
        }
    }

    cout << "PASSED: Vector " << name_a << " and vector " << name_b << " are equal \n";
}


bool double_equal(double a, double b, double tol = 1e-10)
{
    return abs(a - b) < tol;
}

void ASSERT_EQUAL_INDEX(Vector vector, int index, double correct_element, std::string name_vector)
{
    if (abs(vector[index] - correct_element) > 1e-10)
    {
        cout << "PASSED: The element at index " << index << " (" << vector[index] << ") of vector " << name_vector << " is not correct \n";
    }
    else
    {
        cout << "FAILED: The element at index " << index << " (" << vector[index] << ") of vector " << name_vector << " is correct \n";
    }
}

void test_negative_vector()
{
    cout << "Testing negative vector size: ";
    try
    {
        Vector vec0(-1);
        cout << "FAILED" << endl;
    }
    catch (std::invalid_argument &e)
    {
        cout << "PASSED " << endl;
    }
}

void test_index_out_of_bounds()
{
    cout << "Testing index out of bounds: ";
    try
    {
        Vector vec(3);
        vec[3] = 1;
        cout << "FAILED" << endl;
    }
    catch (std::out_of_range &e)
    {
        cout << "PASSED " << endl;
    }
}

void test_destroy_vector()
{
    cout << "Testing destroy vector: ";
    Vector vec(3);
    vec.~Vector();

    if (vec.array() == NULL)
    {
        cout << "PASSED " << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
}

void test_assign()
{
    cout << "Testing assign: ";
    Vector vec(3);
    vec.assign(3, 1.0);
    ASSERT_EQUAL(vec, {1.0, 1.0, 1.0}, "vec", "{1.0, 1.0, 1.0}");
}

void test_resize()
{
    cout << "Testing resize: ";
    Vector vec(3);
    vec.resize(4);
    ASSERT_EQUAL(vec, {0.0, 0.0, 0.0, 0.0}, "vec", "{0.0, 0.0, 0.0, 0.0}");
}

void test_const_index()
{
    cout << "Testing const index: ";
    const Vector vec(3);
    //How is this really testing the constant porperty, Maybe we can try to modify and catch the error
    if (double_equal(vec[0], 0.0))
    {
        cout << "PASSED " << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
}

void test_index()
{
    cout << "Testing index: ";
    Vector vec(3);

    if (double_equal(vec[0], 0.0))
    {
        cout << "PASSED " << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
}

void test_copy_constructor()
{
    cout << "Testing copy constructor: ";
    Vector vec(3);
    Vector vec2(vec);
    ASSERT_EQUAL(vec, vec2, "vec", "vec2");
}

void test_assignment_operator()
{
    cout << "Testing assignment operator: ";
    Vector vec(3);
    Vector vec2 = vec;
    ASSERT_EQUAL(vec, vec2, "vec", "vec2");
}

void test_default_constructor()
{
    cout << "Testing default constructor: ";
    Vector vec;
    if (vec.size() == 0)
    {
        cout << "PASSED " << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
}

void test_array_constructor()
{
    cout << "Testing array constructor: ";
    double array[3] = {1.0, 2.0, 3.0};
    Vector vec(3, array);
    ASSERT_EQUAL(vec, {1.0, 2.0, 3.0}, "vec", "{1.0, 2.0, 3.0}");
}

void test_constant_constructor()
{
    cout << "Testing constant constructor: ";
    Vector vec(3, 1.0);
    ASSERT_EQUAL(vec, {1.0, 1.0, 1.0}, "vec", "{1.0, 1.0, 1.0}");
}

int main()
{
    // tests for error handling
    test_negative_vector();
    test_index_out_of_bounds();

    // tests for constructors
    test_default_constructor();
    test_copy_constructor();
    test_constant_constructor();
    test_array_constructor();

    // othr tests
    test_assignment_operator();

    test_index();
    test_const_index();

    test_resize();
    test_assign();
    test_destroy_vector();

    return 0;
}
