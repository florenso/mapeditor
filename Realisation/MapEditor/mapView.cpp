#include "mapView.hpp"

mapView::mapView(QWidget *parent, QGraphicsView * view, int width, int height):
    view(view),
    windowWidth(width),
    windowHeight(height)
{
    //if no height or with given, set to view size
    if(width == 0){
        windowWidth = view->width();
    }
    if(height == 0){
        windowHeight = view->height();
    }
    scene = new QGraphicsScene;
    std::cout << "new Viewer with size: " << windowWidth << " x " << windowHeight << std::endl;
    scene->setSceneRect( 0, 0, windowWidth, windowHeight);
    view->setScene(scene);
    tileType[QString("free")]=Qt::green;
    tileType[QString("blocked")]=Qt::red;
    tileType[QString("unkown")]=Qt::black;
}

mapView::~mapView(){
    delete view;
    delete scene;
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

void mapView::drawLine(int x1, int y1, int x2, int y2, QRgb color){
    //Bad method needs rework
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, x2-x1, y2-y1);
    block->setBrush(* new QBrush(color));
    block->setPos(x1, y1);
    scene->addItem(block);
    view->setScene(scene);
    view->show();
}

void mapView::setTag(int x, int y, std::string value){
    //place a text on a point on mapView

}

void mapView::clear(){
    QList<QGraphicsItem *> list = scene->items();
    foreach( QGraphicsItem * item, list ){
        scene->removeItem(item);
    }
}
