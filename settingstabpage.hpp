#ifndef SETTINGSTABPAGE_HPP
#define SETTINGSTABPAGE_HPP

#include <QWidget>

class QGroupBox;

class SettingsTabPage : public QWidget
{
    Q_OBJECT
public:
    SettingsTabPage();
public slots:
    void setTurbineName1(QString name);
    void setTurbineName2(QString name);
    void setTurbineName3(QString name);
    void setTurbineName4(QString name);
    void setTurbineName5(QString name);

private:
    QGroupBox *groupBox1;
    QGroupBox *groupBox2;
    QGroupBox *groupBox3;
    QGroupBox *groupBox4;
    QGroupBox *groupBox5;
};

#endif // SETTINGSTABPAGE_HPP
