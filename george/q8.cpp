#include <cmath>
#include <iostream>

using namespace std;

double normalCDF(double x)
{
    return erfc(-x / sqrt(2)) / 2;
}

template <typename T>
double interval_bisection(double y_target, double left,
                          double right, double epsilon, T functor)
{
    // cout << "Trying to find solution to " << y_target << endl;
    // cout << "Left: "<< left << " right: " << right << endl;
    double mid, y_mid;
    do
    {
        mid = (right + left) / 2;
        y_mid = functor(mid);

        // cout << "Mid is " << y_mid << endl;

        if (y_target < y_mid){
            // cout << "moving right to " << mid << endl;
            right = mid;
        }
        else {
            // cout << "moving left to " << mid << endl;
            left = mid;
        }

    } while (abs(y_target-y_mid) > epsilon);

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

BlackScholesCallFunctor::BlackScholesCallFunctor(double T, double K, double S, double r) : T(T), K(K), S(S), r(r){};

double BlackScholesCallFunctor::operator()(double sigma) const
{
    // code to price via bs, can be called with obj(sigma)

    // cout << "in BS() " << endl;
    double d1 = (log(S / K) + (r + sigma * sigma / 2) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    double call_price = normalCDF(d1) * S - normalCDF(d2) * K * exp(-r * T);

    return call_price;
};

int main()
{
    BlackScholesCallFunctor stock(0.25, 95.0, 100.0, 0.1);
    float call_price = 13.6953;
    // double call_price = stock(0.5);
    double impl_vol = interval_bisection(call_price, 0.0001, 10.0, 0.001, stock);
    cout << "call price: " << call_price << endl;
    cout << "implied vol: " << impl_vol << endl;

    return 0;
}