#include "turbinetabpage.hpp"
#include "qcgaugewidget.hpp"
#include "preferences.hpp"
#include "turbinewidget.hpp"

#include <QGroupBox>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QSerialPort>
#include <QThread>

#include <string>

const int TURBINE_WIDTH = 180;
const int TURBINE_HEIGHT = 180;

TurbineTabPage::TurbineTabPage()
    : mSerialPort(new QSerialPort(this))
    , mTurbine1( new TurbineWidget )
    , mTurbine2( new TurbineWidget )
    , mTurbine3( new TurbineWidget )
    , mTurbine4( new TurbineWidget )
    , mTurbine5( new TurbineWidget )
    , mTurbine6( new TurbineWidget )
    , mTurbine7( new TurbineWidget )
    , mTurbine8( new TurbineWidget )
    , mTurbine9( new TurbineWidget )
    , mTurbine10( new TurbineWidget )
    , mTurbine11( new TurbineWidget )
    , mTurbine12( new TurbineWidget )
    , mTurbine13( new TurbineWidget )
    , mTurbine14( new TurbineWidget )
    , mTurbine15( new TurbineWidget )
{

    /* Initialize Serial Port */

    Preferences *prefs = Preferences::instance();
    mSerialPort->setPortName(prefs->cacheLookup("port"));
    mSerialPort->open(QIODevice::ReadWrite);
    mSerialPort->setBaudRate(QSerialPort::Baud9600); //must be the same as your arduino-baudrate
    mSerialPort->setDataBits(QSerialPort::Data8);
    mSerialPort->setParity(QSerialPort::NoParity);
    mSerialPort->setStopBits(QSerialPort::OneStop);
    mSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    mDate = QDate::currentDate();
    mTime = QTime::currentTime().toString("_hh_mm_ss");

    QString date = mDate.toString("dd_MM_yyyy") + mTime + ".log";
    QByteArray bytearray = date.toLatin1();
    const char *file_name = bytearray.data();
    mOutput.open(file_name);

    mOutput << "[TIME] " << "[T1] " << "[T2] " << "[T3] " << "[T4] " << "[T5] " << "[T6] "
            << "[T7] " << "[T8] " << "[T9] " << "[T10] " << "[T11] " << "[T12] " << "[T13] "
            << "[T14] " << "[T15]" << std::endl;

    groupBox1 = new QGroupBox("TURBINE 0");
    groupBox2 = new QGroupBox("TURBINE 1");
    groupBox3 = new QGroupBox("TURBINE 2");
    groupBox4 = new QGroupBox("TURBINE 3");
    groupBox5 = new QGroupBox("TURBINE 4");
    groupBox6 = new QGroupBox("TURBINE 5");
    groupBox7 = new QGroupBox("TURBINE 6");
    groupBox8 = new QGroupBox("TURBINE 7");
    groupBox9 = new QGroupBox("TURBINE 8");
    groupBox10 = new QGroupBox("TURBINE 9");
    groupBox11 = new QGroupBox("TURBINE 10");
    groupBox12 = new QGroupBox("TURBINE 11");
    groupBox13 = new QGroupBox("TURBINE 12");
    groupBox14 = new QGroupBox("TURBINE 13");
    groupBox15 = new QGroupBox("TURBINE 14");

    QHBoxLayout *hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(groupBox1);
    hlayout1->addWidget(groupBox2);
    hlayout1->addWidget(groupBox3);
    hlayout1->addWidget(groupBox4);
    hlayout1->addWidget(groupBox5);

    QHBoxLayout *hlayout2 = new QHBoxLayout;
    hlayout2->addWidget(groupBox6);
    hlayout2->addWidget(groupBox7);
    hlayout2->addWidget(groupBox8);
    hlayout2->addWidget(groupBox9);
    hlayout2->addWidget(groupBox10);

    QHBoxLayout *hlayout3 = new QHBoxLayout;
    hlayout3->addWidget(groupBox11);
    hlayout3->addWidget(groupBox12);
    hlayout3->addWidget(groupBox13);
    hlayout3->addWidget(groupBox14);
    hlayout3->addWidget(groupBox15);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addLayout(hlayout1);
    vlayout->addLayout(hlayout2);
    vlayout->addLayout(hlayout3);


    mTurbine1->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine2->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine3->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine4->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine5->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine6->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine7->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine8->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine9->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine10->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine11->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine12->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine13->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine14->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);
    mTurbine15->setFixedSize(TURBINE_WIDTH,TURBINE_HEIGHT);

    QVBoxLayout *vlayoutGroup1 = new QVBoxLayout;
    vlayoutGroup1->addWidget(mTurbine1);

    QVBoxLayout *vlayoutGroup2 = new QVBoxLayout;
    vlayoutGroup2->addWidget(mTurbine2);

    QVBoxLayout *vlayoutGroup3 = new QVBoxLayout;
    vlayoutGroup3->addWidget(mTurbine3);

    QVBoxLayout *vlayoutGroup4 = new QVBoxLayout;
    vlayoutGroup4->addWidget(mTurbine4);

    QVBoxLayout *vlayoutGroup5 = new QVBoxLayout;
    vlayoutGroup5->addWidget(mTurbine5);

    QVBoxLayout *vlayoutGroup6 = new QVBoxLayout;
    vlayoutGroup6->addWidget(mTurbine6);

    QVBoxLayout *vlayoutGroup7 = new QVBoxLayout;
    vlayoutGroup7->addWidget(mTurbine7);

    QVBoxLayout *vlayoutGroup8 = new QVBoxLayout;
    vlayoutGroup8->addWidget(mTurbine8);

    QVBoxLayout *vlayoutGroup9 = new QVBoxLayout;
    vlayoutGroup9->addWidget(mTurbine9);

    QVBoxLayout *vlayoutGroup10 = new QVBoxLayout;
    vlayoutGroup10->addWidget(mTurbine10);

    QVBoxLayout *vlayoutGroup11 = new QVBoxLayout;
    vlayoutGroup11->addWidget(mTurbine11);

    QVBoxLayout *vlayoutGroup12 = new QVBoxLayout;
    vlayoutGroup12->addWidget(mTurbine12);

    QVBoxLayout *vlayoutGroup13 = new QVBoxLayout;
    vlayoutGroup13->addWidget(mTurbine13);

    QVBoxLayout *vlayoutGroup14 = new QVBoxLayout;
    vlayoutGroup14->addWidget(mTurbine14);

    QVBoxLayout *vlayoutGroup15 = new QVBoxLayout;
    vlayoutGroup15->addWidget(mTurbine15);

    groupBox1->setLayout(vlayoutGroup1);
    groupBox2->setLayout(vlayoutGroup2);
    groupBox3->setLayout(vlayoutGroup3);
    groupBox4->setLayout(vlayoutGroup4);
    groupBox5->setLayout(vlayoutGroup5);
    groupBox6->setLayout(vlayoutGroup6);
    groupBox7->setLayout(vlayoutGroup7);
    groupBox8->setLayout(vlayoutGroup8);
    groupBox9->setLayout(vlayoutGroup9);
    groupBox10->setLayout(vlayoutGroup10);
    groupBox11->setLayout(vlayoutGroup11);
    groupBox12->setLayout(vlayoutGroup12);
    groupBox13->setLayout(vlayoutGroup13);
    groupBox14->setLayout(vlayoutGroup14);
    groupBox15->setLayout(vlayoutGroup15);

    this->setLayout(vlayout);

    connect(this->mSerialPort, SIGNAL(readyRead()), this, SLOT(serialReciver()));

    connect(prefs, SIGNAL(turbineName1Changed(QString)), this, SLOT(setTurbineName1(QString)));
    connect(prefs, SIGNAL(turbineName2Changed(QString)), this, SLOT(setTurbineName2(QString)));
    connect(prefs, SIGNAL(turbineName3Changed(QString)), this, SLOT(setTurbineName3(QString)));
    connect(prefs, SIGNAL(turbineName4Changed(QString)), this, SLOT(setTurbineName4(QString)));
    connect(prefs, SIGNAL(turbineName5Changed(QString)), this, SLOT(setTurbineName5(QString)));
}

