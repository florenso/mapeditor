#include "../include/viewScene.hpp"

void viewScene::setNewOriginOffset(int unsigned xOffset,int unsigned yOffset)
    {
       QPoint oldOffset = originOffset;
       originOffset.setX(xOffset);
       originOffset.setY(yOffset);
       QPoint relativeOffset = originOffset - oldOffset;
       setSceneRect(0,0,width() + relativeOffset.x(), height() + relativeOffset.y());
       //loop to relocate all items on the scene
       for( auto item : items() ) {
            item->setPos(item->pos()+relativeOffset);
           }
       drawAxes();
    }

void viewScene::drawAxes()
    {
        QPen pen(Qt::red);
        delete xAxis;
        delete yAxis;
        xAxis = addLine(0,originOffset.y(),width(),originOffset.y(),pen);
        yAxis = addLine(originOffset.x(),0,originOffset.x(),height(),pen);
    }

QPoint viewScene::getOriginOffset()
    {
        return originOffset;
    }

void viewScene::addOriginOffset(unsigned int x, unsigned int y)
    {
        setNewOriginOffset(originOffset.x()+x,originOffset.y()+y);
    }

viewScene::viewScene(QObject *parent) : QGraphicsScene(parent)
    {

        //drawAxes();
    }

QPointF viewScene::box_coordinate_2_qpoint(r2d2::Coordinate coordinate){
        return QPointF((coordinate.get_x()/r2d2::Length::CENTIMETER)+originOffset.x(),
        ((coordinate.get_y()/r2d2::Length::CENTIMETER)*-1)+originOffset.y());
    }

QRectF viewScene::box_tile_2_qrect(r2d2::Box box){
        return QRectF(
                    (box.get_bottom_left().get_x()/r2d2::Length::CENTIMETER)+originOffset.x(),
                    ((box.get_bottom_left().get_y()/r2d2::Length::CENTIMETER)*-1)+originOffset.y(),
                    (box.get_axis_size().get_x()/r2d2::Length::CENTIMETER),
                    (box.get_axis_size().get_y()/r2d2::Length::CENTIMETER)*-1);
    }

r2d2::Coordinate viewScene::qpoint_2_box_coordinate(QPointF point, double z){
        return r2d2::Coordinate(
                    (point.x() - getOriginOffset().x())*r2d2::Length::CENTIMETER,
                    (-1*(point.y() - getOriginOffset().y()))*r2d2::Length::CENTIMETER,
                    z*r2d2::Length::CENTIMETER
                    );
    }

r2d2::Box viewScene::qrect_2_box_coordinate(QRectF rect,double min_z,double max_z){

        return r2d2::Box(qpoint_2_box_coordinate(rect.bottomLeft(),min_z),
                         qpoint_2_box_coordinate(rect.topRight(),max_z));
    }

void viewScene::drawTile(r2d2::Box box,QColor color){
    QGraphicsRectItem *block = new QGraphicsRectItem(box_tile_2_qrect(box));
    block->setBrush(* new QBrush(color));
    addItem(block);
    }


void viewScene::drawTile(int x, int y, int width, int height, QColor color){
        std::cout << "you should not use this drawTile method...." << std::endl;
        y*=-1;
        height*=-1;
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, width, height);
    block->setBrush(* new QBrush(color));
    block->setPos(x+originOffset.x(), y+originOffset.y());
    addItem(block);
}

//DOES NOT WORK
void viewScene::drawLine(int x1, int y1, int x2, int y2, QRgb color){
        y1*=-1;
        y2*=-1;
    //Bad method needs rework
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, x2-x1, y2-y1);
    block->setBrush(* new QBrush(color));
    block->setPos(x1, y1);
    addItem(block);
    //setScene(scene);
    //show();
}

void viewScene::setTag(int x, int y, QString value){
        y*=-1;
    QGraphicsTextItem *item = addText(value);
    item->setPos(x+originOffset.x(), y+originOffset.y());
}

void viewScene::clear(){
    QList<QGraphicsItem *> list = items();
    foreach( QGraphicsItem * item, list ){
        removeItem(item);
    }
    drawAxes();
}


