#include "charttabpage.hpp"
#include "qcustomplot/qcustomplot.h"
#include "preferences.hpp"

#include <QHBoxLayout>
#include <QSharedPointer>
#include <QGroupBox>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>

ChartTabPage::ChartTabPage()
    : mPlot(new QCustomPlot)
    , yAxisLowerRange(1000)
    , yAxisUpperRange(6000)
    , xAxisSpeed(8)
    , xAxisTicks(1)
{

    mPlot->addGraph(); // blue line
    mPlot->graph(0)->setPen(QPen(Qt::blue));
    mPlot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));
    mPlot->graph(0)->setAntialiasedFill(false);
    mPlot->addGraph(); // red line
    mPlot->graph(1)->setPen(QPen(Qt::red));
    mPlot->graph(0)->setChannelFillGraph(mPlot->graph(1));


    mPlot->addGraph(); // blue dot
    mPlot->graph(2)->setPen(QPen(Qt::blue));
    mPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
    mPlot->graph(2)->setScatterStyle(QCPScatterStyle::ssDisc);
    mPlot->addGraph(); // red dot
    mPlot->graph(3)->setPen(QPen(Qt::red));
    mPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
    mPlot->graph(3)->setScatterStyle(QCPScatterStyle::ssDisc);

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

    QHBoxLayout *hlayoutSpint = new QHBoxLayout;
    QLabel *label1 = new QLabel("<font color='black'>yAxis Range: </font>");
    hlayoutSpint->addWidget(label1);
    QSpinBox *qspinBox1 = new QSpinBox;
    qspinBox1->setRange(0,10000);
    qspinBox1->setValue(1000);
    hlayoutSpint->addWidget(qspinBox1);
    QLabel *label2 = new QLabel("<font color='black'>to </font>");
    hlayoutSpint->addWidget(label2);
    QSpinBox *qspinBox2 = new QSpinBox;
    qspinBox2->setRange(0,10000);
    qspinBox2->setValue(6000);
    hlayoutSpint->addWidget(qspinBox2);
    vlayout1->addLayout(hlayoutSpint);

    QHBoxLayout *hlayoutSpeed = new QHBoxLayout;
    QLabel *label3 = new QLabel("<font color='black'> xAxis Speed: </font>");
    hlayoutSpeed->addWidget(label3);
    QSpinBox *spinBox3 = new QSpinBox;
    spinBox3->setRange(0, 30);
    spinBox3->setValue(8);
    hlayoutSpeed->addWidget(spinBox3);
    vlayout1->addLayout(hlayoutSpeed);

    QHBoxLayout *hlayoutTick = new QHBoxLayout;
    QLabel *label4 = new QLabel("<font color='black'> xAxis Tick step: </font>");
    hlayoutTick->addWidget(label4);
    QSpinBox *spinBox4 = new QSpinBox;
    spinBox4->setRange(1,10);
    spinBox4->setValue(1);
    hlayoutTick->addWidget(spinBox4);
    vlayout1->addLayout(hlayoutTick);


    connect(qspinBox1, SIGNAL(valueChanged(int)), this, SLOT(yAxisRangeMinSet(int)));
    connect(qspinBox2, SIGNAL(valueChanged(int)), this, SLOT(yAxisRangeMaxSet(int)));
    connect(spinBox3, SIGNAL(valueChanged(int)), this, SLOT(xAxisSpeedSet(int)));
    connect(spinBox4, SIGNAL(valueChanged(int)), this, SLOT(xAxisTickSet(int)));
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

        // add data to lines:
        mPlot->graph(0)->addData(key, prefs->cacheLookup("plot1").toInt() );
        mPlot->graph(1)->addData(key, prefs->cacheLookup("plot2").toInt() );
        // set data of dots:
        mPlot->graph(2)->clearData();
        mPlot->graph(2)->addData(key, prefs->cacheLookup("plot1").toInt() );
        mPlot->graph(3)->clearData();
        mPlot->graph(3)->addData(key, prefs->cacheLookup("plot2").toInt() );
        // remove data of lines that's outside visible range:
        mPlot->graph(0)->removeDataBefore(key-8);
        //mPlot->graph(1)->removeDataBefore(key-8);
        // rescale value (vertical) axis to fit the current data:
        mPlot->graph(0)->rescaleValueAxis();
        //mPlot->graph(1)->rescaleValueAxis(true);
        lastPointKey = key;
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


