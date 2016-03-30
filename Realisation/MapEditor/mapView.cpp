#include "mapView.hpp"
#include <iostream>
#include <QWheelEvent>
#include <QMouseEvent>

mapView::mapView(QWidget *parent, QGraphicsView * view):
    view(view)

{
    scene = new QGraphicsScene;
    scene->setSceneRect( 0, 0, 400, 400);
    view->setScene(scene);
    tileType[QString("free")]=Qt::green;
    tileType[QString("blocked")]=Qt::red;
    tileType[QString("unkown")]=Qt::black;

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
