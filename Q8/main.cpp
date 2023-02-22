#include <iostream>
#include <stdlib.h>

#include "header.h"

using namespace std;


int main()
{   
    // initialise inputs
    BlackScholesCallFunctor stock(0.25, 95.0, 100.0, 0.1);
    float call_price = 13.6953;
    int max_iter = 30;


    double left = 0.01;
    double right = 10.0;

    // check that the function has opposite signs at the endpoints
    if ( (stock(left) - call_price) * (stock(right) - call_price) > 0)
    {
        throw std::invalid_argument("The function has the same sign at the left and right endpoints.");
    }

    // calculate implied volatility
    double impl_vol = interval_bisection<BlackScholesCallFunctor>(call_price, 0.2, 1, 0.0001, stock, max_iter);
    cout << "The Black-Scholes call price is: " << call_price << endl;
    cout << "The implied volatility is: " << impl_vol << endl;

    return 0;
}
