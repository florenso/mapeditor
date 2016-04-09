//**************************************
//! Class responsible for drawing the objects from the map
//! \authors
//! 	- Daniel Klomp
//!		- Jop van Buuren
//!     - Koen de Guijter
//!
//! \context
//!		- part of TH7-8 assignment 2016 / Project: MapEditer
//!
//! this class contains the methods to navigate,read and translates a map to avalible draw functions for a scene.
//!
//**************************************

//TODO: deze klasse moet een mapinterface hebben!!!

#ifndef MAPVIEW_HPP
#define MAPVIEW_HPP
#include "../../../map/source/include/MapInterface.hpp"
#include "../../../map/source/include/BoxMap.hpp"
#include "../../../adt/source/include/Box.hpp"
#include "../../../adt/source/include/Coordinate.hpp"
#include "../../../adt/source/include/Translation.hpp"
#include "../../../adt/source/include/Length.hpp"
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QString>
#include <iostream>
#include <string>

#include "viewScene.hpp"


namespace MapTypes{
    enum class TileType {
        UNKNOWN, MIXED, BLOCKED, EMPTY
    };
}

class mapView: public QGraphicsView
{
public:
    //! Constructor of the mapView.
    explicit mapView(QWidget *parent);

    //! Deconstroctor of the mapView.
    ~mapView();   

    void increaseScale();
    void decreaseScale();
    void increaseRotation(int inc = 90);
    void decreaseRotation(int dec = 90);
    void resetRotation();
    void resetScale();
    void setZoomSpeed(qreal speed);
    int getScale();
    int getRotation();
    void checkSceneBorder();

    viewScene * scene;

    std::map<MapTypes::TileType, QColor> tileColors;
    //std::map<bool, QColor> tileColors;

    void loadMapFile(string file);

    void drawMap();
    MapTypes::TileType getTileType(r2d2::BoxInfo & tileInfo);

private:


    void updateTransform();
    int windowWidth;
    int windowHeight;  
    int rotation  = 0;
    qreal zoomSpeed = 0.05f;
    qreal maxScale  = 5.0f;
    qreal minScale  = 0.1f;
    qreal scaleSize = (maxScale / 2) - minScale;
    int scrollStepSize=10;
    r2d2::SaveLoadMap * map;

protected:
    //! Catches all events and returns true when a event is caught
    bool event(QEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
    };

#endif // MAPVIEW_HPP
