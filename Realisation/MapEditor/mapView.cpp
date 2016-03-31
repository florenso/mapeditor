#include "mapView.hpp"
#include <iostream>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QScrollBar>
#include <QInputEvent>


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
    view->show();
    tileType[QString("free")]=Qt::green;
    tileType[QString("blocked")]=Qt::red;
    tileType[QString("unkown")]=Qt::black;
    view->verticalScrollBar()->installEventFilter(this);
    view->horizontalScrollBar()->installEventFilter(this);


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
 *
 */


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

bool mapView::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::Wheel)
    {
        if (object == view->verticalScrollBar()){//catch
            QWheelEvent* we = static_cast<QWheelEvent*>(event);
            int num = we->delta();
            std::cout << "delta: "<< num<< std::endl;
            fflush(stdout);
            return true;
            }
        else if(object == view->horizontalScrollBar()){//catch horizontal scroll
                return true;}
    }
    return false;
}

