#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "preferences.hpp"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Preferences *prefs = Preferences::instance();
    qDebug() << prefs->cacheLookup("port");

}

MainWindow::~MainWindow()
{
    delete ui;
}
