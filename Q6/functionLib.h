#pragma once

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
