#ifndef TURBINETABPAGE_HPP
#define TURBINETABPAGE_HPP

#include <QWidget>

class QcGaugeWidget;
class QSerialPort;
class QcNeedleItem;
class QGroupBox;
class TurbineWidget;

class TurbineTabPage : public QWidget
{
    Q_OBJECT
public:
    TurbineTabPage();
private slots:
    void serialReciver();
    void setTurbineName1(QString name);
    void setTurbineName2(QString name);
    void setTurbineName3(QString name);
    void setTurbineName4(QString name);
    void setTurbineName5(QString name);
    void setTurbineName6(QString name);
    void setTurbineName7(QString name);
    void setTurbineName8(QString name);
    void setTurbineName9(QString name);
    void setTurbineName10(QString name);
    void setTurbineName11(QString name);
    void setTurbineName12(QString name);
    void setTurbineName13(QString name);
    void setTurbineName14(QString name);
    void setTurbineName15(QString name);
private:
    QSerialPort *mSerialPort;

    TurbineWidget *mTurbine1;
    TurbineWidget *mTurbine2;
    TurbineWidget *mTurbine3;
    TurbineWidget *mTurbine4;
    TurbineWidget *mTurbine5;
    TurbineWidget *mTurbine6;
    TurbineWidget *mTurbine7;
    TurbineWidget *mTurbine8;
    TurbineWidget *mTurbine9;
    TurbineWidget *mTurbine10;
    TurbineWidget *mTurbine11;
    TurbineWidget *mTurbine12;
    TurbineWidget *mTurbine13;
    TurbineWidget *mTurbine14;
    TurbineWidget *mTurbine15;

    QGroupBox *groupBox1;
    QGroupBox *groupBox2;
    QGroupBox *groupBox3;
    QGroupBox *groupBox4;
    QGroupBox *groupBox5;
    QGroupBox *groupBox6;
    QGroupBox *groupBox7;
    QGroupBox *groupBox8;
    QGroupBox *groupBox9;
    QGroupBox *groupBox10;
    QGroupBox *groupBox11;
    QGroupBox *groupBox12;
    QGroupBox *groupBox13;
    QGroupBox *groupBox14;
    QGroupBox *groupBox15;
};

#endif // TURBINETABPAGE_HPP
