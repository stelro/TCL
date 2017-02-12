#include "settingstabpage.hpp"
#include "preferences.hpp"

#include <QGroupBox>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

const int LINE_EDIT_WIDTH = 120;

SettingsTabPage::SettingsTabPage()
{




//    Preferences *prefs = Preferences::instance();

//    connect(textEdit1, SIGNAL(textChanged(QString)), prefs, SLOT(setTurbineName1(QString)));
//    connect(prefs,SIGNAL(turbineName1Changed(QString)), this, SLOT(setTurbineName1(QString)));

//    connect(textEdit2, SIGNAL(textChanged(QString)), prefs, SLOT(setTurbineName2(QString)));
//    connect(prefs,SIGNAL(turbineName2Changed(QString)), this, SLOT(setTurbineName2(QString)));

//    connect(textEdit3, SIGNAL(textChanged(QString)), prefs, SLOT(setTurbineName3(QString)));
//    connect(prefs,SIGNAL(turbineName3Changed(QString)), this, SLOT(setTurbineName3(QString)));

//    connect(textEdit4, SIGNAL(textChanged(QString)), prefs, SLOT(setTurbineName4(QString)));
//    connect(prefs,SIGNAL(turbineName4Changed(QString)), this, SLOT(setTurbineName4(QString)));

//    connect(textEdit5, SIGNAL(textChanged(QString)), prefs, SLOT(setTurbineName5(QString)));
//    connect(prefs,SIGNAL(turbineName5Changed(QString)), this, SLOT(setTurbineName5(QString)));

    QVBoxLayout *vlayout = new QVBoxLayout;
    QHBoxLayout *settingsLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    vlayout->addLayout(settingsLayout);
    vlayout->addLayout(buttonLayout);

    QPushButton *applyButton = new QPushButton("&Apply");
    applyButton->setFixedWidth(100);
    buttonLayout->addWidget(applyButton, 0, Qt::AlignRight);
    applyButton->setDisabled(true);

    QGroupBox *turbinesBox = new QGroupBox("Turbines Settings");
    QGroupBox *plotBox = new QGroupBox("Plot Settings");

    settingsLayout->addWidget(turbinesBox);
    settingsLayout->addWidget(plotBox);

    QGridLayout *turbinesNamesGrid = new QGridLayout;
    turbinesBox->setLayout(turbinesNamesGrid);

    QLabel *label1 = new QLabel("<font color='black'>Turbine 1: </font>");
    turbinesNamesGrid->addWidget(label1,0,0);
    QLineEdit *lineEdit1 = new QLineEdit;
    lineEdit1->setFixedWidth(LINE_EDIT_WIDTH);
    turbinesNamesGrid->addWidget(lineEdit1, 0, 1);

    QLabel *label2 = new QLabel("<font color='black'>Turbine 2: </font>");
    turbinesNamesGrid->addWidget(label2,1,0);
    QLineEdit *lineEdit2 = new QLineEdit;
    lineEdit1->setFixedWidth(LINE_EDIT_WIDTH);
    turbinesNamesGrid->addWidget(lineEdit2, 1, 1);

    QLabel *label3 = new QLabel("<font color='black'>Turbine 3: </font>");
    turbinesNamesGrid->addWidget(label3,2,0);
    QLineEdit *lineEdit3 = new QLineEdit;
    lineEdit1->setFixedWidth(LINE_EDIT_WIDTH);
    turbinesNamesGrid->addWidget(lineEdit3, 2, 1);

    QLabel *label4 = new QLabel("<font color='black'>Turbine 4: </font>");
    turbinesNamesGrid->addWidget(label4,3,0);
    QLineEdit *lineEdit4 = new QLineEdit;
    lineEdit1->setFixedWidth(LINE_EDIT_WIDTH);
    turbinesNamesGrid->addWidget(lineEdit4, 3, 1);

    QLabel *label5 = new QLabel("<font color='black'>Turbine 5: </font>");
    turbinesNamesGrid->addWidget(label5,4,0);
    QLineEdit *lineEdit5 = new QLineEdit;
    lineEdit1->setFixedWidth(LINE_EDIT_WIDTH);
    turbinesNamesGrid->addWidget(lineEdit5, 4, 1);

    QGridLayout *plotGrid = new QGridLayout;
    plotBox->setLayout(plotGrid);



    this->setLayout(vlayout);
}

void SettingsTabPage::setTurbineName1(QString name)
{
    groupBox1->setTitle(name);
}

void SettingsTabPage::setTurbineName2(QString name)
{
    groupBox2->setTitle(name);
}

void SettingsTabPage::setTurbineName3(QString name)
{
    groupBox3->setTitle(name);
}

void SettingsTabPage::setTurbineName4(QString name)
{
    groupBox4->setTitle(name);
}

void SettingsTabPage::setTurbineName5(QString name)
{
    groupBox5->setTitle(name);
}
