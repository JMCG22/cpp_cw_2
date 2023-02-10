#pragma once

/* Approximate formula to find the normal CDF */
double normCDF(double x);

/* Get the Black-Scholes price for given inputs*/
double blackScholesCallPrice(double strike, double spot, double volatility, double interestRate, double time);