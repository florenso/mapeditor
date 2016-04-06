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
    tileColors[MapTypes::TileType::EMPTY]=Qt::white;
    tileColors[MapTypes::TileType::BLOCKED]=Qt::black;
    tileColors[MapTypes::TileType::MIXED]=Qt::yellow;
    tileColors[MapTypes::TileType::UNKNOWN]=Qt::gray;
}

mapView::~mapView(){
    delete view;
    delete scene;
}

void mapView::drawTile(int x, int y, int width, int height, QColor color){
    std::cout << "New tile: x " << x << " y " << y << " w " << width << " h " << height<< std::endl;
    QGraphicsRectItem *block = new QGraphicsRectItem;
    block->setRect(0, 0, width, height);
    block->setBrush(* new QBrush(color));
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

MapTypes::TileType mapView::getTileColor(QString name){
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

void mapView::drawMap(Map &map){
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
    std::cout<<"De functie uitgaan werkt ook";
}


bool mapView::mouseInMapView(QPoint p){
        //QPoint p = mapFromGlobal(QCursor::pos());
        if(p.x() <= size().width() && p.x()>=0 && p.y() <= size().height() && p.y()>=0) {return true;}
        return false;
    }

bool mapView::event(QEvent *event)
{
        std::cout<<"map view event type"<< event->type()<<std::endl;
        fflush(stdout);
    return QObject::event(event);
}
