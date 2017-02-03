#ifndef TURBINETABPAGE_HPP
#define TURBINETABPAGE_HPP

#include <QWidget>

class QcGaugeWidget;
class QLCDNumber;

class TurbineTabPage : public QWidget
{
public:
    TurbineTabPage();
    void initializeTurbine1();
    void initializeTurbine2();
    void initializeTurbine3();
    void initializeTurbine4();
    void initializeTurbine5();
private:
    QcGaugeWidget* mTurbineCounter1;
    QcGaugeWidget* mTurbineCounter2;
    QcGaugeWidget* mTurbineCounter3;
    QcGaugeWidget* mTurbineCounter4;
    QcGaugeWidget* mTurbineCounter5;

    QLCDNumber *mLcdScreen1;
    QLCDNumber *mLcdScreen2;
    QLCDNumber *mLcdScreen3;
    QLCDNumber *mLcdScreen4;
    QLCDNumber *mLcdScreen5;
};

#endif // TURBINETABPAGE_HPP
