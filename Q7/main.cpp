#include "header.h"
#include <iostream>

using namespace std;


int main()
{
    // initialise inputs
    double strike = 95.0;
    double s_0 = 100.;
    double vol = 0.5;
    double r = 0.1;
    double t = 0.25;

    // calculate call price
    double call_cost = bs_call_price(s_0, strike, vol, r, t);

    cout << "The Black-Scholes option price is: " << call_cost << endl;

    return 0;
}
