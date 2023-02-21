#include <iostream>
#include <stdlib.h>

#include "header.h"

using namespace std;


int main()
{   
    BlackScholesCallFunctor stock(0.25, 95.0, 100.0, 0.1);
    float call_price = 13.6953;
    int max_iter = 30;

    double impl_vol = interval_bisection<BlackScholesCallFunctor>(call_price, 0.0001, 10.0, 0.0001, stock, max_iter);
    cout << "call price: " << call_price << endl;
    cout << "implied vol: " << impl_vol << endl;

    return 0;
}