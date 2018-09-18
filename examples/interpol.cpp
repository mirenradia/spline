#include <iostream>
#include <cmath>
#include <vector>
#include "spline.hpp"

template<class Function>
double deriv1(const Function& f, double x)
{
    double dx=1e-8*(1.0+std::abs(x));
    double x0=x-dx;
    double x2=x+dx;
    return (f(x2)-f(x0)) / (2.0*dx);
}

template<class Function>
double deriv2(const Function& f, double x)
{
    double dx=1e-6*(1.0+std::abs(x));
    double x0=x-dx;
    double x2=x+dx;
    return (f(x0)-2.0*f(x)+f(x2)) / (dx*dx);
}

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
    // set_boundary() is optional and if omitted, natural boundary condition,
    // f''(a)=f''(b)=0, will be used
    // note, if natural boundary conditions are not used then extrapolation
    // will be a quadratic function, unless the last argument is set to true,
    // which forces linear extrapolation, but this will violate second order
    // differentiability at the endpoint
    s.set_boundary(tools::spline<array_t>::second_deriv, 0.0,
                   tools::spline<array_t>::first_deriv, -2.0, false);
    s.set_points(X,Y);

    for(size_t i=0; i<X.size(); i++)
    {
        std::cout << X[i] << "\t" << Y[i] << "\n";
    }
    std::cout << "\n";

    for(int i=-50; i<250; i++)
    {
        double x=0.01*i;
        std::cout << x << "\t" << s(x) << "\t" << s.deriv(1,x) << "\t"
            << s.deriv(2,x) << "\t" << s.deriv(3,x) << "\n";
        // checking analytic derivatives and finite differences are close
        assert(fabs(s.deriv(1,x)-deriv1(s,x)) < 1e-8);
        assert(fabs(s.deriv(2,x)-deriv2(s,x)) < 1e-8);
    }
    std::cout << "\n";

    return 0;
}
