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


SOURCES += source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/map_utils.cpp \
    source/src/mapEditor.cpp \
    source/src/mapView.cpp \
    source/src/RectInfo.cpp \
    source/src/viewScene.cpp

HEADERS  += source/include/mainwindow.hpp \
    source/include/map_utils.hpp \
    source/include/mapEditor.hpp \
    source/include/mapView.hpp \
    source/include/RectInfo.hpp \
    source/include/stubs.hpp \
    source/include/viewScene.hpp \


FORMS    += source/mainwindow.ui
