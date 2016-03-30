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
#include <QGraphicsSceneMouseEvent>

class mapView: public QWidget
{
public:
    mapView(QWidget *parent, QGraphicsView * view);
    void drawTile(int x, int y, int width, int height, QString type);
    void drawLine(int x1, int y1, int x2, int y2, int width, QRgb color);
    void setTag(int x, int y, std::string value);
    void clear();
    bool mouseInMapView();
private:
    int windowWidth = 0;
    int windowHeight = 0;
    QGraphicsView * view;
    QGraphicsScene * scene;
    std::map<QString, QColor> tileType;
    //QCurrentView;
protected:
    virtual void wheelEvent(QWheelEvent * event);
    bool event(QEvent *event);
    };

#endif // CANVAS_HPP
