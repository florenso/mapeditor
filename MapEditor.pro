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
    viewScene.cpp \
    source/Maputils/map_utils.cpp \
    source/Maputils/RectInfo.cpp \
    source/Maputils/stubs.cpp \
    source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/map_utils.cpp \
    source/src/mapEditor.cpp \
    source/src/mapView.cpp \
    source/src/RectInfo.cpp \
    source/src/viewScene.cpp

HEADERS  += mainwindow.hpp \
    mapView.hpp \
    map_utils.hpp \
    RectInfo.hpp \
    stubs.hpp \
    mapEditor.hpp \
    viewScene.hpp \
    source/include/mainwindow.hpp \
    source/include/map_utils.hpp \
    source/include/mapEditor.hpp \
    source/include/mapView.hpp \
    source/include/RectInfo.hpp \
    source/include/stubs.hpp \
    source/include/viewScene.hpp \
    source/Maputils/map_utils.hpp \
    source/Maputils/RectInfo.hpp \
    source/Maputils/stubs.hpp

FORMS    += mainwindow.ui
