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
        //drawTile(-10,-10,20,20,QColor(100,0,0));
        delete (xAxis);
        delete (yAxis);
        xAxis = addLine(0,originOffset.y(),width(),originOffset.y());
        yAxis = addLine(originOffset.x(),0,originOffset.x(),height());
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

void viewScene::drawTile(int x, int y, int width, int height, QColor color){
        y*=-1;
        height*=-1;
    //std::cout << "New tile: x " << x << " y " << y << " w " << width << " h " << height<< std::endl;
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, width, height);
    block->setBrush(* new QBrush(color));
    block->setFlag(QGraphicsItem::ItemIsSelectable, true);
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
}

//remove only the selected items
void viewScene::deleteSelectedItems(){
    QList<QGraphicsItem *> list = selectedItems();
    foreach( QGraphicsItem * item, list ){
        removeItem(item);
    }
}
