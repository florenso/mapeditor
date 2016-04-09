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
#include "map_utils.hpp"
#include "stubs.hpp"
#include <map>

class viewScene : public QGraphicsScene
    {
    Q_OBJECT
public:
    explicit viewScene(QObject *parent = 0);

    //! Draws a tile with position x,y and size width,height on the scene.
    void drawTile(int x, int y, int width, int height, QColor color);

    //! Draws a line from position x1,y1 to position x2,y2 on the scene.
    void drawLine(int x1, int y1, int x2, int y2, QRgb color);

    //! Draws a the text value on the scene on position x,y.
    void setTag(int x, int y, QString value);

    //! Clears all the objects in the scene.
    void clear();


signals:

public slots:


    };

#endif // VIEWSCENE_HPP
