#include "functionLib.h"
#include "stdafx.h"

/* The Vector interface states the methods and attributes all forms of vector should include */

class Vector {
    private:
        int nn; // size of array; upper index is nn - 1
        double* v;
    
    public:
        Vector(); // empty
        explicit Vector(int n); // zero-based array
        Vector(int n, double a); // initialize to constant value
        Vector(int n, const double* a); // initialize to array
        Vector(const Vector& rhs); // copy constructor
        Vector& operator=(const Vector& rhs); // assignment

        inline double& operator[](const int i); // i'th element
        inline const double& operator[](const int i) const;
        inline int size() const;
        void resize(int newn); // resize (contents not preserved)
        void assign(int newn, double a); // resize and assign a constant value
        
        ~Vector();
        
};

Vector::Vector() : nn {0}, v {new double[0]} {};

explicit Vector::Vector(int n) : nn {std::max(n, 0)} {
    if (nn) {
        v = new double[n];
        v = {};
    }
}

// Should we check size again? Not as nice but maybe
Vector::Vector(int n, double a) : nn {std::max(n, 0)}, v {&a} {};

Vector::Vector(int n, const double* a) : nn {std::max(n, 0)} {
    if (nn) {
        v = new double[n];
        for (int i = 0; i < nn; i++) {
            v[i] = a[i];
        }
    }
}

Vector::Vector(const Vector& rhs) : nn {rhs.nn}, v {rhs.v} {}

Vector& Vector::operator=(const Vector& rhs) {
    
    // Checking for self assignment. If we self assign then we can not use the standard delete method as we will delete what we need to assign
    if (this == &rhs) {
        return *this;
    }
    
    // If we already have something in the current vector then get rid of it
    if (v) {
        delete[] v;
    }
    
    // Assign the length
    nn = rhs.nn;
    v = nullptr;
    
    // copy the data from rhs to v
    if (nn) {
        v = new double[nn];
    }
    
    for (int i = 0; i < nn; i++) {
        v[i] = rhs.v[i];
    }
    
    // return the object
    return *this;
}

inline double& Vector::operator[](const int i) {
    if (i < nn - 1) {
        return v[i];
    } else {
        std::cout << "Index " << i << " out of bounds";
    }
}

inline const double& Vector::operator[](const int i) const {
    if (i < nn - 1) {
        return v[i];
    } else {
        std::cout << "Index " << i << " out of bounds";
    }
}

inline int Vector::size() const {
    return nn;
}

void Vector::resize(int newn) {
    delete[] v;

    if (newn) {
        nn = newn;
        v = new double[nn];
    }
}

void Vector::assign(int newn, double a) {
    delete[] v;

    if (newn) {
        nn = newn;
        v = new double[nn];
        v = &a;
    }
}

Vector::~Vector() { 
    delete[] v; 
}