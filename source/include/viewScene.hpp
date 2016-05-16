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
#include "Box.hpp"
#include "Coordinate.hpp"
#include "Translation.hpp"
#include "Length.hpp"

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
    void drawLine(int x1, int y1, int x2, int y2, QRgb color);

    //! Draws a the text value on the scene on position x,y.
    void setTag(int x, int y, QString value);

    //! delete selected items
    void deleteSelectedItems();

    //! Clears all the objects in the scene.
    void clear();

    void drawTile(r2d2::Box box, QColor color);

    bool isTile(QGraphicsItem * item);

    void setTag(r2d2::Coordinate pos, QString value);

    QPointF box_coordinate_2_qpoint(r2d2::Coordinate);
    QRectF box_tile_2_qrect(r2d2::Box box);
    r2d2::Coordinate qpoint_2_box_coordinate(QPointF point, double z = 0);
    r2d2::Box qrect_2_box_coordinate(QRectF rect, double min_z = 0, double max_z = 1);
signals:

public slots:


    };

#endif // VIEWSCENE_HPP
