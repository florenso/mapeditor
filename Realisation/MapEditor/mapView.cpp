#include "mapView.hpp"

mapView::mapView(QWidget *parent, QGraphicsView * view)

{
    scene = new QGraphicsScene;
    scene->setSceneRect( 0, 0, 400, 400);
    view->setScene(scene);
    tileType["free"]=Qt::green;
    tileType["blocked"]=Qt::red;
    tileType["unkown"]=Qt::black;

}

void mapView::drawTile(int x, int y, int width, int height, QString type){
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, width, height);
    block->setBrush(* new QBrush(tileType[type]));
    block->setPos(x, y);
    scene->addItem(block);
    view->setScene(scene);
    view->show();
}

void mapView::drawLine(int x1, int y1, int x2, int y2, int width, QRgb color){
    //draw a line on the mapView
}

void mapView::setTag(int x, int y, std::string value){
    //place a text on a point on mapView
}

void mapView::clear(){
    /*iter door scene->items();
    for(){
       scene->removeItem(item);
    }
    */
}
