#include "viewScene.hpp"

viewScene::viewScene(QObject *parent) : QGraphicsScene(parent)
    {
        tileColors[MapTypes::TileType::EMPTY]=Qt::white;
        tileColors[MapTypes::TileType::BLOCKED]=Qt::black;
        tileColors[MapTypes::TileType::MIXED]=Qt::yellow;
        tileColors[MapTypes::TileType::UNKNOWN]=Qt::gray;
    }

void viewScene::drawTile(int x, int y, int width, int height, QColor color){
    std::cout << "New tile: x " << x << " y " << y << " w " << width << " h " << height<< std::endl;
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, width, height);
    block->setBrush(* new QBrush(color));
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

MapTypes::TileType viewScene::getTileColor(QString name){
    if(name == "Free"){
        return MapTypes::TileType::EMPTY;
    }else if(name == "Blocked"){
        return MapTypes::TileType::BLOCKED;
    }else if(name == "Mixed"){
        return MapTypes::TileType::MIXED;
    }else{
        return MapTypes::TileType::UNKNOWN;
    }
}

void viewScene::drawMap(Map &map){
    std::vector<std::vector<RectInfo> > rectList = RectInfo_from_map_using_tiles(map, 50, 50);
    for (int y = 0; y <= rectList.size()-1; y++){
        for(int x = 0; x <= rectList[y].size()-1; x++){
            RectInfo current = rectList[y][x];

            Coordinate left_up = current.get_left_up();
            Coordinate right_down = current.get_right_down();
            //std::cout<<"De current: " << tileColors[current.get_state()];
            drawTile((int)left_up.get_x(), (int)left_up.get_y(), (int)(right_down.get_x() - left_up.get_x()),
                                        (int)(left_up.get_y() - right_down.get_y()), tileColors[current.get_state()] );
        }

    }
}
