#include <iostream>
#include <vector>
#include "spline.hpp"

template <class T>
using array_t = std::vector<T>;

int main(int argc, char** argv)
{

    array_t<double> X(5), Y(5);
    X[0]=0.1;
    X[1]=0.4;
    X[2]=1.2;
    X[3]=1.8;
    X[4]=2.0;
    Y[0]=0.1;
    Y[1]=0.7;
    Y[2]=0.6;
    Y[3]=1.1;
    Y[4]=0.9;

    tools::spline<array_t> s;
    s.set_points(X,Y);    // currently it is required that X is already sorted

    double x=1.5;

    std::cout << "spline at " << x << " is " << s(x) << "\n";

    return 0;
}
