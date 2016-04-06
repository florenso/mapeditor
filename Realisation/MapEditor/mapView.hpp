//**************************************
//! Class responsible for drawing the objects from the map
//! \authors
//! 	- Daniel Klomp
//!		- Jop van Buuren
//!     - Koen de Guijter
//!
//! \context
//!		- part of TH7-8 assignment 2016 / Project: MapEditer
//**************************************

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
#include "map_utils.hpp"
#include "stubs.hpp"

class mapView: public QGraphicsView
{
public:
    //! Constructor of the mapView.
    explicit mapView(QWidget *parent);

    //! Deconstroctor of the mapView.
    ~mapView();

    //! Draws a tile with position x,y and size width,height on the scene.
    void drawTile(int x, int y, int width, int height, QColor color);

    //! Draws a line from position x1,y1 to position x2,y2 on the scene.
    void drawLine(int x1, int y1, int x2, int y2, QRgb color);

    //! Draws a the text value on the scene on position x,y.
    void setTag(int x, int y, QString value);

    //! Clears all the objects in the scene.
    void clear();

    MapTypes::TileType getTileColor(QString s);

    //! Checks to the mouse is located in the view.
    bool mouseInMapView(QPoint p);

    void drawMap(Map &map);
private:
    int windowWidth;
    int windowHeight;
    int scale;
    QGraphicsView * view;
    QGraphicsScene * scene;
    std::map<MapTypes::TileType, QColor> tileColors;

protected:
    //! Catches all events and returns true when a event is caught
    bool event(QEvent *event);
    };

#endif // MAPVIEW_HPP
