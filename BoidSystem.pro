#-------------------------------------------------
#
# Project created by QtCreator 2014-11-11T15:36:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BoidSystem
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    management.cpp \
    boid.cpp \
    coordinate.cpp \
    navigation.cpp

HEADERS  += mainwindow.h \
    management.h \
    boid.h \
    coordinate.h \
    navigation.h

FORMS    += mainwindow.ui
