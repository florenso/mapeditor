#include "viewScene.hpp"

viewScene::viewScene(QObject *parent) : QGraphicsScene(parent)
    {
        tileColors[tileTypes::Free]=Qt::green;
        tileColors[tileTypes::Blocked]=Qt::red;
        tileColors[tileTypes::Mixed]=Qt::yellow;
        tileColors[tileTypes::Unknown]=Qt::black;
    }

void viewScene::drawTile(int x, int y, int width, int height, QString type){
    std::cout << "New tile: x " << x << " y " << y << " w " << width << " h " << height << std::endl;
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, width, height);
    block->setBrush(* new QBrush(tileColors[getTileColor(type)]));
    block->setPos(x, y);
    addItem(block);
}

void viewScene::drawLine(int x1, int y1, int x2, int y2, QRgb color){
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
    QGraphicsTextItem *item = addText(value);
    item->setPos(x,y);
}

void viewScene::clear(){
    QList<QGraphicsItem *> list = items();
    foreach( QGraphicsItem * item, list ){
        removeItem(item);
    }
}

tileTypes viewScene::getTileColor(QString name){
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
