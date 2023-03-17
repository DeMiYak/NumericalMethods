#ifndef NINT_H_INCLUDED
#define NINT_H_INCLUDED

// Ётап 2.2 »нтерпол€ционный многочлен Ќьютона
#include"Func.h"
#include<math.h>

void NewtonInterpolation(double *arg, size_t size, size_t deg, double x, double (*fnc)(double*, size_t, double, double), double (*f)(double))
{
    cout << "»нтерпол€ци€ Ќьютона:" << endl;
    size_t degp = deg + 1;
    double space[degp][deg], total = 0, product = 1;
    for(size_t i = 0; i < deg; i++)
    {
        space[0][i] = arg[i];
        space[1][i] = arg[size+i];
    }
    for(size_t i = 2; i < degp; i++)
    {
        for(size_t j = 0; j < degp - i; j++)
        {
            space[i][j] = (space[i-1][j+1]-space[i-1][j])/(space[0][j+i-1]-space[0][j]);
        }
    }

    /*
    for(size_t i = 0; i < 2; i++)
    {
        cout << "f" << i << ": ";
        for(size_t j = 0; j < degp; j++)
            cout << space[i][j] << ' ';
        cout << endl;
    }

    for(size_t i = 2; i < degp; i++)
    {
        cout << "f" << i << ": ";
        for(size_t j = 0; j < degp - i; j++)
        cout << space[i][j] << ' ';
        cout << endl;
    }
    */

    for(size_t i = 1; i < degp; i++)
    {
        total += space[i][0]*product;
        product *= (x - arg[i-1]);
    }

    cout << "«начение в точке интерпол€ции х = " << x << ": " << total << endl;
    cout << "јбсолютна€ погрешность: " << fabs(total - f(x)) << endl << endl;
}

#endif // NINT_H_INCLUDED
