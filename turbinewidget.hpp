#ifndef TURBINEWIDGET_HPP
#define TURBINEWIDGET_HPP

#include "qcgaugewidget.hpp"

class TurbineWidget : public QcGaugeWidget
{
public:
    TurbineWidget(QWidget *parent = 0);
    ~TurbineWidget();
    void setValue(int value);
    QcNeedleItem* getNeedle() const { return mNeedle; }

private:
    QcNeedleItem *mNeedle;
};

#endif // TURBINEWIDGET_HPP
