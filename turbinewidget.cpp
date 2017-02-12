#include "turbinewidget.hpp"

TurbineWidget::TurbineWidget(QWidget *parent)
    : QcGaugeWidget(parent)
{
    addBackground(20);
    QcBackgroundItem *bkg1 = addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,QColor(182,181,176));
    bkg1->addColor(1.0,QColor(182,181,176));

    QcBackgroundItem *bkg2 = addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,QColor(50,78,92));
    bkg2->addColor(1.0,QColor(83,105,118));

    //the dots values , not the numbers
    addArc(55);
    addDegrees(65)->setValueRange(0,10);
    addColorBand(50);

    addValues(80)->setValueRange(0,10);

    addLabel(70)->setText("RPM");
    QcLabelItem *lab = addLabel(40);
    lab->setText("0");

    //Needle height
    mNeedle = addNeedle(60);
    mNeedle->setLabel(lab);
    mNeedle->setColor(QColor(249,89,75));
    mNeedle->setValueRange(0,10000);
    addBackground(7);
}

TurbineWidget::~TurbineWidget()
{
    //Empty
}

void TurbineWidget::setValue(int value)
{
    mNeedle->setCurrentValue(value);
}
