#include "charttabpage.hpp"
#include "qcustomplot/qcustomplot.h"
#include "preferences.hpp"

#include <QHBoxLayout>
#include <QSharedPointer>
#include <QGroupBox>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QColorDialog>
#include <QPushButton>
#include <QCheckBox>

const int CBUTTON_WIDTH = 40;

ChartTabPage::ChartTabPage()
    : mPlot(new QCustomPlot)
    , yAxisLowerRange(1000)
    , yAxisUpperRange(6000)
    , xAxisSpeed(8)
    , xAxisTicks(1)
    , mPlotEnabled1(true)
    , mPlotEnabled2(true)
    , mPlotEnabled3(false)
    , mPlotEnabled4(false)
    , mPlotEnabled5(false)
    , mPlotEnabled6(false)
    , mPlotEnabled7(false)
    , mPlotEnabled8(false)
    , mPlotEnabled9(false)
    , mPlotEnabled10(false)
    , mPlotEnabled11(false)
    , mPlotEnabled12(false)
    , mPlotEnabled13(false)
    , mPlotEnabled14(false)
    , mPlotEnabled15(false)
    , ccolor1(QColor(255,0,0))
    , ccolor2(QColor(0,0,255))
    , ccolor3(QColor(0,255,0))
    , ccolor4(QColor(225,128,0))
    , ccolor5(QColor(255,191,0))
    , ccolor6(QColor(128,255,0))
    , ccolor7(QColor(64,255,0))
    , ccolor8(QColor(0,255,191))
    , ccolor9(QColor(64,0,255))
    , ccolor10(QColor(191,0,255))
    , ccolor11(QColor(255,0,255))
    , ccolor12(QColor(255,0,128))
    , ccolor13(QColor(0,128,255))
    , ccolor14(QColor(255,0,64))
    , ccolor15(QColor(0,255,191))
{

    mPlot->addGraph();
    mPlot->graph(0)->setPen(QPen(ccolor1));
    mPlot->addGraph();
    mPlot->graph(1)->setPen(QPen(ccolor2));
    mPlot->addGraph();
    mPlot->graph(2)->setPen(QPen(ccolor3));
    mPlot->addGraph();
    mPlot->graph(3)->setPen(QPen(ccolor4));
    mPlot->addGraph();
    mPlot->graph(4)->setPen(QPen(ccolor5));
    mPlot->addGraph();
    mPlot->graph(5)->setPen(QPen(ccolor6));
    mPlot->addGraph();
    mPlot->graph(6)->setPen(QPen(ccolor7));
    mPlot->addGraph();
    mPlot->graph(7)->setPen(QPen(ccolor8));
    mPlot->addGraph();
    mPlot->graph(8)->setPen(QPen(ccolor9));
    mPlot->addGraph();
    mPlot->graph(9)->setPen(QPen(ccolor10));
    mPlot->addGraph();
    mPlot->graph(10)->setPen(QPen(ccolor11));
    mPlot->addGraph();
    mPlot->graph(11)->setPen(QPen(ccolor12));
    mPlot->addGraph();
    mPlot->graph(12)->setPen(QPen(ccolor13));
    mPlot->addGraph();
    mPlot->graph(13)->setPen(QPen(ccolor14));
    mPlot->addGraph();
    mPlot->graph(14)->setPen(QPen(ccolor15));

    mPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    mPlot->xAxis->setDateTimeFormat("hh:mm:ss");
    mPlot->xAxis->setAutoTickStep(false);
    mPlot->xAxis->setTickStep(xAxisTicks);
    mPlot->axisRect()->setupFullAxesBox();


    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realTimeDataSlot()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible


    QGroupBox *groupBox = new QGroupBox("Plot Settings");
    QVBoxLayout *layout = new QVBoxLayout;
    mPlot->setFixedHeight(400);
    layout->addWidget(mPlot);
    layout->addWidget(groupBox);

    QHBoxLayout *hlayout = new QHBoxLayout;
    groupBox->setLayout(hlayout);
    QVBoxLayout *vlayout1 = new QVBoxLayout;
    hlayout->addLayout(vlayout1);
    QHBoxLayout *hlayout2 = new QHBoxLayout;
    hlayout->addLayout(hlayout2);

    QHBoxLayout *hlayoutSpint = new QHBoxLayout;
    QLabel *label1 = new QLabel("<font color='black'>yAxis Range: </font>");
    hlayoutSpint->addWidget(label1);
    QSpinBox *qspinBox1 = new QSpinBox;
    qspinBox1->setRange(0,10000);
    qspinBox1->setValue(1000);
    hlayoutSpint->addWidget(qspinBox1, 1, Qt::AlignLeft);
    QLabel *label2 = new QLabel("<font color='black'>to </font>");
    hlayoutSpint->addWidget(label2,1, Qt::AlignLeft);
    QSpinBox *qspinBox2 = new QSpinBox;
    qspinBox2->setRange(0,10000);
    qspinBox2->setValue(6000);
    hlayoutSpint->addWidget(qspinBox2,16, Qt::AlignLeft);
    hlayoutSpint->setSpacing(0);
    hlayoutSpint->setMargin(0);
    hlayoutSpint->setContentsMargins(0,0,0,0);
    vlayout1->addLayout(hlayoutSpint);

    QHBoxLayout *hlayoutSpeed = new QHBoxLayout;
    hlayoutSpeed->setSpacing(0);
    hlayoutSpeed->setMargin(0);
    hlayoutSpeed->setContentsMargins(0,0,0,0);
    QLabel *label3 = new QLabel("<font color='black'> xAxis Speed: </font>");
    hlayoutSpeed->addWidget(label3);
    QSpinBox *spinBox3 = new QSpinBox;
    spinBox3->setRange(0, 30);
    spinBox3->setValue(8);
    hlayoutSpeed->addWidget(spinBox3,2,Qt::AlignLeft);
    vlayout1->addLayout(hlayoutSpeed);

    QHBoxLayout *hlayoutTick = new QHBoxLayout;
    hlayoutTick->setSpacing(0);
    hlayoutTick->setMargin(0);
    hlayoutTick->setContentsMargins(0,0,0,0);
    QLabel *label4 = new QLabel("<font color='black'> xAxis Tick step: </font>");
    hlayoutTick->addWidget(label4);
    QSpinBox *spinBox4 = new QSpinBox;
    spinBox4->setRange(1,10);
    spinBox4->setValue(1);
    hlayoutTick->addWidget(spinBox4, 2, Qt::AlignLeft);
    vlayout1->addLayout(hlayoutTick);

    //----------------------------------------//

    QVBoxLayout *vlayout2 = new QVBoxLayout;

    QHBoxLayout *cHlayout1 = new QHBoxLayout;
    QLabel *clabel1 = new QLabel("<font color='black'> Turbine 1: </font>");
    cHlayout1->addWidget(clabel1);
    cbutton1 = new QPushButton("...");
    cbutton1->setStyleSheet(getColorString(ccolor1));
    cbutton1->setFixedWidth(CBUTTON_WIDTH);
    cHlayout1->addWidget(cbutton1);
    QLabel *slabel1 = new QLabel("<font color='black'> show: </font>");
    cHlayout1->addWidget(slabel1);
    QCheckBox *scheck1 = new QCheckBox;
    scheck1->setChecked(true);
    connect(scheck1, SIGNAL(clicked(bool)), this, SLOT(mPlotSet1(bool)));
    cHlayout1->addWidget(scheck1);
    connect(cbutton1, SIGNAL(clicked(bool)), this, SLOT(cColorSet1(bool)));
    vlayout2->addLayout(cHlayout1);

    QHBoxLayout *cHlayout2 = new QHBoxLayout;
    QLabel *clabel2 = new QLabel("<font color='black'> Turbine 2: </font>");
    cHlayout2->addWidget(clabel2);
    cbutton2 = new QPushButton("...");
    cbutton2->setStyleSheet(getColorString(ccolor2));
    cbutton2->setFixedWidth(CBUTTON_WIDTH);
    cHlayout2->addWidget(cbutton2);
    QLabel *slabel2 = new QLabel("<font color='black'> show: </font>");
    cHlayout2->addWidget(slabel2);
    QCheckBox *scheck2 = new QCheckBox;
    scheck2->setChecked(true);
    connect(scheck2, SIGNAL(clicked(bool)), this, SLOT(mPlotSet2(bool)));
    cHlayout2->addWidget(scheck2);
    connect(cbutton2, SIGNAL(clicked(bool)), this, SLOT(cColorSet2(bool)));
    vlayout2->addLayout(cHlayout2);


    QHBoxLayout *cHlayout3 = new QHBoxLayout;
    QLabel *clabel3 = new QLabel("<font color='black'> Turbine 3: </font>");
    cHlayout3->addWidget(clabel3);
    cbutton3 = new QPushButton("...");
    cbutton3->setStyleSheet(getColorString(ccolor3));
    cbutton3->setFixedWidth(CBUTTON_WIDTH);
    cHlayout3->addWidget(cbutton3);
    QLabel *slabel3 = new QLabel("<font color='black'> show: </font>");
    cHlayout3->addWidget(slabel3);
    QCheckBox *scheck3 = new QCheckBox;
    cHlayout3->addWidget(scheck3);
    connect(scheck3, SIGNAL(clicked(bool)), this, SLOT(mPlotSet3(bool)));
    connect(cbutton3, SIGNAL(clicked(bool)), this, SLOT(cColorSet3(bool)));
    vlayout2->addLayout(cHlayout3);


    QHBoxLayout *cHlayout4 = new QHBoxLayout;
    QLabel *clabel4 = new QLabel("<font color='black'> Turbine 4: </font>");
    cHlayout4->addWidget(clabel4);
    cbutton4 = new QPushButton("...");
    cbutton4->setStyleSheet(getColorString(ccolor4));
    cbutton4->setFixedWidth(CBUTTON_WIDTH);
    cHlayout4->addWidget(cbutton4);
    QLabel *slabel4 = new QLabel("<font color='black'> show: </font>");
    cHlayout4->addWidget(slabel4);
    QCheckBox *scheck4 = new QCheckBox;
    cHlayout4->addWidget(scheck4);
    connect(scheck4, SIGNAL(clicked(bool)), this, SLOT(mPlotSet4(bool)));
    connect(cbutton4, SIGNAL(clicked(bool)), this, SLOT(cColorSet4(bool)));
    vlayout2->addLayout(cHlayout4);


    QHBoxLayout *cHlayout5 = new QHBoxLayout;
    QLabel *clabel5 = new QLabel("<font color='black'> Turbine 5: </font>");
    cHlayout5->addWidget(clabel5);
    cbutton5 = new QPushButton("...");
    cbutton5->setStyleSheet(getColorString(ccolor5));
    cbutton5->setFixedWidth(CBUTTON_WIDTH);
    cHlayout5->addWidget(cbutton5);
    QLabel *slabel5 = new QLabel("<font color='black'> show: </font>");
    cHlayout5->addWidget(slabel5);
    QCheckBox *scheck5 = new QCheckBox;
    cHlayout5->addWidget(scheck5);
    connect(scheck5, SIGNAL(clicked(bool)), this, SLOT(mPlotSet5(bool)));
    connect(cbutton5, SIGNAL(clicked(bool)), this, SLOT(cColorSet5(bool)));
    vlayout2->addLayout(cHlayout5);

    //----------------------------------------//

    QVBoxLayout *vlayout3 = new QVBoxLayout;

    QHBoxLayout *cHlayout6 = new QHBoxLayout;
    QLabel *clabel6 = new QLabel("<font color='black'> Turbine 6: </font>");
    cHlayout6->addWidget(clabel6);
    cbutton6 = new QPushButton("...");
    cbutton6->setStyleSheet(getColorString(ccolor6));
    cbutton6->setFixedWidth(CBUTTON_WIDTH);
    cHlayout6->addWidget(cbutton6);
    QLabel *slabel6 = new QLabel("<font color='black'> show: </font>");
    cHlayout6->addWidget(slabel6);
    QCheckBox *scheck6 = new QCheckBox;
    cHlayout6->addWidget(scheck6);
    connect(scheck6, SIGNAL(clicked(bool)), this, SLOT(mPlotSet6(bool)));
    connect(cbutton6, SIGNAL(clicked(bool)), this, SLOT(cColorSet6(bool)));
    vlayout3->addLayout(cHlayout6);

    QHBoxLayout *cHlayout7 = new QHBoxLayout;
    QLabel *clabel7 = new QLabel("<font color='black'> Turbine 7: </font>");
    cHlayout7->addWidget(clabel7);
    cbutton7 = new QPushButton("...");
    cbutton7->setStyleSheet(getColorString(ccolor7));
    cbutton7->setFixedWidth(CBUTTON_WIDTH);
    cHlayout7->addWidget(cbutton7);
    QLabel *slabel7 = new QLabel("<font color='black'> show: </font>");
    cHlayout7->addWidget(slabel7);
    QCheckBox *scheck7 = new QCheckBox;
    cHlayout7->addWidget(scheck7);
    connect(scheck7, SIGNAL(clicked(bool)), this, SLOT(mPlotSet7(bool)));
    connect(cbutton7, SIGNAL(clicked(bool)), this, SLOT(cColorSet7(bool)));
    vlayout3->addLayout(cHlayout7);


    QHBoxLayout *cHlayout8 = new QHBoxLayout;
    QLabel *clabel8 = new QLabel("<font color='black'> Turbine 8: </font>");
    cHlayout8->addWidget(clabel8);
    cbutton8 = new QPushButton("...");
    cbutton8->setStyleSheet(getColorString(ccolor8));
    cbutton8->setFixedWidth(CBUTTON_WIDTH);
    cHlayout8->addWidget(cbutton8);
    QLabel *slabel8 = new QLabel("<font color='black'> show: </font>");
    cHlayout8->addWidget(slabel8);
    QCheckBox *scheck8 = new QCheckBox;
    cHlayout8->addWidget(scheck8);
    connect(scheck8, SIGNAL(clicked(bool)), this, SLOT(mPlotSet8(bool)));
    connect(cbutton8, SIGNAL(clicked(bool)), this, SLOT(cColorSet8(bool)));
    vlayout3->addLayout(cHlayout8);


    QHBoxLayout *cHlayout9 = new QHBoxLayout;
    QLabel *clabel9 = new QLabel("<font color='black'> Turbine 9: </font>");
    cHlayout9->addWidget(clabel9);
    cbutton9 = new QPushButton("...");
    cbutton9->setStyleSheet(getColorString(ccolor9));
    cbutton9->setFixedWidth(CBUTTON_WIDTH);
    cHlayout9->addWidget(cbutton9);
    QLabel *slabel9 = new QLabel("<font color='black'> show: </font>");
    cHlayout9->addWidget(slabel9);
    QCheckBox *scheck9 = new QCheckBox;
    cHlayout9->addWidget(scheck9);
    connect(scheck9, SIGNAL(clicked(bool)), this, SLOT(mPlotSet9(bool)));
    connect(cbutton9, SIGNAL(clicked(bool)), this, SLOT(cColorSet9(bool)));
    vlayout3->addLayout(cHlayout9);


    QHBoxLayout *cHlayout10 = new QHBoxLayout;
    QLabel *clabel10 = new QLabel("<font color='black'> Turbine 10: </font>");
    cHlayout10->addWidget(clabel10);
    cbutton10 = new QPushButton("...");
    cbutton10->setStyleSheet(getColorString(ccolor10));
    cbutton10->setFixedWidth(CBUTTON_WIDTH);
    cHlayout10->addWidget(cbutton10);
    QLabel *slabel10 = new QLabel("<font color='black'> show: </font>");
    cHlayout10->addWidget(slabel10);
    QCheckBox *scheck10 = new QCheckBox;
    cHlayout10->addWidget(scheck10);
    connect(scheck10, SIGNAL(clicked(bool)), this, SLOT(mPlotSet10(bool)));
    connect(cbutton10, SIGNAL(clicked(bool)), this, SLOT(cColorSet10(bool)));
    vlayout3->addLayout(cHlayout10);

    //----------------------------------------//

    QVBoxLayout *vlayout4 = new QVBoxLayout;

    QHBoxLayout *cHlayout11 = new QHBoxLayout;
    QLabel *clabel11 = new QLabel("<font color='black'> Turbine 11: </font>");
    cHlayout11->addWidget(clabel11);
    cbutton11 = new QPushButton("...");
    cbutton11->setStyleSheet(getColorString(ccolor11));
    cbutton11->setFixedWidth(CBUTTON_WIDTH);
    cHlayout11->addWidget(cbutton11);
    QLabel *slabel11 = new QLabel("<font color='black'> show: </font>");
    cHlayout11->addWidget(slabel11);
    QCheckBox *scheck11 = new QCheckBox;
    cHlayout11->addWidget(scheck11);
    connect(scheck11, SIGNAL(clicked(bool)), this, SLOT(mPlotSet11(bool)));
    connect(cbutton11, SIGNAL(clicked(bool)), this, SLOT(cColorSet11(bool)));
    vlayout4->addLayout(cHlayout11);

    QHBoxLayout *cHlayout12 = new QHBoxLayout;
    QLabel *clabel12 = new QLabel("<font color='black'> Turbine 12: </font>");
    cHlayout12->addWidget(clabel12);
    cbutton12 = new QPushButton("...");
    cbutton12->setStyleSheet(getColorString(ccolor12));
    cbutton12->setFixedWidth(CBUTTON_WIDTH);
    cHlayout12->addWidget(cbutton12);
    QLabel *slabel12 = new QLabel("<font color='black'> show: </font>");
    cHlayout12->addWidget(slabel12);
    QCheckBox *scheck12 = new QCheckBox;
    cHlayout12->addWidget(scheck12);
    connect(scheck12, SIGNAL(clicked(bool)), this, SLOT(mPlotSet12(bool)));
    connect(cbutton12, SIGNAL(clicked(bool)), this, SLOT(cColorSet12(bool)));
    vlayout4->addLayout(cHlayout12);


    QHBoxLayout *cHlayout13 = new QHBoxLayout;
    QLabel *clabel13 = new QLabel("<font color='black'> Turbine 13: </font>");
    cHlayout13->addWidget(clabel13);
    cbutton13 = new QPushButton("...");
    cbutton13->setStyleSheet(getColorString(ccolor13));
    cbutton13->setFixedWidth(CBUTTON_WIDTH);
    cHlayout13->addWidget(cbutton13);
    QLabel *slabel13 = new QLabel("<font color='black'> show: </font>");
    cHlayout13->addWidget(slabel13);
    QCheckBox *scheck13 = new QCheckBox;
    cHlayout13->addWidget(scheck13);
    connect(scheck13, SIGNAL(clicked(bool)), this, SLOT(mPlotSet13(bool)));
    connect(cbutton13, SIGNAL(clicked(bool)), this, SLOT(cColorSet13(bool)));
    vlayout4->addLayout(cHlayout13);


    QHBoxLayout *cHlayout14 = new QHBoxLayout;
    QLabel *clabel14 = new QLabel("<font color='black'> Turbine 14: </font>");
    cHlayout14->addWidget(clabel14);
    cbutton14 = new QPushButton("...");
    cbutton14->setStyleSheet(getColorString(ccolor14));
    cbutton14->setFixedWidth(CBUTTON_WIDTH);
    cHlayout14->addWidget(cbutton14);
    QLabel *slabel14 = new QLabel("<font color='black'> show: </font>");
    cHlayout14->addWidget(slabel14);
    QCheckBox *scheck14 = new QCheckBox;
    cHlayout14->addWidget(scheck14);
    connect(scheck14, SIGNAL(clicked(bool)), this, SLOT(mPlotSet14(bool)));
    connect(cbutton14, SIGNAL(clicked(bool)), this, SLOT(cColorSet14(bool)));
    vlayout4->addLayout(cHlayout14);


    QHBoxLayout *cHlayout15 = new QHBoxLayout;
    QLabel *clabel15 = new QLabel("<font color='black'> Turbine 15: </font>");
    cHlayout15->addWidget(clabel15);
    cbutton15 = new QPushButton("...");
    cbutton15->setStyleSheet(getColorString(ccolor15));
    cbutton15->setFixedWidth(CBUTTON_WIDTH);
    cHlayout15->addWidget(cbutton15);
    QLabel *slabel15 = new QLabel("<font color='black'> show: </font>");
    cHlayout15->addWidget(slabel15);
    QCheckBox *scheck15 = new QCheckBox;
    cHlayout15->addWidget(scheck15);
    connect(scheck15, SIGNAL(clicked(bool)), this, SLOT(mPlotSet15(bool)));
    connect(cbutton15, SIGNAL(clicked(bool)), this, SLOT(cColorSet15(bool)));
    vlayout4->addLayout(cHlayout15);

    hlayout2->addLayout(vlayout2);
    hlayout2->addLayout(vlayout3);
    hlayout2->addLayout(vlayout4);


    connect(qspinBox1, SIGNAL(valueChanged(int)), this, SLOT(yAxisRangeMinSet(int)));
    connect(qspinBox2, SIGNAL(valueChanged(int)), this, SLOT(yAxisRangeMaxSet(int)));
    connect(spinBox3, SIGNAL(valueChanged(int)), this, SLOT(xAxisSpeedSet(int)));
    connect(spinBox4, SIGNAL(valueChanged(int)), this, SLOT(xAxisTickSet(int)));

    /* If user select new color , then change the color of the selected axis */

    connect(this, SIGNAL(cColor1Changed(QColor)), this, SLOT(changePlotColor1(QColor)));
    connect(this, SIGNAL(cColor2Changed(QColor)), this, SLOT(changePlotColor2(QColor)));
    connect(this, SIGNAL(cColor3Changed(QColor)), this, SLOT(changePlotColor3(QColor)));
    connect(this, SIGNAL(cColor4Changed(QColor)), this, SLOT(changePlotColor4(QColor)));
    connect(this, SIGNAL(cColor5Changed(QColor)), this, SLOT(changePlotColor5(QColor)));
    connect(this, SIGNAL(cColor6Changed(QColor)), this, SLOT(changePlotColor6(QColor)));
    connect(this, SIGNAL(cColor7Changed(QColor)), this, SLOT(changePlotColor7(QColor)));
    connect(this, SIGNAL(cColor8Changed(QColor)), this, SLOT(changePlotColor8(QColor)));
    connect(this, SIGNAL(cColor9Changed(QColor)), this, SLOT(changePlotColor9(QColor)));
    connect(this, SIGNAL(cColor10Changed(QColor)), this, SLOT(changePlotColor10(QColor)));
    connect(this, SIGNAL(cColor11Changed(QColor)), this, SLOT(changePlotColor11(QColor)));
    connect(this, SIGNAL(cColor12Changed(QColor)), this, SLOT(changePlotColor12(QColor)));
    connect(this, SIGNAL(cColor13Changed(QColor)), this, SLOT(changePlotColor13(QColor)));
    connect(this, SIGNAL(cColor14Changed(QColor)), this, SLOT(changePlotColor14(QColor)));
    connect(this, SIGNAL(cColor15Changed(QColor)), this, SLOT(changePlotColor15(QColor)));

    this->setLayout(layout);
}

