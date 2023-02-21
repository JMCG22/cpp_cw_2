#include <cmath>
#include <random>
#include "header.h"


double normalCDF(double x) 
{   
    /*
    Cumulative normal distribution function
    Using the error function
    */

    return erfc(-x / sqrt(2)) / 2;
}

double bs_call_price(double s0, double strike, double vol, double r, double t )
{
    /*
    Calculate the price of a call option using the Black-Scholes formula
    */

    double d1 = (log(s0/strike) + (r + vol*vol/2)*t)/ (vol*sqrt(t));
    double d2 = d1 - vol*sqrt(t);

    double call_price = normalCDF(d1)*s0 - normalCDF(d2)*strike*exp(-r*t);

    return call_price;                  
}