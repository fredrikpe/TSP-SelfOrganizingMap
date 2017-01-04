#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T09:40:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    selforganizingmap.cpp \
    canvas.cpp

HEADERS  += mainwindow.h \
    selforganizingmap.h \
    canvas.h

FORMS    += mainwindow.ui

# Compiler
QMAKE_CXX = g++-6
# FLAGS
QMAKE_CXXFLAGS += -Wall -Wextra -fopenmp -g

LIBS += -fopenmp

DISTFILES += \
    nicaragua_3496.txt \
    djibouti_38.txt \
    japan_9847.txt \
    oman_1979.txt \
    uruguay_734.txt \
    qatar_194.txt \
    western-sahara_29.txt
