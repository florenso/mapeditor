#include "mapView.hpp"
#include <iostream>
#include <QWheelEvent>
#include <QMouseEvent>

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
    drawTile(100, 100, 20, 20, "Free");
    drawTile(300, 200, 50, 70, "Unknown");
    drawTile(400, 500, 20, 20, "Blocked");
    drawTile(600, 700, 20, 20, "Mixed");
    //view->centerOn(0,0);
    tileColors[tileTypes::Free]=Qt::green;
    tileColors[tileTypes::Blocked]=Qt::red;
    tileColors[tileTypes::Mixed]=Qt::yellow;
    tileColors[tileTypes::Unknown]=Qt::black;
}

mapView::~mapView(){
    delete view;
    delete scene;
}

void mapView::drawTile(int x, int y, int width, int height, QString type){
    std::cout << "New tile: x " << x << " y " << y << " w " << width << " h " << height << std::endl;
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, width *scale, height * scale);
    block->setBrush(* new QBrush(tileColors[getTileColor(type)]));
    block->setPos(x*scale, y*scale);
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

void mapView::setTag(int x, int y, QString value){
    QGraphicsTextItem *item = scene->addText(value);
    item->setPos(x,y);
}

void mapView::clear(){
    QList<QGraphicsItem *> list = scene->items();
    foreach( QGraphicsItem * item, list ){
        scene->removeItem(item);
    }
}

tileTypes mapView::getTileColor(QString name){
    if(name == "Free"){
        return tileTypes::Free;
    }else if(name == "Blocked"){
        return tileTypes::Blocked;
    }else if(name == "Mixed"){
        return tileTypes::Mixed;
    }else{
        return tileTypes::Unknown;
    }
}

void mapView::increaseScale(){
    scale += 0.2f;
    QRect newRect(0, 0, windowWidth * scale, windowHeight * scale);
    scene->setSceneRect(newRect);
}

void mapView::decreaseScale(){
    scale -= 1;
    QRect newRect(0, 0, windowWidth * scale, windowHeight * scale);
    scene->setSceneRect(newRect);
    std::cout << "w " << scene->width() << " h " << scene->height() << std::endl;
}

int mapView::getScale(){
    return scale;
}

void mapView::rescale(){
    clear();
    QRect newRect(0, 0, windowWidth * scale, windowHeight * scale);
    scene->setSceneRect(newRect);
    std::cout << "w " << scene->width() << " h " << scene->height() << std::endl;
}

void mapView::wheelEvent(QWheelEvent *event)
    {
        int num = event->delta();
        std::cout << "delta: "<< num<< std::endl;
        std::cout<< "wheel pos" << event->pos().x() << std::endl;
        fflush(stdout);
    }

bool mapView::mouseInMapView(){
        QPoint p = view->mapFromGlobal(QCursor::pos());
        if(p.x() < view->size().width() && p.x()>0 && p.y() < view->size().height() && p.y()>0) {return true;}
        return false;
    }


bool mapView::event(QEvent *event)
{
        std::cout << "woop"<< mouseInMapView() <<std::endl;
        std::cout<<"map view event type"<< event->type()<<std::endl;
        fflush(stdout);
    return QWidget::event(event);
}