void ChartTabPage::realTimeDataSlot()
{
    Preferences *prefs = Preferences::instance();

    // calculate two new data points:
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    double key = 0;
#else
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
#endif
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.01) // at most add point every 10 ms
    {


        if (mPlotEnabled1) {
            mPlot->graph(0)->addData(key, prefs->cacheLookup("plot1").toInt() );
        }

        if (mPlotEnabled2) {
            mPlot->graph(1)->addData(key, prefs->cacheLookup("plot2").toInt() );
        }

        if (mPlotEnabled3) {
            mPlot->graph(2)->addData(key, prefs->cacheLookup("plot3").toInt() );
        }

        if (mPlotEnabled4) {
            mPlot->graph(3)->addData(key, prefs->cacheLookup("plot4").toInt() );
        }

        if (mPlotEnabled5) {
            mPlot->graph(4)->addData(key, prefs->cacheLookup("plot5").toInt() );
        }

        if (mPlotEnabled6) {
            mPlot->graph(5)->addData(key, prefs->cacheLookup("plot6").toInt() );
        }

        if (mPlotEnabled7) {
            mPlot->graph(6)->addData(key, prefs->cacheLookup("plot7").toInt() );
        }

        if (mPlotEnabled8) {
            mPlot->graph(7)->addData(key, prefs->cacheLookup("plot8").toInt() );
        }

        if (mPlotEnabled9) {
            mPlot->graph(8)->addData(key, prefs->cacheLookup("plot9").toInt() );
        }

        if (mPlotEnabled10) {
            mPlot->graph(9)->addData(key, prefs->cacheLookup("plot10").toInt() );
        }

        if (mPlotEnabled11) {
            mPlot->graph(10)->addData(key, prefs->cacheLookup("plot11").toInt() );
        }

        if (mPlotEnabled12) {
            mPlot->graph(11)->addData(key, prefs->cacheLookup("plot12").toInt() );
        }

        if (mPlotEnabled13) {
            mPlot->graph(12)->addData(key, prefs->cacheLookup("plot13").toInt() );
        }

        if (mPlotEnabled14) {
            mPlot->graph(13)->addData(key, prefs->cacheLookup("plot14").toInt() );
        }

        if (mPlotEnabled15) {
            mPlot->graph(14)->addData(key, prefs->cacheLookup("plot15").toInt() );
        }

        // remove data of lines that's outside visible range:
        mPlot->graph(0)->removeDataBefore(key-xAxisSpeed);
        //mPlot->graph(1)->removeDataBefore(key-8);
        // rescale value (vertical) axis to fit the current data:
        mPlot->graph(0)->rescaleValueAxis();
        //mPlot->graph(1)->rescaleValueAxis(true);
        lastPointKey = key;

        mPlot->graph(1)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(1)->rescaleValueAxis();
        mPlot->graph(2)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(2)->rescaleValueAxis();
        mPlot->graph(3)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(3)->rescaleValueAxis();
        mPlot->graph(4)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(4)->rescaleValueAxis();
        mPlot->graph(5)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(5)->rescaleValueAxis();
        mPlot->graph(6)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(6)->rescaleValueAxis();
        mPlot->graph(7)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(7)->rescaleValueAxis();
        mPlot->graph(8)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(8)->rescaleValueAxis();
        mPlot->graph(9)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(9)->rescaleValueAxis();
        mPlot->graph(10)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(10)->rescaleValueAxis();
        mPlot->graph(11)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(11)->rescaleValueAxis();
        mPlot->graph(12)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(12)->rescaleValueAxis();
        mPlot->graph(13)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(13)->rescaleValueAxis();
        mPlot->graph(14)->removeDataBefore(key-xAxisSpeed);
        mPlot->graph(14)->rescaleValueAxis();
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    mPlot->xAxis->setRange(key+0.25, xAxisSpeed, Qt::AlignRight);
    mPlot->yAxis->setRange(yAxisLowerRange, yAxisUpperRange);
    mPlot->replot();

    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {
//        ui->statusBar->showMessage(
//                    QString("%1 FPS, Total Data points: %2")
//                    .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
//                    .arg(ui->customPlot->graph(0)->data()->count()+ui->customPlot->graph(1)->data()->count())
//                    , 0);
        lastFpsKey = key;
        frameCount = 0;
    }
}

