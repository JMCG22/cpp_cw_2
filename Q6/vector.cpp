#include "header.h"
#include <iostream>

using namespace std;

/* The Vector interface states the methods and attributes all forms of vector should include */

void Vector::set_n(int n)
{
    if (n < 0)
    {
        throw std::invalid_argument("n must be positive");
    }
    nn = n;
}

Vector::Vector(){
    nn = 0;
    v = new double[nn];
}

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

    // Delete the current vector
    resize(rhs.nn);

    // Copy the values from the rhs to the current vector
    for (int i = 0; i < nn; i++)
    {
        v[i] = rhs.v[i];
    }

    // return the object
    return *this;
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
    v = NULL;
}