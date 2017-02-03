#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "preferences.hpp"
#include "turbinetabpage.hpp"
#include "settingstabpage.hpp"
#include "charttabpage.hpp"
#include "titlebar.hpp"

#include <QDebug>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    turbinePage(new TurbineTabPage),
    chartPage(new ChartTabPage),
    settingsPage(new SettingsTabPage)
{
    ui->setupUi(this);

    TitleBar *mTitleBar = new TitleBar(this);
    ui->verticalLayout->addWidget(mTitleBar);

    /* Disable title bar from QDialog */
    this->setWindowFlags(Qt::CustomizeWindowHint);

    /* Prevent from window resizing */
    this->setFixedSize(this->size());

    Preferences *prefs = Preferences::instance();

    this->setStyleSheet("QPushButton {border: none;  border-radius: 2px; height: 36px;  line-height: 36px;  padding: 0 2rem; "
                        "color: #fff; background-color: #333030; text-align: center; }"
                        "QPushButton:hover:!pressed { background-color: #595656; }"
                        "QMainWindow { background-color: #fff; } "
                        "QWidget#mTitleBar { background-color: #595656; } "
                        "QLabel { color: #fff; } "
                        "QTabWidget::pane { background-color: #fff; border: 0; }"
                        "QListWidget { border: none; background-color: #333030; color: #fff;  }"
                        "QWidget#mTitleBar { background-color: #595656; }" );

    QListWidgetItem *_turbineTab = new QListWidgetItem(ui->mTabBar);
    _turbineTab->setText("RPM");
    _turbineTab->setIcon( QIcon(":/turbine-grey.png") );

    QListWidgetItem *_chartTab = new QListWidgetItem(ui->mTabBar);
    _chartTab->setText("Chart");
    _chartTab->setIcon( QIcon(":/chart-grey.png") );

    QListWidgetItem *_settingsTab = new QListWidgetItem(ui->mTabBar);
    _settingsTab->setText("Settings");
    _settingsTab->setIcon( QIcon(":/settings-grey.png") );

    QListWidgetItem *_exitTab = new QListWidgetItem(ui->mTabBar);
    _exitTab->setText("Exit");
    _exitTab->setIcon( QIcon(":/exit-grey.png") );

    //ui->mTitleLabel->setText( this->windowTitle() );

    /* emit tab bar items events */
    connect(ui->mTabBar, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(tabBarItemClicked(QListWidgetItem*)));
    connect(ui->mTabBar, SIGNAL(currentRowChanged(int)), ui->mTabContainer, SLOT(setCurrentIndex(int)));

    ui->mTabContainer->insertWidget(0, turbinePage);
    ui->mTabContainer->insertWidget(1,chartPage);
    ui->mTabContainer->insertWidget(2,settingsPage);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tabBarItemClicked(QListWidgetItem *item)
{
    if (ui->mTabBar->item(3) == item) {
        this->close();
    }
}
