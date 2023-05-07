#ifndef INTEGRATOR_H_INCLUDED
#define INTEGRATOR_H_INCLUDED

#include"RPN.h"
#include"MethodResult.h"

class Integrator {
public:
    Integrator(const Formula &formula, double startingPoint, double endingPoint, int segmentNum) {
        _formula = Formula(formula);
        SetValues(startingPoint, endingPoint, segmentNum);
    }

    explicit Integrator(const Formula &formula) {
        _formula = formula;
    }

    Integrator() = default;

    void SetValues(double startingPoint, double endingPoint, int segmentNum);

    MethodResult JLeftRectangle();

    MethodResult JRightRectangle();

    MethodResult JMiddleRectangle();

    MethodResult JTrapezoid();

    MethodResult JSimpson();

    MethodResult JThreeEighths();

    double ZeroDerivative(double x, double step);

    double FirstDerivative(double x, double step = -1);

    double SecondDerivative(double x, double step = -1);

    double FourthDerivative(double x, double step = -1);

    double GetStartingPoint() const { return _startingPoint; }

    double GetEndingPoint() const { return _endingPoint; }

    int GetSegmentNum() const { return _segmentNum; }

    void ModifySegmentNum(int modifier = -1) {if(modifier > 0) _segmentNum *= modifier;}

    Formula GetFormula() const{return _formula;}

    double findModuleMax(int derivativeIndex);


private:

    Formula _formula;

    double _startingPoint = 0;

    double _endingPoint = 1;

    int _segmentNum = 10;

    static bool ValidateValues(double startingPoint, double endingPoint, int segmentNum);

//    Formula IntegrateFormula();
};

//template<double (Integrator::*Method)()>
//void printIntegralValues(Integrator &integrator);


#endif // INTEGRATOR_H_INCLUDED
