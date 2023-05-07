#include <functional>
#include"Task4.3.h"
#include"Task4.2.h"

MethodResult principleRungeValue(pair<MethodResult, MethodResult> integralResult, int modifier, int derivativeIndex){
    double value = (pow(modifier, derivativeIndex)*integralResult.second.value - integralResult.first.value)/(pow(modifier, derivativeIndex) - 1);
    return value;
}

void printIntegralValuesModified(pair<Integrator, Integrator> &integrator, int integralIndex){
    std::vector<std::function<double(double, double)>> integralList = {ZeroDegreeIntegral, FirstDegreeIntegral,
                                                                       SecondDegreeIntegral, ThirdDegreeIntegral,
                                                                       FourthDegreeIntegral};

    int modifier = integrator.second.GetSegmentNum()/integrator.first.GetSegmentNum();

    double absoluteIntegralResult = integralList[integralIndex](integrator.first.GetStartingPoint(), integrator.first.GetEndingPoint());

    pair<MethodResult, MethodResult> integralResult[] = {
            {integrator.first.JLeftRectangle(), integrator.second.JLeftRectangle()},
            {integrator.first.JRightRectangle(), integrator.second.JRightRectangle()},
            {integrator.first.JMiddleRectangle(), integrator.second.JMiddleRectangle()},
            {integrator.first.JTrapezoid(), integrator.second.JTrapezoid()},
            {integrator.first.JSimpson(), integrator.second.JSimpson()},
                                     };

    MethodResult principleRungeResult[] = {
            principleRungeValue(integralResult[0], modifier, 1),
            principleRungeValue(integralResult[1], modifier, 1),
            principleRungeValue(integralResult[2], modifier, 2),
            principleRungeValue(integralResult[3], modifier, 2),
            principleRungeValue(integralResult[4], modifier, 4),

    };

    std::vector<const wchar_t *> integralName = {L"Левые прямоугольники: ", L"Правые прямоугольники: ", L"Средние прямоугольники: ",
                                                 L"Трапеция: ", L"Симпсон: "};

    for (int i = 0; i < 5; ++i) {
        wcout << endl << integralName[i] << endl;
        wcout << L"Без множителя l: " << endl << endl;
        wcout << "Значение: " << integralResult[i].first.value << endl;
        wcout << L"Абсолютная фактическая погрешность: " << fabs(integralResult[i].first.value - absoluteIntegralResult) << endl;
        wcout << L"Теоретическая погрешность: " << integralResult[i].first.error << endl << endl;

        wcout << L"С множителем l: " << endl << endl;
        wcout << "Значение: " << integralResult[i].second.value << endl;
        wcout << L"Абсолютная фактическая погрешность: " << fabs(integralResult[i].second.value - absoluteIntegralResult) << endl;
        wcout << L"Теоретическая погрешность: " << integralResult[i].second.error << endl << endl;

        wcout << L"Принцип Рунге: " << endl << endl;
        wcout << L"Значение: " << principleRungeResult[i].value << endl;
        wcout << L"Абсолютная фактическая погрешность: " << fabs(principleRungeResult[i].value - absoluteIntegralResult) << endl;
    }
}



void Task4_3(){
    string inputString[] = {"1", "x", "x^2", "x^3", "x^4"};

    wcout << endl << endl << L"Задание 4.3" << endl;

    double startingPoint;
    double endingPoint;
    int segmentNum;
    int modifier;

    wcout << L"Введите значения:" << endl;

    wcout << "A - startingPoint: ";
    cin >> startingPoint;
    wcout << "B - endingPoint: ";
    cin >> endingPoint;
    wcout << "m segments: ";
    cin >> segmentNum;
    wcout << "l-times modifier: ";
    cin >> modifier;


    std::vector<std::pair<Integrator,Integrator>> inputIntegrator;
    for (int i = 0; i < 5; ++i) {
        Integrator enteredIntegrator = Integrator(Formula(inputString[i]), startingPoint, endingPoint, segmentNum);
        inputIntegrator.emplace_back(enteredIntegrator,enteredIntegrator);
        inputIntegrator[i].second.ModifySegmentNum(modifier);
    }

    for (int i = 0; i < 5; ++i) {
        wcout << L"Формула на входе: ";
        cout << inputIntegrator[i].second.GetFormula().GetFormula() << endl;
        printIntegralValuesModified(inputIntegrator[i], i);
        cout << endl << endl;
    }
}