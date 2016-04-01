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

enum class tileTypes {Free, Blocked, Mixed, Unknown};

class mapView: public QWidget
{
public:
    explicit mapView(QWidget *parent, QGraphicsView * view, int width=0, int height=0);
    ~mapView();
    void drawTile(int x, int y, int width, int height, QString type);
    void drawLine(int x1, int y1, int x2, int y2, QRgb color);
    void setTag(int x, int y, QString value);
    void clear();
    tileTypes getTileColor(QString s);
    bool mouseInMapView();
private:
    int windowWidth;
    int windowHeight;
    int scale;
    QGraphicsView * view;
    QGraphicsScene * scene;
    std::map<tileTypes, QColor> tileColors;
protected:
    virtual void wheelEvent(QWheelEvent * event);
    bool event(QEvent *event);
    };

#endif // CANVAS_HPP
