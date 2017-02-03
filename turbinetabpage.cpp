#include "turbinetabpage.hpp"
#include "qcgaugewidget.hpp"

#include <QGroupBox>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLCDNumber>

const int TURBINE_WIDTH = 220;
const int TURBINE_HEIGHT = 220;
const int LCD_WIDTH = 140;
const int LCD_HEIGHT = 40;

TurbineTabPage::TurbineTabPage()
    : mTurbineCounter1(new QcGaugeWidget)
    , mTurbineCounter2(new QcGaugeWidget)
    , mTurbineCounter3(new QcGaugeWidget)
    , mTurbineCounter4(new QcGaugeWidget)
    , mTurbineCounter5(new QcGaugeWidget)
    , mLcdScreen1(new QLCDNumber)
    , mLcdScreen2(new QLCDNumber)
    , mLcdScreen3(new QLCDNumber)
    , mLcdScreen4(new QLCDNumber)
    , mLcdScreen5(new QLCDNumber)
{

    initializeTurbine1();
    initializeTurbine2();
    initializeTurbine3();
    initializeTurbine4();
    initializeTurbine5();

    QGroupBox *groupBox1 = new QGroupBox("TURBINE 1");
    QGroupBox *groupBox2 = new QGroupBox("TURBINE 2");
    QGroupBox *groupBox3 = new QGroupBox("TURBINE 3");
    QGroupBox *groupBox4 = new QGroupBox("TURBINE 4");
    QGroupBox *groupBox5 = new QGroupBox("TURBINE 5");

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(groupBox1);
    hlayout->addWidget(groupBox2);
    hlayout->addWidget(groupBox3);
    hlayout->addWidget(groupBox4);
    hlayout->addWidget(groupBox5);

    mTurbineCounter1->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbineCounter2->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbineCounter3->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbineCounter4->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbineCounter5->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);

    mLcdScreen1->setSegmentStyle(QLCDNumber::Flat);
    mLcdScreen1->setFixedSize(LCD_WIDTH,LCD_HEIGHT);

    mLcdScreen2->setSegmentStyle(QLCDNumber::Flat);
    mLcdScreen2->setFixedSize(LCD_WIDTH,LCD_HEIGHT);

    mLcdScreen3->setSegmentStyle(QLCDNumber::Flat);
    mLcdScreen3->setFixedSize(LCD_WIDTH,LCD_HEIGHT);

    mLcdScreen4->setSegmentStyle(QLCDNumber::Flat);
    mLcdScreen4->setFixedSize(LCD_WIDTH,LCD_HEIGHT);

    mLcdScreen5->setSegmentStyle(QLCDNumber::Flat);
    mLcdScreen5->setFixedSize(LCD_WIDTH,LCD_HEIGHT);

    QVBoxLayout *vlayoutGroup1 = new QVBoxLayout;
    vlayoutGroup1->addWidget(mTurbineCounter1);
    vlayoutGroup1->addWidget(mLcdScreen1,0,Qt::AlignHCenter);

    QVBoxLayout *vlayoutGroup2 = new QVBoxLayout;
    vlayoutGroup2->addWidget(mTurbineCounter2);
    vlayoutGroup2->addWidget(mLcdScreen2,0,Qt::AlignHCenter);

    QVBoxLayout *vlayoutGroup3 = new QVBoxLayout;
    vlayoutGroup3->addWidget(mTurbineCounter3);
    vlayoutGroup3->addWidget(mLcdScreen3,0,Qt::AlignHCenter);

    QVBoxLayout *vlayoutGroup4 = new QVBoxLayout;
    vlayoutGroup4->addWidget(mTurbineCounter4);
    vlayoutGroup4->addWidget(mLcdScreen4,0,Qt::AlignHCenter);

    QVBoxLayout *vlayoutGroup5 = new QVBoxLayout;
    vlayoutGroup5->addWidget(mTurbineCounter5);
    vlayoutGroup5->addWidget(mLcdScreen5,0,Qt::AlignHCenter);

    groupBox1->setLayout(vlayoutGroup1);
    groupBox2->setLayout(vlayoutGroup2);
    groupBox3->setLayout(vlayoutGroup3);
    groupBox4->setLayout(vlayoutGroup4);
    groupBox5->setLayout(vlayoutGroup5);


    this->setLayout(hlayout);

}



void TurbineTabPage::initializeTurbine1()
{

    /* FIRST TURBINE */

    QcNeedleItem *rpmNeedle;

    mTurbineCounter1->addBackground(20);
    QcBackgroundItem *bkg1 = mTurbineCounter1->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,QColor(182,181,176));
    bkg1->addColor(1.0,QColor(182,181,176));

    QcBackgroundItem *bkg2 = mTurbineCounter1->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,QColor(50,78,92));
    bkg2->addColor(1.0,QColor(83,105,118));

    //the dots values , not the numbers
    mTurbineCounter1->addArc(55);
    mTurbineCounter1->addDegrees(65)->setValueRange(0,10);
    mTurbineCounter1->addColorBand(50);

    mTurbineCounter1->addValues(80)->setValueRange(0,10);

    mTurbineCounter1->addLabel(70)->setText("RPM");
    QcLabelItem *lab = mTurbineCounter1->addLabel(40);
    lab->setText("0");

    //Needle height
    rpmNeedle = mTurbineCounter1->addNeedle(60);
    rpmNeedle->setLabel(lab);
    rpmNeedle->setColor(QColor(249,89,75));
    rpmNeedle->setValueRange(0,10000);
    mTurbineCounter1->addBackground(7);
    //mTurbineCounter1->addGlass(88);

}

