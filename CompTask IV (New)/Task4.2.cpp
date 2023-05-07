#include <functional>
#include"Task4.2.h"

double ZeroDegreeIntegral(double a, double b) {
    return b - a;
}

double FirstDegreeIntegral(double a, double b) {
    return pow(b, 2) / 2 - pow(a, 2) / 2;
}

double SecondDegreeIntegral(double a, double b) {
    return pow(b, 3) / 3 - pow(a, 3) / 3;
}

double ThirdDegreeIntegral(double a, double b) {
    return pow(b, 4) / 4 - pow(a, 4) / 4;
}

double FourthDegreeIntegral(double a, double b) {
    return pow(b, 5) / 5 - pow(a, 5) / 5;
}


void printIntegralValues(Integrator &integrator, int integralIndex) {
    std::vector<std::function<double(double, double)>> integralList = {ZeroDegreeIntegral, FirstDegreeIntegral,
                                                                       SecondDegreeIntegral, ThirdDegreeIntegral,
                                                                       FourthDegreeIntegral};

    double absoluteIntegralResult = integralList[integralIndex](integrator.GetStartingPoint(), integrator.GetEndingPoint());

    MethodResult integralResult[] = {integrator.JLeftRectangle(), integrator.JRightRectangle(),
                                     integrator.JMiddleRectangle(), integrator.JTrapezoid(),
                                     integrator.JSimpson(), integrator.JThreeEighths()};

    std::vector<const wchar_t *> integralName = {L"Левые прямоугольники: ", L"Правые прямоугольники: ", L"Средние прямоугольники: ",
                             L"Трапеция: ", L"Симпсон: ", L"Три восьмых: "};

    for (int i = 0; i < 6; ++i) {
        wcout << endl << integralName[i] << integralResult[i].value << endl;
        wcout << L"Абсолютная фактическая погрешность: " << fabs(integralResult[i].value - absoluteIntegralResult) << endl;
        wcout << L"Теоретическая погрешность: " << integralResult[i].error << endl;
    }
}

void Task4_2() {
    string inputString[] = {"1", "x", "x^2", "x^3", "x^4"};

    double startingPoint;
    double endingPoint;
    int segmentNum;

//    getline(cin, inputFormula);



    wcout << L"Задание 4.1, 4.2" << endl;

    wcout << L"Введите значения:" << endl;

    wcout << "A: ";
    cin >> startingPoint;
    wcout << "B: ";
    cin >> endingPoint;
    wcout << "m: ";
    cin >> segmentNum;

    Integrator inputIntegrator[5];
    for (int i = 0; i < 5; ++i) {
        inputIntegrator[i] = Integrator(Formula(inputString[i]), startingPoint, endingPoint, segmentNum);
    }

    for (int i = 0; i < 5; ++i) {
        wcout << L"Формула на входе: ";
        cout << inputIntegrator[i].GetFormula().GetFormula() << endl;
        printIntegralValues(inputIntegrator[i], i);
        cout << endl << endl;
    }
}