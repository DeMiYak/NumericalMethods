#ifndef LINT_H_INCLUDED
#define LINT_H_INCLUDED

// ���� 2.1 ���������������� ��������� ��������
#include"Func.h"
#include<math.h>

using namespace std;


void LagrangeInterpolation(double *arg, size_t size, size_t deg, double x, double (*fnc)(double*, size_t, double, double), double (*f)(double))
{
    cout << endl << "������������ ��������:" << endl;
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
    cout << "�������� � ����� ������������ x = " << x << ": " << total << endl;
    cout << "���������� �����������: " << fabs(total - f(x)) << endl << endl;
}

#endif // LINT_H_INCLUDED
