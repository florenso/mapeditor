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
    source/src/viewScene.cpp \
    ../adt/source/src/Length.cpp \
    ../adt/source/src/Translation.cpp \
    ../adt/source/src/Box.cpp \
    ../adt/source/src/Coordinate.cpp \
    ../map/source/src/MapInterface.cpp


HEADERS  += source/include/mainwindow.hpp \
    source/include/map_utils.hpp \
    source/include/mapEditor.hpp \
    source/include/mapView.hpp \
    source/include/RectInfo.hpp \
    source/include/stubs.hpp \
    source/include/viewScene.hpp \
    ../adt/source/include/Length.hpp \
    ../adt/source/include/Translation.hpp \
    ../adt/source/include/Box.hpp \
    ../adt/source/include/Coordinate.hpp \
    ../map/source/include/MapInterface.hpp




FORMS    += source/mainwindow.ui
