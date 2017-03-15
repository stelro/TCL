/*
 * Copyright (C) 2016
 * Author: Stelmach Rostislav <stelmach.ro@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "preferences.hpp"
#include "turbinetabpage.hpp"
#include "charttabpage.hpp"
#include "titlebar.hpp"

#include <QDebug>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    turbinePage(new TurbineTabPage),
    chartPage(new ChartTabPage)
{
    ui->setupUi(this);

    TitleBar *mTitleBar = new TitleBar(this);
    ui->verticalLayout->addWidget(mTitleBar);

    /* Disable title bar from QDialog */
    this->setWindowFlags(Qt::CustomizeWindowHint);

    /* Prevent from window resizing */
    this->setFixedSize(this->size());

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
    _turbineTab->setIcon( QIcon(":/jet_icon.png") );

    QListWidgetItem *_chartTab = new QListWidgetItem(ui->mTabBar);
    _chartTab->setText("Chart");
    _chartTab->setIcon( QIcon(":/plot_icon.png") );

    QListWidgetItem *_exitTab = new QListWidgetItem(ui->mTabBar);
    _exitTab->setText("Exit");
    _exitTab->setIcon( QIcon(":/Exit-52.png") );

    //ui->mTitleLabel->setText( this->windowTitle() );

    /* emit tab bar items events */
    connect(ui->mTabBar, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(tabBarItemClicked(QListWidgetItem*)));
    connect(ui->mTabBar, SIGNAL(currentRowChanged(int)), ui->mTabContainer, SLOT(setCurrentIndex(int)));

    ui->mTabContainer->insertWidget(0, turbinePage);
    ui->mTabContainer->insertWidget(1,chartPage);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tabBarItemClicked(QListWidgetItem *item)
{
    if (ui->mTabBar->item(2) == item) {
        this->close();
    }
}
