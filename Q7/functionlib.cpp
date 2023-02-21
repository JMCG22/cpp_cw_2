//functionlib.cpp
//Definitions of functions for:
//1)Horners Algorithm to evaluate the normal cdf
//2)Normal cdf
//3)Black Scholes formula.

#include "functionLib.h"
#include "stdafx.h"

/* Use function overloading to define Horner's method and use it in the computation of the normal CDF*/
static inline double hornerFunction(double x, double a0, double a1) {
    return a0 + a1 * x;
}

static inline double hornerFunction(double x, double a0, double a1, double a2) {
    return a0 + x * hornerFunction(x, a1, a2);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3) {
    return a0 + x * hornerFunction(x, a1, a2, a3);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4) {
    return a0 + x * hornerFunction(x, a1, a2, a3, a4);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5) {
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5);
}

double normCDF(double x) {
    /* Approximate value of a normal CDF using formula*/
    double expression;
    double approx;

    if (x < 0 ) {
        return 1 - normCDF(-x);
    } else {
        double k = 1/(1 + (0.2316419 * x));
        expression = hornerFunction(k, 0, 0.31938153, -0.356563782, 1.781477937, -1.821255978, 1.330274429);

        approx = 1 - ((1 / sqrt(2 * M_PI)) * exp(-x*x*0.5)) * expression;

        return approx;
    }
}

double blackScholesCallPrice(double strike, double spot, double volatility, double interestRate, double time) {
   
    double d1;
    double d2;
    double price;

    d1 = (1 / (volatility * sqrt(time))) * (log(spot / strike) + (interestRate + (volatility*volatility / 2)) * time);
    d2 = d1 - volatility * sqrt(time);

    price = (normCDF(d1) * spot) - (normCDF(d2) * strike * exp(-interestRate * time));

    return price;
}


