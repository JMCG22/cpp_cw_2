#pragma once

#include <stdlib.h>
#include <iostream >
#include <stdexcept>

using namespace std;

double normalCDF(double x);

template <typename T>
double interval_bisection(double y_target, double left,
                          double right, double epsilon, T functor, int max_iter = 1000)
{

    double y_left = functor(left);
    double y_right = functor(right);

    // check that the function has opposite signs at the endpoints
    // this is advised for the bisection method
    if ((y_left - y_target) * (y_right - y_target) > 0)
    {
        throw std::invalid_argument("The function has the same sign at the left and right endpoints.");
    }

    double y_mid = 0.0;
    double mid = 0.0;
    int iter = 0;

    // iterate until the midpoint is within the desired tolerance
    // or the maximum number of iterations is reached
    while (iter < max_iter)
    {
        mid = (left + right) / 2.0;
        y_mid = functor(mid);

        if (y_mid == y_target || (right - left) / 2.0 < epsilon)
        {
            // given float equality checks, most likely the root is within the tolerance
            // so return the midpoint
            return mid;
        }

        iter++;

        // update the left and right endpoints
        if ((y_mid - y_target) * (y_left - y_target) > 0)
        {
            // the midpoint has the same sign as the left endpoint so update the left endpoint
            left = mid;
            y_left = y_mid;
        }
        else
        {
            // the midpoint has the same sign as the right endpoint so update the right endpoint
            right = mid;
            y_right = y_mid;
        }
    }

    // if the maximum number of iterations is reached, return the midpoint
    // we throw an error instead of returning the midpoint, so that the user can
    // catch and decide what action to take
    throw std::runtime_error("The maximum number of iterations was reached");
}

class BlackScholesCallFunctor
{
private:
    double T, K, S, r;

public:
    BlackScholesCallFunctor(double T, double K, double S, double r);
    double operator()(double sigma) const;
};