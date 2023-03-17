#ifndef LINT_H_INCLUDED
#define LINT_H_INCLUDED

// Ётап 2.1 »нтерпол€ционный многочлен Ћагранжа
#include"Func.h"
#include<math.h>

using namespace std;


void LagrangeInterpolation(double *arg, size_t size, size_t deg, double x, double (*fnc)(double*, size_t, double, double), double (*f)(double))
{
    cout << endl << "»нтерпол€ци€ Ћагранжа:" << endl;
    double denominator;
    double numerator;
    double total = 0;
    double *ptr = arg;
    for(;ptr < (arg + deg); ptr++)
    {
        denominator = fnc(arg, deg, *ptr, *ptr);
        numerator = fnc(arg, deg, x, *ptr);
        // cout << "denominator: " << denominator << endl;
        total += numerator/denominator*(*(ptr+size));
        // cout << "total: " << total << endl;
    }
    cout << "«начение в точке интерпол€ции x = " << x << ": " << total << endl;
    cout << "јбсолютна€ погрешность: " << fabs(total - f(x)) << endl << endl;
}

#endif // LINT_H_INCLUDED