TurbineTabPage::~TurbineTabPage()
{
    if (mOutput.is_open()) {
        mOutput.close();
    }
}


void TurbineTabPage::serialReciver()
{
    QString input_converter;
    std::string to_file_string;
    Preferences *prefs = Preferences::instance();

    //if the whole line isn't available within the next 4 chars
    if (mSerialPort->bytesAvailable() < 5)
        return; //return from this call (wait for the next readyRead() signal)

    char dataBuffer[6];

    mSerialPort->readLine(dataBuffer,6);

    to_file_string = dataBuffer;
    input_converter = QString::fromStdString(to_file_string);

    char current_turbine = input_converter.at(0).toLatin1();
    QString current_value = input_converter.mid( 1, input_converter.length() );

    mTime = QTime::currentTime().toString("hh:mm:ss:zzz");
    QByteArray bytearray = mTime.toLatin1();
    char *current_time =  bytearray.data();


    if ( current_value.toInt() != 0 ) {

        switch (current_turbine) {
        case 'a':
            prefs->cacheStore("plot1", current_value);
            mTurbine1->setValue(current_value.toInt());
            break;

        case 'b':
            prefs->cacheStore("plot2", current_value);
            mTurbine2->setValue(current_value.toInt());
            break;
        case 'c':
            prefs->cacheStore("plot3", current_value);
            mTurbine3->setValue(current_value.toInt());
            break;

        case 'd':
            prefs->cacheStore("plot4", current_value);
            mTurbine4->setValue(current_value.toInt());
            break;
        case 'e':
            prefs->cacheStore("plot5", current_value);
            mTurbine5->setValue(current_value.toInt());
            break;
        case 'f':
            prefs->cacheStore("plot1", current_value);
            mTurbine6->setValue(current_value.toInt());
            break;

        case 'g':
            prefs->cacheStore("plot2", current_value);
            mTurbine7->setValue(current_value.toInt());
            break;
        case 'h':
            prefs->cacheStore("plot3", current_value);
            mTurbine8->setValue(current_value.toInt());
            break;

        case 'i':
            prefs->cacheStore("plot4", current_value);
            mTurbine9->setValue(current_value.toInt());
            break;
        case 'j':
            prefs->cacheStore("plot5", current_value);
            mTurbine10->setValue(current_value.toInt());
            break;
        case 'k':
            prefs->cacheStore("plot1", current_value);
            mTurbine11->setValue(current_value.toInt());
            break;

        case 'l':
            prefs->cacheStore("plot2", current_value);
            mTurbine12->setValue(current_value.toInt());
            break;
        case 'm':
            prefs->cacheStore("plot3", current_value);
            mTurbine13->setValue(current_value.toInt());
            break;

        case 'n':
            prefs->cacheStore("plot4", current_value);
            mTurbine14->setValue(current_value.toInt());
            break;
        case 'o':
            prefs->cacheStore("plot5", current_value);
            mTurbine15->setValue(current_value.toInt());
            break;

        }

        mOutput << current_time << " " << prefs->cacheLookup("plot1").toInt() << " " << prefs->cacheLookup("plot2").toInt() << " "
                << prefs->cacheLookup("plot3").toInt() << " " << prefs->cacheLookup("plot4").toInt() << " " << prefs->cacheLookup("plot5").toInt() << " "
                << prefs->cacheLookup("plot6").toInt() << " " << prefs->cacheLookup("plot7").toInt() << " " << prefs->cacheLookup("plot8").toInt() << " "
                << prefs->cacheLookup("plot9").toInt()<< " " << prefs->cacheLookup("plot10").toInt() << " " << prefs->cacheLookup("plot11").toInt() << " "
                << prefs->cacheLookup("plot12").toInt() << " " << prefs->cacheLookup("plot13").toInt() << " " << prefs->cacheLookup("plot14").toInt() << " "
                << prefs->cacheLookup("plot15").toInt() << " " << std::endl;
    }


    if (mSerialPort->bytesAvailable() > 0)
        QMetaObject::invokeMethod(this, "serialReciver", Qt::QueuedConnection);
}

