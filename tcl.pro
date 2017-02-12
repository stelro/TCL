#-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T14:27:28
#
#-------------------------------------------------

QT += core gui
QT += serialport
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = tcl
TEMPLATE = app


SOURCES += main.cpp\
        splashdialog.cpp \
    mainwindow.cpp \
    preferences.cpp \
    qcgaugewidget.cpp \
    turbinetabpage.cpp \
    settingstabpage.cpp \
    charttabpage.cpp \
    titlebar.cpp \
    qcustomplot/qcustomplot.cpp \
    turbinewidget.cpp

HEADERS  += splashdialog.hpp \
    mainwindow.hpp \
    preferences.hpp \
    qcgaugewidget.hpp \
    turbinetabpage.hpp \
    settingstabpage.hpp \
    charttabpage.hpp \
    titlebar.hpp \
    qcustomplot/qcustomplot.h \
    turbinewidget.hpp

FORMS    += splashdialog.ui \
    mainwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    Exit Filled-50.png \
    Jet Engine Filled-50.png \
    Settings-48.png \
    Scatter Plot-64.png

