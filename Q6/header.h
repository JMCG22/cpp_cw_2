#pragma once

#include <iostream>
#include <cmath>
#include <new>
#include <vector>

using namespace std;


class Vector
{
private:
    int nn; // size of array; upper index is nn - 1
    double *v;
    void set_n(int n);

public:
    Vector();                               // empty
    explicit Vector(int n);                 // zero-based array
    Vector(int n, double a);                // initialize to constant value
    Vector(int n, const double *a);         // initialize to array
    Vector(const Vector &rhs);              // copy constructor
    Vector &operator=(const Vector &rhs);   // assignment
    inline double &operator[](const int i); // i'th element
    inline const double &operator[](const int i) const;
    inline int size() const;
    void resize(int newn);           // resize (contents not preserved)
    void assign(int newn, double a); // resize and assign a constant value
    inline double *array() const;
    ~Vector();
};

inline double &Vector::operator[](const int i)
{
    //I think nn should be replaced by size() as we dont need to access the object properties 
    if ((i >= size()) || (i < 0))
    {
        throw std::out_of_range("Index out of bounds");
    }
    return v[i];
}

inline const double &Vector::operator[](const int i) const
{
    // cout << "const [] called" << endl;
    if ((i >= size()) || (i < 0))
    {
        throw std::out_of_range("Index out of bounds");
    }

    return v[i];
}

inline int Vector::size() const
{
    return nn;
}
inline double *Vector::array() const
{
    return v;
}
