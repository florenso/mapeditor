#include "mapView.hpp"
#include <iostream>


mapView::mapView(QWidget *parent):
    QGraphicsView(parent),
    windowWidth(1000),
    windowHeight(1000)
{
    /*//if no height or with given, set to view size

    if(width == 0){
      windowWidth = width();
    }
    if(height == 0){
        windowHeight = height();
    }
    */
    scene = new QGraphicsScene;
    std::cout << "new Viewer with size: " << windowWidth << " x " << windowHeight << std::endl;
    scene->setSceneRect( 0, 0, windowWidth, windowHeight);
    setScene(scene);
    show();

    //set default scale
    resetScale();

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
    block->setRect(0, 0, width, height);
    block->setBrush(* new QBrush(tileColors[getTileColor(type)]));
    block->setPos(x, y);
    scene->addItem(block);
}

void mapView::drawLine(int x1, int y1, int x2, int y2, QRgb color){
    //Bad method needs rework
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, x2-x1, y2-y1);
    block->setBrush(* new QBrush(color));
    block->setPos(x1, y1);
    scene->addItem(block);
    setScene(scene);
    show();
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

void mapView::increaseScale(qreal inc){
    if(!(scaleSize > maxScale)){
        scaleSize += inc;
    }
    updateTransform();
}

void mapView::decreaseScale(qreal dec){
    scaleSize -= dec;
    if(scaleSize < minScale){
        scaleSize = minScale;

    }
    updateTransform();
}

int mapView::getScale(){
    return scaleSize * 200;
}

void mapView::resetScale(){
    scaleSize = 0.5f;
    updateTransform();
}

void mapView::increaseRotation(int inc){
    rotation = (rotation + inc) % 360;
    updateTransform();
}

void mapView::decreaseRotation(int dec){
    if(rotation == 0){
        rotation = 360 - dec;
    }else{
        rotation -= dec;
    }
    updateTransform();
}

int mapView::getRotation(){
    return rotation;
}

void mapView::resetRotation(){
    rotation = 0;
    updateTransform();
}

void mapView::updateTransform(){
    resetTransform();
    rotate(rotation);
    scale(scaleSize, scaleSize);
}

void mapView::setZoomSpeed(int speed){
    zoomSpeed = speed;
}

/*  void mapView::drawMap(RectInfo *map){
 *      for (int i = 0; i <= len(map); i++;){
 *          Box box = new Box;
 *          box = map->get_2D_Box()
 *          Coordinate left_up = map->get_left_up();
 *          Coordinate right_down = map->get_right_down();
 *          drawTile(left_up.get_x(), left_up.get_y(), right_down.get_x() - left_up.get_x(),
 *                   left_up.get_y() - right_down_y(), map->get_state );
 *          }
 *  }
 */


bool mapView::mouseInMapView(QPoint p){
    //QPoint p = mapFromGlobal(QCursor::pos());
    if(p.x() <= size().width() && p.x()>=0 && p.y() <= size().height() && p.y()>=0) {return true;}
    return false;
}

bool mapView::event(QEvent *event)
{
        //std::cout<<"map view event type"<< event->type()<<std::endl;
        //fflush(stdout);
    return QObject::event(event);
}