void ChartTabPage::yAxisRangeMinSet(int min)
{
    mPlot->yAxis->setRangeLower(min);
    yAxisLowerRange = min;
    mPlot->replot();
}

void ChartTabPage::yAxisRangeMaxSet(int max)
{
    mPlot->yAxis->setRangeUpper(max);
    yAxisUpperRange = max;
    mPlot->replot();
}

void ChartTabPage::xAxisSpeedSet(int speed)
{
    xAxisSpeed = speed;

}

void ChartTabPage::xAxisTickSet(int ticks)
{
    xAxisTicks = ticks;
    mPlot->xAxis->setTickStep(xAxisTicks);
    mPlot->replot();
}

void ChartTabPage::cColorSet1(bool)
{
    ccolor1 = QColorDialog::getColor(Qt::white, this);
    emit cColor1Changed(ccolor1);
}

void ChartTabPage::cColorSet2(bool)
{
    ccolor2 = QColorDialog::getColor(Qt::white, this);
    emit cColor2Changed(ccolor2);
}

void ChartTabPage::cColorSet3(bool)
{
    ccolor3 = QColorDialog::getColor(Qt::white, this);
    emit cColor3Changed(ccolor3);
}

void ChartTabPage::cColorSet4(bool)
{
    ccolor4 = QColorDialog::getColor(Qt::white, this);
    emit cColor4Changed(ccolor4);
}

