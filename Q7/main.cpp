
#include "stdafx.h"
#include "functionLib.h"

using namespace std;

int main()
{
    double price;
    double strike = 95;
    double spot = 100;
    double volatility = 0.5;
    double interestRate = 0.1;
    double time = 0.25;

    price = blackScholesCallPrice(strike, spot, volatility, interestRate, time);

    cout << "The Black-Scholes option price is: " << price << "\n";
}
