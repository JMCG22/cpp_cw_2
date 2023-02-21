#include <iostream>
#include <cmath>

using namespace std;

double normalCDF(double x) 
{
    return erfc(-x / sqrt(2)) / 2;
}

double bs_call_price(double s0, double strike, double vol, double r, double t ){

    double d1 = (log(s0/strike) + (r + vol*vol/2)*t)/ (vol*sqrt(t));
    double d2 = d1 - vol*sqrt(t);

    double call_price = normalCDF(d1)*s0 - normalCDF(d2)*strike*exp(-r*t);

    return call_price;                  
}

int main()
{
    double strike = 95.0;
    double s_0 = 100.;
    double vol = 0.5;
    double r = 0.1;
    double t = 0.25;


    double call_cost = bs_call_price(s_0, strike, vol, r, t);
    cout << "Call cost: " << call_cost << endl;

    return 0;
}
