/**
* ������� ����� ���������� (�)
* (������ ������ ���: 28.02.2023 8:50 - ...)
*
* �������� ������ �20
*
* ����:
* f(x) = sqrt(x) - 2*cos(pi*x/2),
* [A,B]=[0,4.5]
* eps = 1e-8
* N >= 2 (������, ���� ��������)
*
* ����� ������� ������:
* 1. ��������� ��������� ������ ��������� (1) �� ������� [A, B];
* 2. ��������� ������ ��������� (1) �� �������� �������� ����� ���� [ai, bi]
* a. ������� ����������� ������� (������� ��������);
* b. ������� ������� (������� �����������);
* c. ���������������� ������� �������;
* d. ������� �������
* � �������� ��������� eps>0 (eps � �������� ������).
*
*
*/



#include"Task1.h"
#include"Task2.h"
#include<math.h>
#include<assert.h>
#include<iostream>
#include<locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"russian");
    cout.precision(12);
    cout << "����: ����������� ������� ���������� ���������" << endl;
    cout << "f(x) = sqrt(x) - 2*cos(pi*x/2)" << endl;
    //double A = 0, B = 4.5;
    //double eps = 1e-8;
    double A, B;
    double eps;
    size_t N;


    /* 0. Entering data and checking-in */
    cout << "A = ";cin >> A;
    cout << "B = ";cin >> B;
    cout << "eps = ";cin >> eps;
    cout << "N = "; cin >> N; cout << endl;
    assert(N>=2 || eps>0);

    /* 1. Decoupling roots on [A, B] */

    double h = (B-A)/N;
    double x = A, xNext = A + h;
    size_t counter = 0;

    // 1.1 Bisection Method
    cout << '\n' << '\n' << "����� ��������: " << endl;
    while(x < B)
    {
        double a = x, b = xNext;
        double c, delta, fappr=(a+b)/2;
        size_t m = 0;
        if(f(a)*f(b)<=0)
        {
            counter++;
            while(b - a >= 2*eps){
                m++;
                c = (a+b)/2;
                if(f(b)*f(c)<=0)
                {
                    a = c;
                } else b = c;
            }
            delta = (b-a)/2;

            cout << '\n' << "����� " << x << " � " << xNext << ":\n"<< "��������� �����������: " << fappr << endl;
            cout << "����� ��������: " << m << "\n����������� �������: " << c << "\n����� ���������� �������: " << delta;
            cout << "\n������� |f(X)-0|: " << fabs(f(c)) << endl;

        }

        x = xNext;
        xNext += h;
    }
    cout << '\n' << "����� ������: " << counter << endl;

   // Clearing up data
    x = A; xNext = A + h;
    counter = 0;

    // 1.2 Tangent Method
    cout << '\n' << '\n' << "����� �������: " << endl;
    while(x < B)
    {
        double a = x, b = xNext;
        double c = (a+b)/2, delta, fappr=(a+b)/2;
        size_t m = 0;
        if(f(a)*f(b) <= 0){
            counter++;
            while(fabs(c - a) >= eps){
                m++;
                a = c;
                c = fi(c);
                if(c > xNext || c < x){
                    cout << "����� "<< x << " � " << xNext << ": ������: ������ �� ����� ���� �������� (���������� ����� N ��������)" << endl;
                    m = 0;
                    break;
                }
            }
        }
        if(m){
            delta = fabs(c-a);

            cout << '\n' << "����� " << x << " � " << xNext << ":\n"<< "��������� �����������: " << fappr << endl;
            cout << "����� ��������: " << m << "\n����������� �������: " << c << "\n|x{m}-x{m+1}|: " << delta;
            cout << "\n������� |f(X)-0|: " << fabs(f(c)) << endl;
        }
        x = xNext;
        xNext += h;
    }
    cout << '\n' << "����� ������: " << counter << endl;

    // Clearing up data
    x = A; xNext = A + h;
    counter = 0;

    // 1.3 Modified Tangent Method (MoTangeM)
    cout << '\n' << '\n' << "���������������� ����� �������: " << endl;
    while(x < B)
    {
        double a = x, b = xNext;
        double c = (a+b)/2, delta, fappr=(a+b)/2;
        double cf = df(c);
        size_t m = 0;
        if(f(a)*f(b) <= 0){
            counter++;
            while(fabs(c - a) >= eps){
                m++;
                a = c;
                c = c - f(c)/cf;
                if(c > xNext || c < x){
                    cout << "����� "<< x << " � " << xNext << ": ������: ������ �� ����� ���� �������� (���������� ����� N ��������)" << endl;
                    m = 0;
                    break;
                }
            }
        }
        if(m){
            delta = fabs(c-a);

            cout << '\n' << "����� " << x << " � " << xNext << ":\n"<< "��������� �����������: " << fappr << endl;
            cout << "����� ��������: " << m << "\n����������� �������: " << c << "\n|x{m} - x{m-1}|: " << delta;
            cout << "\n������� |f(X)-0|: " << fabs(f(c)) << endl;
        }
        x = xNext;
        xNext += h;
    }
    cout << '\n' << "����� ������: " << counter << endl;

    // Clearing up data
    x = A; xNext = A + h;
    counter = 0;

    // 1.4 Secant Method
    cout << '\n' << '\n' << "����� �������: " << endl;
    while(x < B){
        double a = x, b = xNext;
        double c = secf(b, a), delta, fappr=secf(b, a);
        size_t m = 0;
        if(f(a)*f(b)<=0){
            counter++;
            while(fabs(c - b) >= eps){
                m++;
                a = b;
                b = c;
                c = secf(c, a);
                if(c < x || c > xNext){
                    cout << "����� "<< x << " � " << xNext << ": ������: ������ �� ����� ���� �������� (���������� ����� N ��������)" << endl;
                    m = 0;
                    break;
                }
            }
        }
        if(m){
            delta = fabs(c - b);
            cout << '\n' << "����� " << x << " � " << xNext << ":\n"<< "��������� �����������: " << fappr << endl;
            cout << "����� ��������: " << m << "\n����������� �������: " << c << "\n|x{m}-x{m-1}|: " << delta;
            cout << "\n������� |f(X)-0|: " << fabs(f(c)) << endl;
        }
        x = xNext;
        xNext += h;
    }
    cout << '\n' << "����� ������: " << counter << endl;
}
