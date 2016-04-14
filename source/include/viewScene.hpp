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
//#include "map_utils.hpp"
//#include "stubs.hpp"
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

    QRectF box_tile_2_qrect(r2d2::Box box);
public:

    void drawAxes();
    QPoint getOriginOffset();

    void addOriginOffset(int unsigned x, int unsigned y);

    void setNewOriginOffset(int unsigned xOffset,int unsigned yOffset);

    explicit viewScene(QObject *parent = 0);

    //! Draws a tile with position x,y and size width,height on the scene.
    void drawTile(int x, int y, int width, int height, QColor color);

    //! Draws a line from position x1,y1 to position x2,y2 on the scene.
    void drawLine(int x1, int y1, int x2, int y2, QRgb color);

    //! Draws a the text value on the scene on position x,y.
    void setTag(int x, int y, QString value);

    //! Clears all the objects in the scene.
    void clear();



    void drawTile(r2d2::Box box, QColor color);
signals:

public slots:


    };

#endif // VIEWSCENE_HPP
