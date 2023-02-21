#include <cmath>
#include <iostream>
#include "header.h"

using namespace std;

double normalCDF(double x)
{
    /*
    Cumulative normal distribution function
    Using the error function
    */
    return erfc(-x / sqrt(2)) / 2;
}


BlackScholesCallFunctor::BlackScholesCallFunctor(double T, double K, double S, double r) : T(T), K(K), S(S), r(r){};

double BlackScholesCallFunctor::operator()(double sigma) const
{
    /*
    Calculate the price of a call option using the Black-Scholes formula, given a volatility
    */


    double d1 = (log(S / K) + (r + sigma * sigma / 2) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    double call_price = normalCDF(d1) * S - normalCDF(d2) * K * exp(-r * T);

    return call_price;
};