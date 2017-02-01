#include "splashdialog.hpp"
#include "ui_splashdialog.h"
#include "mainwindow.hpp"
#include "preferences.hpp"

#include <QLineEdit>
#include <QApplication>

const int BUTTON_WIDTH = 91;
const int BUTTON_HEIGHT = 31;

SplashDialog::SplashDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplashDialog)
{
    ui->setupUi(this);

    /* Disable title bar from QDialog */

    this->setWindowFlags(Qt::CustomizeWindowHint);

    /* Add stylesheet to QDialog */

    updateSerialValue(ui->mAvailablePorts->currentText());
    connect(ui->mExitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->mConnectButton, SIGNAL(clicked(bool)), this, SLOT(showMainWindow()));
    connect(ui->mAvailablePorts, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateSerialValue(QString)));
    connect(ui->mRefreshButton, SIGNAL(clicked(bool)), this, SLOT(updateDialog()));

    this->setStyleSheet("QPushButton {border: none;  border-radius: 2px; height: 36px;  line-height: 36px;  padding: 0 2rem; "
                        "color: #fff; background-color: #333030; text-align: center; }"
                        "QPushButton:hover:!pressed { background-color: #595656; }"
                        "QDialog { background-color: #fff; } "
                        "QWidget#mTitleBar { background-color: #595656; } "
                        "QLabel { color: #fff; } " );

    /* Set fixed size policy for QPushButtons */

    ui->mConnectButton->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    ui->mConnectButton->setMaximumSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    ui->mRefreshButton->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    ui->mRefreshButton->setMaximumSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    ui->mExitButton->setMinimumSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    ui->mExitButton->setMaximumSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    /* Change label text and inherit title from QDialog form */

    ui->mTitleLabel->setText( this->windowTitle() );

    /* Prevent from window resizing */
    this->setFixedSize(this->size());

    updateDialog();
}

SplashDialog::~SplashDialog()
{
    delete ui;
}

void SplashDialog::showMainWindow()
{
    mMainWindow = new MainWindow();
    mMainWindow->show();
    this->hide();
}

void SplashDialog::updateSerialValue(const QString& value)
{
    Preferences *pref = Preferences::instance();
    pref->cacheStore("port", ui->mAvailablePorts->currentText());
}

void SplashDialog::updateDialog()
{
    ui->mAvailablePorts->clear();

    /* Get available serial ports */
    mAvaliableSPorts = QSerialPortInfo::availablePorts();
    /* list all available ports */
    foreach(QSerialPortInfo item , mAvaliableSPorts) {
        ui->mAvailablePorts->addItem(item.portName());
    }

    this->update();
}
