#----------------------------------------------
#
# Project created by QtCreator 2016-03-29T14:23:54
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

RC_FILE = source/mapeditor.rc
ICON = source/mapeditor.icns

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapEditor
TEMPLATE = app


SOURCES += source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/mapEditor.cpp \
    source/src/mapView.cpp \
    source/src/viewScene.cpp \
    ../adt/source/src/Length.cpp \
    ../adt/source/src/Translation.cpp \
    ../adt/source/src/Box.cpp \
    ../adt/source/src/Coordinate.cpp \
    ../adt/source/src/Angle.cpp \
    ../map/source/src/MapInterface.cpp \
    ../map/source/src/BoxMap.cpp \
    ../polarview/source/src/DistanceReading.cpp \
    ../polarview/source/src/MapPolarView.cpp \
    source/src/polarview/polarViewTab.cpp \
    ../PolarView-Aggregator/source/src/PolarViewAggregator.cpp \
    ../PolarView-Aggregator/source/src/SensorAggregator.cpp


HEADERS  += source/include/mainwindow.hpp \
    source/include/mapEditor.hpp \
    source/include/mapView.hpp \
    source/include/viewScene.hpp \
    ../adt/source/include/Length.hpp \
    ../adt/source/include/Translation.hpp \
    ../adt/source/include/Box.hpp \
    ../adt/source/include/Angle.hpp \
    ../adt/source/include/Coordinate.hpp \
    ../map/source/include/MapInterface.hpp \
    ../map/source/include/BoxMap.hpp \
    ../adt/source/include/ADT_Base.hpp \
    ../polarview/source/include/DistanceReading.hpp \
    ../polarview/source/include/PolarView.hpp \
    ../polarview/source/include/MapPolarView.hpp \
    source/include/polarview/polarViewTab.hpp \
    ../sensorInterfaces/source/include/Sensor.hpp \
    ../sensorInterfaces/source/include/LocatedDistanceSensor.hpp \
    ../sensorInterfaces/source/include/CoordinateAttitude.hpp \
    ../sensorInterfaces/source/include/DistanceSensor.hpp \
    ../sensorInterfaces/source/include/Locatable.hpp \
    ../PolarView-Aggregator/source/include/PolarViewAggregator.hpp \
    ../PolarView-Aggregator/source/include/SensorAggregator.hpp


INCLUDEPATH += ../adt/source/include/
INCLUDEPATH += ../polarview/source/include/
INCLUDEPATH += source/include/
INCLUDEPATH += source/include/polarview/
INCLUDEPATH += ../PolarView-Aggregator/source/include/
INCLUDEPATH += ../sensorInterfaces/source/include/

FORMS    += source/mainwindow.ui \
    source/polarViewTab.ui