void TurbineTabPage::setTurbineName1(QString name)
{
    this->groupBox1->setTitle(name);
}

void TurbineTabPage::setTurbineName2(QString name)
{
    this->groupBox2->setTitle(name);
}

void TurbineTabPage::setTurbineName3(QString name)
{
    this->groupBox3->setTitle(name);
}

void TurbineTabPage::setTurbineName4(QString name)
{
    this->groupBox4->setTitle(name);
}

void TurbineTabPage::setTurbineName5(QString name)
{
    this->groupBox5->setTitle(name);
}

void TurbineTabPage::setTurbineName6(QString name)
{
    this->groupBox6->setTitle(name);
}

void TurbineTabPage::setTurbineName7(QString name)
{
    this->groupBox7->setTitle(name);
}

void TurbineTabPage::setTurbineName8(QString name)
{
    this->groupBox8->setTitle(name);
}

void TurbineTabPage::setTurbineName9(QString name)
{
    this->groupBox9->setTitle(name);
}

void TurbineTabPage::setTurbineName10(QString name)
{
    this->groupBox10->setTitle(name);
}
void TurbineTabPage::setTurbineName11(QString name)
{
    this->groupBox11->setTitle(name);
}

void TurbineTabPage::setTurbineName12(QString name)
{
    this->groupBox12->setTitle(name);
}

void TurbineTabPage::setTurbineName13(QString name)
{
    this->groupBox13->setTitle(name);
}

void TurbineTabPage::setTurbineName14(QString name)
{
    this->groupBox14->setTitle(name);
}

void TurbineTabPage::setTurbineName15(QString name)
{
    this->groupBox15->setTitle(name);
}
