#include "canvas.hpp"

Canvas::Canvas(QWidget *parent, QGraphicsView * view):

{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene->setSceneRect( 0, 0, 400, 400);
    view = ui->graphicsView;
    //view->setFixedSize(390, 390);
    view->setScene(scene);
}

void Canvas::drawTile(int x, int y, int width, int height, tileType type){
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, width, height);
    block->setBrush(* new QBrush(color));
    block->setPos(x, y);
    scene->addItem(block);
    view->setScene(scene);
    view->show();
}

void Canvas::drawLine(int x1, int y1, int x2, int y2, int width, QRgb color){
    //draw a line on the canvas
}

void Canvas::setTag(int x, int y, std::string value){
    //place a text on a point on canvas
}

void Canvas::clear(){
    /*iter door scene->items();
    for(){
       scene->removeItem(item);
    }
    */
}
