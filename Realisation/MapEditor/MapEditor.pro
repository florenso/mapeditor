#----------------------------------------------
#
# Project created by QtCreator 2016-03-29T14:23:54
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mapView.cpp \
    map_utils.cpp \
    RectInfo.cpp \
    mapEditor.cpp \
    viewScene.cpp

HEADERS  += mainwindow.hpp \
    mapView.hpp \
    map_utils.hpp \
    RectInfo.hpp \
    stubs.hpp \
    mapEditor.hpp \
    viewScene.hpp

FORMS    += mainwindow.ui
