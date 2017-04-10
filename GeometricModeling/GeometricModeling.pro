#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T15:50:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeometricModeling
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS_DEBUG *= -g -O0 -std=c++11 -Wno-deprecated
QMAKE_CXXFLAGS_RELEASE *= -O3 -std=c++11 -Wno-deprecated

SOURCES += main.cpp\
        mainwindow.cpp \
    vector.cpp

HEADERS  += mainwindow.h \
    vector.h \
    primitives.h

FORMS    += mainwindow.ui
