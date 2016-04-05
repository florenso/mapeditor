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
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QString>
#include <iostream>
#include <string>
#include <map>
#include "viewScene.hpp"
//#include "RectInfo"



class mapView: public QGraphicsView
{
public:
    //! Constructor of the mapView.
    explicit mapView(QWidget *parent);

    //! Deconstroctor of the mapView.
    ~mapView();

    void increaseScale(qreal inc = 0.025f);
    void decreaseScale(qreal dec = 0.025f);
    void increaseRotation(int inc = 90);
    void decreaseRotation(int dec = 90);
    void resetRotation();
    void resetScale();
    void setZoomSpeed(qreal speed);
    int getScale();
    int getRotation();

    //void drawMap(RectInfo *map);
    viewScene * scene;
private:
    void updateTransform();
    int windowWidth;
    int windowHeight;
    int rotation  = 0;
    qreal zoomSpeed = 0.05f;
    qreal maxScale  = 1.0f;
    qreal minScale  = 0.1f;
    qreal scaleSize = 0.5f;
    int scrollStepSize=10;

protected:
    //! Catches all events and returns true when a event is caught
    bool event(QEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
    };

#endif // MAPVIEW_HPP
