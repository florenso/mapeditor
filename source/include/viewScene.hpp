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

class viewScene : public QGraphicsScene
    {
    Q_OBJECT

private:

    QPoint originOffset{0,0};


    QGraphicsLineItem * xAxis = addLine(0,0,0,0);
    QGraphicsLineItem * yAxis = addLine(0,0,0,0);


public:

    void drawAxes();
    QPoint getOriginOffset();

    void addOriginOffset(int unsigned x, int unsigned y);

    void setNewOriginOffset(int unsigned xOffset,int unsigned yOffset);

    explicit viewScene(QObject *parent = 0);

    //! Draws a line from position x1,y1 to position x2,y2 on the scene.
    void drawLine(r2d2::Coordinate point1, r2d2::Coordinate point2, QColor color);

    //! Draws a the text value on the scene on position x,y.
    void setTag(int x, int y, QString value);

    //! delete selected items
    void deleteSelectedItems();

    //! Clears all the objects in the scene.
    void clear();

    void drawTile(r2d2::Box box, QColor color);

    bool isTile(QGraphicsItem * item);

    QPointF box_coordinate_2_qpoint(r2d2::Coordinate);
    QRectF box_tile_2_qrect(r2d2::Box box);
    r2d2::Coordinate qpoint_2_box_coordinate(QPointF point, double z = 0);
    r2d2::Box qrect_2_box_coordinate(QRectF rect, double min_z = 0, double max_z = 1);
signals:

public slots:


    };

#endif // VIEWSCENE_HPP
