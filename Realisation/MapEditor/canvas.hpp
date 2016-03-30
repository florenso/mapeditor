#ifndef CANVAS_HPP
#define CANVAS_HPP
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

enum class tileType {
    free = Qt::green,
    blocked = Qt::red,
    unkown = Qt::black
};

class Canvas: public QWidget
{
public:
    Canvas(QWidget *parent, QGraphicsView * view);
    void drawTile(int x, int y, int width, int height, tileType type);
    void drawLine(int x1, int y1, int x2, int y2, int width, QRgb color);
    void setTag(int x, int y, std::string value);
    void clear();
private:
    int windowWidth = 0;
    int windowHeight = 0;
    QGraphicsView * view;
    QGraphicsScene * scene;

};

#endif // CANVAS_HPP
