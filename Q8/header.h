#pragma once

#include <stdlib.h>
#include <iostream >
using namespace std;


double normalCDF(double x);

template <typename T>
double interval_bisection(double y_target, double left,
                          double right, double epsilon, T functor, int max_iter = 1000)
{

    double mid, y_mid;

    do
    {
        mid = (right + left) / 2;
        y_mid = functor(mid);

        if (y_target < y_mid)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
        max_iter--;

    } while ((abs(y_target - y_mid) > epsilon) && (max_iter > 0));

    if (max_iter == 0)
    {
        cout << "max iter reached. Returning current mid" << endl;
    }

    return mid;
}

class BlackScholesCallFunctor
{
private:
    double T, K, S, r;

public:
    BlackScholesCallFunctor(double T, double K, double S, double r);
    double operator()(double sigma) const;
};