void TurbineTabPage::initializeTurbine2()
{
    /* SECOND TURBINE */

    QcNeedleItem *rpmNeedle2;

    mTurbineCounter2->addBackground(20);
    QcBackgroundItem *bkg1 = mTurbineCounter2->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,QColor(182,181,176));
    bkg1->addColor(1.0,QColor(182,181,176));

    QcBackgroundItem *bkg2 = mTurbineCounter2->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,QColor(50,78,92));
    bkg2->addColor(1.0,QColor(83,105,118));

    //the dots values , not the numbers
    mTurbineCounter2->addArc(55);
    mTurbineCounter2->addDegrees(65)->setValueRange(0,10);
    mTurbineCounter2->addColorBand(50);

    mTurbineCounter2->addValues(80)->setValueRange(0,10);

    mTurbineCounter2->addLabel(70)->setText("RPM");
    QcLabelItem *lab = mTurbineCounter2->addLabel(40);
    lab->setText("0");

    //Needle height
    rpmNeedle2 = mTurbineCounter2->addNeedle(60);
    rpmNeedle2->setLabel(lab);
    rpmNeedle2->setColor(QColor(249,89,75));
    rpmNeedle2->setValueRange(0,10000);
    mTurbineCounter2->addBackground(7);

}

void TurbineTabPage::initializeTurbine3()
{
    /* THRID TURBINE */

    QcNeedleItem *rpmNeedle3;

    mTurbineCounter3->addBackground(20);
    QcBackgroundItem *bkg1 = mTurbineCounter3->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,QColor(182,181,176));
    bkg1->addColor(1.0,QColor(182,181,176));

    QcBackgroundItem *bkg2 = mTurbineCounter3->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,QColor(50,78,92));
    bkg2->addColor(1.0,QColor(83,105,118));

    //the dots values , not the numbers
    mTurbineCounter3->addArc(55);
    mTurbineCounter3->addDegrees(65)->setValueRange(0,10);
    mTurbineCounter3->addColorBand(50);

    mTurbineCounter3->addValues(80)->setValueRange(0,10);

    mTurbineCounter3->addLabel(70)->setText("RPM");
    QcLabelItem *lab = mTurbineCounter3->addLabel(40);
    lab->setText("0");

    //Needle height
    rpmNeedle3 = mTurbineCounter3->addNeedle(60);
    rpmNeedle3->setLabel(lab);
    rpmNeedle3->setColor(QColor(249,89,75));
    rpmNeedle3->setValueRange(0,10000);
    mTurbineCounter3->addBackground(7);
}

void TurbineTabPage::initializeTurbine4()
{

    /* FOURTH TURBINE */

    QcNeedleItem *rpmNeedle4;

    mTurbineCounter4->addBackground(20);
    QcBackgroundItem *bkg1 = mTurbineCounter4->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,QColor(182,181,176));
    bkg1->addColor(1.0,QColor(182,181,176));

    QcBackgroundItem *bkg2 = mTurbineCounter4->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,QColor(50,78,92));
    bkg2->addColor(1.0,QColor(83,105,118));

    //the dots values , not the numbers
    mTurbineCounter4->addArc(55);
    mTurbineCounter4->addDegrees(65)->setValueRange(0,10);
    mTurbineCounter4->addColorBand(50);

    mTurbineCounter4->addValues(80)->setValueRange(0,10);

    mTurbineCounter4->addLabel(70)->setText("RPM");
    QcLabelItem *lab = mTurbineCounter4->addLabel(40);
    lab->setText("0");

    //Needle height
    rpmNeedle4 = mTurbineCounter4->addNeedle(60);
    rpmNeedle4->setLabel(lab);
    rpmNeedle4->setColor(QColor(249,89,75));
    rpmNeedle4->setValueRange(0,10000);
    mTurbineCounter4->addBackground(7);
}

void TurbineTabPage::initializeTurbine5()
{
    /* FIFTH TURBINE */

    QcNeedleItem *rpmNeedle5;

    mTurbineCounter5->addBackground(20);
    QcBackgroundItem *bkg1 = mTurbineCounter5->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,QColor(182,181,176));
    bkg1->addColor(1.0,QColor(182,181,176));

    QcBackgroundItem *bkg2 = mTurbineCounter5->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,QColor(50,78,92));
    bkg2->addColor(1.0,QColor(83,105,118));

    //the dots values , not the numbers
    mTurbineCounter5->addArc(55);
    mTurbineCounter5->addDegrees(65)->setValueRange(0,10);
    mTurbineCounter5->addColorBand(50);

    mTurbineCounter5->addValues(80)->setValueRange(0,10);

    mTurbineCounter5->addLabel(70)->setText("RPM");
    QcLabelItem *lab = mTurbineCounter5->addLabel(40);
    lab->setText("0");

    //Needle height
    rpmNeedle5 = mTurbineCounter5->addNeedle(60);
    rpmNeedle5->setLabel(lab);
    rpmNeedle5->setColor(QColor(249,89,75));
    rpmNeedle5->setValueRange(0,10000);
    mTurbineCounter5->addBackground(7);
}
