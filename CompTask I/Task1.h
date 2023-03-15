#ifndef TASK1_H_INCLUDED
#define TASK1_H_INCLUDED

#include<iostream>
#include<math.h>

double f(double x)
{
    return sqrt(x) - 2*cos(M_PI_2*x);
}

double df(double x)
{
    return 1.0/(2*sqrt(x)) + M_PI*sin(M_PI_2*x);
}

double ddf(double x)
{
    return -1.0/(4*sqrt(x*x*x)) + M_PI*M_PI_2*cos(M_PI_2*x);
}

double fi(double x)
{
    return x - f(x)/df(x);
}

double dfi(double x)
{
    return f(x)*ddf(x)/(df(x)*df(x));
}

double secf(double x, double y)
{
    return x - f(x)/(f(x) - f(y))*(x - y);
}
#endif // TASK1_H_INCLUDED
