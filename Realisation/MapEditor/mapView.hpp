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

class mapView: public QWidget
{
public:
    explicit mapView(QWidget *parent, QGraphicsView * view, int width=0, int height=0);
    ~mapView();
    void drawTile(int x, int y, int width, int height, QString type);
    void drawLine(int x1, int y1, int x2, int y2, QRgb color);
    void setTag(int x, int y, QString value);
    void clear();
private:
    int windowWidth;
    int windowHeight;
    QGraphicsView * view;
    QGraphicsScene * scene;
    std::map<QString, QColor> tileType;
    //QCurrentView;
};

#endif // CANVAS_HPP
