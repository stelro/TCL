#-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T14:27:28
#
#-------------------------------------------------

QT       += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    titlebar.cpp

HEADERS  += splashdialog.hpp \
    mainwindow.hpp \
    preferences.hpp \
    qcgaugewidget.hpp \
    turbinetabpage.hpp \
    settingstabpage.hpp \
    charttabpage.hpp \
    titlebar.hpp

FORMS    += splashdialog.ui \
    mainwindow.ui

RESOURCES += \
    resources.qrc

