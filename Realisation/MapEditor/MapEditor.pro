#-------------------------------------------------
#
# Project created by QtCreator 2016-03-29T14:23:54
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    map_utils.cpp \
    RectInfo.cpp \
    stubs.cpp

HEADERS  += mainwindow.hpp \
    map_utils.hpp \
    RectInfo.hpp \
    stubs.hpp

FORMS    += mainwindow.ui
