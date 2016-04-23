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

//! The class that represents a map viewer, which shows an interactive r2d2::map.
/*!
 * The mapView class epresents a map viewer, which shows an interactive r2d2::map.
 * It allows users to move around the viewer and also lets the user zoom in
 * and rotate the map.
 * For new functionality, this class should be extended.
 */
class mapView: public QGraphicsView
{
public:
    //! Constructor of the mapView.
    //! @param parent A pointer to the parent QWidget
    explicit mapView(QWidget *parent);

    //! Destructor of the mapView.
    ~mapView();

    //! Increases the scale of the mapviewer by zooming out.
    //! It will zoom out with the current zoomspeed.
    void increaseScale();

    //! Increases the scale of the mapviewer by zooming in.
    //! It will zoom in with the current zoomspeed.
    void decreaseScale();

    //! Adds an angle to the current rotation of the mapviewer.
    //! Also updates the current view.
    //! @param inc The rotation to add.
    void increaseRotation(int inc = 90);

    //! Subtracts an angle to the current rotation of the mapviewer.
    //! Also updates the current view.
    //! @param inc The rotation to subtract.
    void decreaseRotation(int dec = 90);

    //! Resets the rotation to its original value.
    //! Also updates the view.
    void resetRotation();

    //! Resets the scale to its origin value.
    //! Also updates the view.
    void resetScale();

    //! Sets the zoomspeed to a given value.
    //! @param speed The zoomspeed as a Qreal
    void setZoomSpeed(qreal speed);

    //! Returns the current scale as an int
    int getScale();

    //! Returns the current rotation as an int
    int getRotation();

    //! Checks if the current view is near the borders of the loaded map.
    //! If that is the case, it loads an extra piece of the map and
    //! draws the map and axes correctly.
    void checkSceneBorder();

    //! Sets the lowest z coordinate of the area that is shown on the map.
    //! @param value The z coordinate that is to be set
    void set_z_bottom(float value);

    //! Sets the highest z coordinate of the area that is shown on the map.
    //! @param value The z coordinate that is to be set
    void set_z_top(float value);

    //! The current Scene the map is drawn upon.
    viewScene * scene;

    //! A std::map containing the coloring of the possible tiles in the map.
    std::map<MapTypes::TileType, QColor> tileColors;

    //! Loads the map into the viewer using file i/o.
    //! @param file The file to load the map from.
    void loadMapFile(string file);

    //! Draws the current map on the viewer.
    //! Resets scale and rotation and focuses on the center of the map.
    void drawMap();

    //! A helper method that obtains the tiletype from information about
    //! a piece of the map.
    //! @param tileInfo The BoxInfo from which to get the tiletype.
    MapTypes::TileType getTileType(r2d2::BoxInfo & tileInfo);

    //! Draws an area of the map by cutting it in pieces and obtaining their
    //! tiletypes.
    //! @param box The area to load and draw.
    //! @param tileSize The amount of pieces to cut the area into.
    void drawBox(r2d2::Box box, int tileSize = 10);
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

    //! Returns if you want to stop the event from going to other objects.
    bool eventFilter(QObject *object, QEvent *event);

    //! The bottom z coordinate of the loaded map
    float z_bottom = 0;

    //! The top z coordinate of the loaded map
    float z_top = 1;
    };

#endif // MAPVIEW_HPP