void ChartTabPage::cColorSet5(bool)
{
    ccolor5 = QColorDialog::getColor(Qt::white, this);
    emit cColor5Changed(ccolor5);
}

void ChartTabPage::cColorSet6(bool)
{
    ccolor6 = QColorDialog::getColor(Qt::white, this);
    emit cColor6Changed(ccolor6);
}

void ChartTabPage::cColorSet7(bool)
{
    ccolor7 = QColorDialog::getColor(Qt::white, this);
    emit cColor7Changed(ccolor7);
}

void ChartTabPage::cColorSet8(bool)
{
    ccolor8 = QColorDialog::getColor(Qt::white, this);
    emit cColor8Changed(ccolor8);
}

void ChartTabPage::cColorSet9(bool)
{
    ccolor9 = QColorDialog::getColor(Qt::white, this);
    emit cColor9Changed(ccolor9);
}

void ChartTabPage::cColorSet10(bool)
{
    ccolor10 = QColorDialog::getColor(Qt::white, this);
    emit cColor10Changed(ccolor10);
}

void ChartTabPage::cColorSet11(bool)
{
    ccolor11 = QColorDialog::getColor(Qt::white, this);
    emit cColor11Changed(ccolor11);
}

void ChartTabPage::cColorSet12(bool)
{
    ccolor12 = QColorDialog::getColor(Qt::white, this);
    emit cColor12Changed(ccolor12);
}

