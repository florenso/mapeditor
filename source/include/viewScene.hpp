#ifndef VIEWSCENE_HPP
#define VIEWSCENE_HPP

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <map>
#include <iostream>
#include <map>
#include <QPoint>
#include <QPen>
#include "../../../adt/source/include/Box.hpp"
#include "../../../adt/source/include/Coordinate.hpp"
#include "../../../adt/source/include/Translation.hpp"
#include "../../../adt/source/include/Length.hpp"


//! The class that represents the drawable area of a mapviewer
/*!
 * The class that represents the drawable area of a mapviewer
 * It contains methods to draw lines and tags and to change the origin from
 * which the map is drawn
 */
class viewScene : public QGraphicsScene
    {
    Q_OBJECT
private:

    QPoint originOffset{0,0};


    QGraphicsLineItem * xAxis = addLine(0,0,0,0);
    QGraphicsLineItem * yAxis = addLine(0,0,0,0);


public:

    //! Draws the axes at the correct location.
    void drawAxes();

    //! Returns the current offset from the origin
    QPoint getOriginOffset();

    //! Adds distance to the current offset from the origin
    //! @param x The distance to add in the x direction. Can be negative!
    //! @param y The distance to add in the y direction. Can be negative!
    void addOriginOffset(int unsigned x, int unsigned y);

    //! Sets a new offset from the origin
    //! @param x The offset in the x direction. Can be negative!
    //! @param y The offset in the y direction. Can be negative!
    void setNewOriginOffset(int unsigned xOffset,int unsigned yOffset);

    //! The constructor for the ViewScene
    //! @param parent A pointer to the parent QObject.
    explicit viewScene(QObject *parent = 0);

    //! Draws a line from position x1,y1 to position x2,y2 on the scene.
    //! @param x1 The x coord of the first coordinate
    //! @param y1 The y coord of the first coordinate
    //! @param x2 The x coord of the second coordinate
    //! @param y2 The y coord of the second coordinate
    void drawLine(int x1, int y1, int x2, int y2, QRgb color);

    //! Draws a the text value on the scene on position x,y.
    //! @param x The x location of the location to draw the tag
    //! @param y The y location of the location to draw the tag
    //! @param value The string to draw as an QString
    void setTag(int x, int y, QString value);

    //! Clears all the objects in the scene.
    void clear();

    //! Draws a tile onto the screen
    //! @param box The area to draw
    //! @param color The color to draw as an QColor
    void drawTile(r2d2::Box box, QColor color);

    //! A conversion method that takes a r2d2 coordinate and converts it to
    //! a QPointf
    //! @param coordinate The coordinate to convert
    QPointF box_coordinate_2_qpoint(r2d2::Coordinate coordinate);

    //! A conversion method that takes a Box and converts it to
    //! a QRectF
    //! @param coordinate The r2d2 Box to convert
    QRectF box_tile_2_qrect(r2d2::Box box);

    //! A conversion method that takes a QPointf and converts it to
    //! a r2d2 coordinate
    //! @param coordinate The QPointf to convert
    //! @param z The height the coordinate should be
    r2d2::Coordinate qpoint_2_box_coordinate(QPointF point, double z = 0);

    //! A conversion method that takes a QRectF and converts it to
    //! a r2d2 Box with a given Z range
    //! @param coordinate The QPointf to convert
    //! @param min_z The lowest height the Box should be
    //! @param max_Z The highest height the Box should be
    r2d2::Box qrect_2_box_coordinate(QRectF rect, double min_z = 0, double max_z = 1);
signals:

public slots:


    };

#endif // VIEWSCENE_HPP
