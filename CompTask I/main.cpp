/**
* Яковлев Денис Михайлович (С)
* (Начало работы над: 28.02.2023 8:50 - ...)
*
* Тестовая задача №20
*
* Дано:
* f(x) = sqrt(x) - 2*cos(pi*x/2),
* [A,B]=[0,4.5]
* eps = 1e-8
* N >= 2 (Ошибка, если обратное)
*
* Этапы решения задачи:
* 1. Процедура отделения корней уравнения (1) на отрезке [A, B];
* 2. Уточнение корней уравнения (1) на отрезках перемены знака вида [ai, bi]
* a. Методом половинного деления (методом бисекции);
* b. Методом Ньютона (методом касательных);
* c. Модифицированным методом Ньютона;
* d. Методом секущих
* с заданной точностью eps>0 (eps – параметр задачи).
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
    cout << "Тема: Приближённые решения нелинейных уравнений" << endl;
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
    cout << '\n' << '\n' << "Метод бисекции: " << endl;
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

            cout << '\n' << "Между " << x << " и " << xNext << ":\n"<< "Начальное приближение: " << fappr << endl;
            cout << "Число итераций: " << m << "\nПриближённое решение: " << c << "\nДлина последнего отрезка: " << delta;
            cout << "\nНевязка |f(X)-0|: " << fabs(f(c)) << endl;

        }

        x = xNext;
        xNext += h;
    }
    cout << '\n' << "Число корней: " << counter << endl;

   // Clearing up data
    x = A; xNext = A + h;
    counter = 0;

    // 1.2 Tangent Method
    cout << '\n' << '\n' << "Метод Ньютона: " << endl;
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
                    cout << "Между "<< x << " и " << xNext << ": Ошибка: корень не может быть вычислен (попробуйте взять N побольше)" << endl;
                    m = 0;
                    break;
                }
            }
        }
        if(m){
            delta = fabs(c-a);

            cout << '\n' << "Между " << x << " и " << xNext << ":\n"<< "Начальное приближение: " << fappr << endl;
            cout << "Число итераций: " << m << "\nПриближённое решение: " << c << "\n|x{m}-x{m+1}|: " << delta;
            cout << "\nНевязка |f(X)-0|: " << fabs(f(c)) << endl;
        }
        x = xNext;
        xNext += h;
    }
    cout << '\n' << "Число корней: " << counter << endl;

    // Clearing up data
    x = A; xNext = A + h;
    counter = 0;

    // 1.3 Modified Tangent Method (MoTangeM)
    cout << '\n' << '\n' << "Модифицированный метод Ньютона: " << endl;
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
                    cout << "Между "<< x << " и " << xNext << ": Ошибка: корень не может быть вычислен (попробуйте взять N побольше)" << endl;
                    m = 0;
                    break;
                }
            }
        }
        if(m){
            delta = fabs(c-a);

            cout << '\n' << "Между " << x << " и " << xNext << ":\n"<< "Начальное приближение: " << fappr << endl;
            cout << "Число итераций: " << m << "\nПриближённое решение: " << c << "\n|x{m} - x{m-1}|: " << delta;
            cout << "\nНевязка |f(X)-0|: " << fabs(f(c)) << endl;
        }
        x = xNext;
        xNext += h;
    }
    cout << '\n' << "Число корней: " << counter << endl;

    // Clearing up data
    x = A; xNext = A + h;
    counter = 0;

    // 1.4 Secant Method
    cout << '\n' << '\n' << "Метод секущих: " << endl;
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
                    cout << "Между "<< x << " и " << xNext << ": Ошибка: корень не может быть вычислен (попробуйте взять N побольше)" << endl;
                    m = 0;
                    break;
                }
            }
        }
        if(m){
            delta = fabs(c - b);
            cout << '\n' << "Между " << x << " и " << xNext << ":\n"<< "Начальное приближение: " << fappr << endl;
            cout << "Число итераций: " << m << "\nПриближённое решение: " << c << "\n|x{m}-x{m-1}|: " << delta;
            cout << "\nНевязка |f(X)-0|: " << fabs(f(c)) << endl;
        }
        x = xNext;
        xNext += h;
    }
    cout << '\n' << "Число корней: " << counter << endl;
}