void ChartTabPage::cColorSet13(bool)
{
    ccolor13 = QColorDialog::getColor(Qt::white, this);
    emit cColor13Changed(ccolor13);
}

void ChartTabPage::cColorSet14(bool)
{
    ccolor14 = QColorDialog::getColor(Qt::white, this);
    emit cColor14Changed(ccolor14);
}

void ChartTabPage::cColorSet15(bool)
{
    ccolor15 = QColorDialog::getColor(Qt::white, this);
    emit cColor15Changed(ccolor15);
}

void ChartTabPage::changePlotColor1(const QColor& color)
{
    mPlot->graph(0)->setPen(QPen(color));
    this->cbutton1->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor2(const QColor& color)
{
    mPlot->graph(1)->setPen(QPen(color));
   this->cbutton2->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor3(const QColor& color)
{
    mPlot->graph(2)->setPen(QPen(color));
    this->cbutton3->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor4(const QColor& color)
{
    mPlot->graph(3)->setPen(QPen(color));
    this->cbutton4->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor5(const QColor& color)
{
    mPlot->graph(4)->setPen(QPen(color));
    this->cbutton5->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor6(const QColor& color)
{
    mPlot->graph(5)->setPen(QPen(color));
    this->cbutton6->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor7(const QColor& color)
{
    mPlot->graph(6)->setPen(QPen(color));
    this->cbutton7->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor8(const QColor& color)
{
    mPlot->graph(7)->setPen(QPen(color));
    this->cbutton8->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor9(const QColor& color)
{
    mPlot->graph(8)->setPen(QPen(color));
    this->cbutton9->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor10(const QColor& color)
{
    mPlot->graph(9)->setPen(QPen(color));
    this->cbutton10->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor11(const QColor& color)
{
    mPlot->graph(10)->setPen(QPen(color));
    this->cbutton11->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor12(const QColor& color)
{
    mPlot->graph(11)->setPen(QPen(color));
    this->cbutton12->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor13(const QColor& color)
{
    mPlot->graph(12)->setPen(QPen(color));
    this->cbutton13->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor14(const QColor& color)
{
    mPlot->graph(13)->setPen(QPen(color));
    this->cbutton14->setStyleSheet(getColorString(color));
}

void ChartTabPage::changePlotColor15(const QColor& color)
{
    mPlot->graph(14)->setPen(QPen(color));
    this->cbutton15->setStyleSheet(getColorString(color));
}

QString ChartTabPage::getColorString(const QColor &color)
{
    if(color.isValid()) {
        return QString("background-color: %1").arg(color.name());
    } else {
        return QString("background-color: black");
    }
}




