/**
* Яковлев Денис Михайлович (С++)
*
* 02.05.2023 (21:15) - ...
*
* Решение задач по приближённому вычислению интеграла
* по квадратурным формулам (серия из трёх подзадач)
*
* 1-ая задача: приближённое вычисление интеграла по квадратурным формулам
*
*/



#include<iostream>
#include"Task4.2.h"
#include"Task4.3.h"

using namespace std;

int main() {
    _wsetlocale(LC_ALL, L"russian");
    wcout.precision(16);
    cout.precision(16);


    // Task4_2();

    Task4_3();

//    string input;
//    wcout << L"Введите формулу: ";
//
//    getline(cin, input);
//
//    Formula formula = Formula(input);
//    double x;
//
//    cout << "x: ";
//    cin >> x;
//
//    wcout << L"Значение: " << formula.Evaluate(x);
//
//    return 0;
}
