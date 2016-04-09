#include "../include/mapView.hpp"
#include <iostream>
#include <QMouseEvent>
#include <QScrollBar>
#include <QInputEvent>
#include <QEnterEvent>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QCoreApplication>
#include <QKeyEvent>
#include <QtGui>
#include <QMutex>

QMutex EventRecursion;


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
        tileColors[MapTypes::TileType::EMPTY]=Qt::white;
        tileColors[MapTypes::TileType::BLOCKED]=Qt::black;
        tileColors[MapTypes::TileType::MIXED]=Qt::yellow;
        tileColors[MapTypes::TileType::UNKNOWN]=Qt::gray;


    scene = new viewScene;

    std::cout << "new Viewer with size: " << windowWidth << " x " << windowHeight << std::endl;
    scene->setSceneRect( 0, 0, windowWidth, windowHeight);
    setScene(scene);
    //editor = new mapEditor(this);
    show();

    //set default scale
    resetScale();
    scene->installEventFilter(this);

    scene->drawAxes();
    verticalScrollBar()->installEventFilter(this);
    horizontalScrollBar()->installEventFilter(this);
    setMouseTracking(true);
}

mapView::~mapView(){
    delete scene;
}


void mapView::increaseScale(){
    scaleSize += zoomSpeed;
    if(scaleSize > maxScale){

        scaleSize = maxScale;
    }

    updateTransform();
    //checkSceneBorder();
}

void mapView::decreaseScale(){
    scaleSize -= zoomSpeed;
    if(scaleSize < minScale){
        scaleSize = minScale;

    }
    updateTransform();
    //checkSceneBorder();
}

int mapView::getScale(){
    float normalizer = maxScale / 1;
    // multiply with 200 to make center of the scale range 100%
    return (scaleSize / normalizer) * 200;
}

void mapView::resetScale(){
    scaleSize = (maxScale / 2) - minScale;
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

void mapView::setZoomSpeed(qreal speed){
    zoomSpeed = speed;
}

void mapView::selectTiles(QList<QGraphicsItem *> items){
    for(QGraphicsItem * item : items){
        std::cout << "Item: " << item->pos().x() << " x " << item->pos().y() << std::endl;
    }
}

void mapView::deselectTiles(){
    for(QGraphicsItem * tile : scene->selectedItems()){
        tile->setSelected(false);
    }
}

QList<RectInfo *> mapView::updateSelection(){
    QList selection;
    for(QGraphicsItem * item : scene->selectedItems()){
        int x = item->pos().x();
        int y = item->pos().y();
        int w = item->boundingRect().width();
        int h = item->boundingRect().height();
        std::cout << "item: " << x << y << w << h << std::endl;
        //selection.append();
    }
    return selection;
}

bool mapView::event(QEvent *event)
{
        switch(event->type()){


                case QEvent::KeyPress:{
                    QKeyEvent * ke = static_cast<QKeyEvent*>(event);
                   // std::cout << "key pressed in @ event filter in mainwindow " << ke->key() << std::endl;
                        if(ke->key() == Qt::Key_Down){
                                int val = verticalScrollBar()->value();
                                verticalScrollBar()->setValue(val+scrollStepSize);
                            }
                        else if(ke->key() == Qt::Key_Up){
                                int val = verticalScrollBar()->value();
                                verticalScrollBar()->setValue(val-scrollStepSize);
                            }
                        else if(ke->key() == Qt::Key_Right){
                                int val = horizontalScrollBar()->value();
                                horizontalScrollBar()->setValue(val+scrollStepSize);
                            }
                        else if(ke->key() == Qt::Key_Left){
                                int val = horizontalScrollBar()->value();
                                horizontalScrollBar()->setValue(val-scrollStepSize);
                            }
                        //checkSceneBorder();
                    break;}

                default:
            break;
            }
        //std::cout<<"map view event type"<< event->type()<<std::endl;
        //fflush(stdout);
    return QGraphicsView::event(event);
}

void mapView::checkSceneBorder(){
        QPointF startPoint = mapToScene(QPoint(0,0));
        QPointF endPoint = mapToScene(QPoint(width(),height()));
        int stepSize = endPoint.x()-startPoint.x();

        if(startPoint.x() < stepSize && EventRecursion.tryLock()){
           //std::cout << "too close to startPoint.x" << std::endl;
           QPointF center = mapToScene(viewport()->rect().center());
           scene->addOriginOffset(stepSize,0);
           centerOn(QPointF(stepSize,0)+center);//causes an event (recursion)
           EventRecursion.unlock();

        }
        if(startPoint.y() < stepSize && EventRecursion.tryLock()){
            //std::cout << "too close to startPoint.y" << std::endl;
            QPointF center = mapToScene(viewport()->rect().center());
            scene->addOriginOffset(0,stepSize);
            centerOn(QPointF(0,stepSize)+center);//causes an event (recursion)
            EventRecursion.unlock();
        }
        if(endPoint.x() > (scene->width() - stepSize)){
           //std::cout << "too close to endPoint.x" << std::endl;
           scene->setSceneRect(0,0,scene->width() + stepSize, scene->height());
           scene->drawAxes();
        }

        if(endPoint.y() > (scene->height() - stepSize)){
            //std::cout << "too close to endPoint.y" << std::endl;
            scene->setSceneRect(0,0,scene->width(), scene->height()+stepSize);
            scene->drawAxes();
        }
        //std::cout<< "scene size: " << scene->width() << " " << scene->height() << std::endl;
    }

void mapView::loadMapFile(string file)
    {
        //delete(map);
        map = new r2d2::BoxMap;
        int generate_box_count = 1;
        for (int i = 0; i < generate_box_count; i++) {
            map->set_box_info(
                    r2d2::Box{
                            r2d2::Coordinate{
                                    ((rand() % 20)-10) * r2d2::Length::METER,
                                    ((rand() % 20)-10) * r2d2::Length::METER,
                                    r2d2::Length::METER
                            },
                            r2d2::Coordinate{
                                    ((rand() % 20)-10) * r2d2::Length::METER,
                                    ((rand() % 20)-10) * r2d2::Length::METER,
                                    r2d2::Length::METER
                            }
                    },
                    //r2d2::BoxInfo{rand() % 2 == 0, rand() % 2 == 0, rand() % 2 == 0}
                        r2d2::BoxInfo{true,false,false}
            );
        }
        drawMap();
    }

bool mapView::eventFilter(QObject * object, QEvent * event){
        //return true if you want to stop the event from going to other objects
        //return false if you you do not want to kill the event.
        //event filter order parent->child->child'sChild->etc...

        checkSceneBorder();


    switch(event->type()){

       case QEvent::GraphicsSceneDragEnter:{
         std::cout << "MOVED THE SCENE";
         break;

       }

       case QEvent::Wheel:

           if (object == verticalScrollBar()){//catch
               QWheelEvent* we = static_cast<QWheelEvent*>(event);
               int num = we->delta();
               if(num < 0){
                   decreaseScale();
               }else{
                   increaseScale();
               }
               return true;
               }
           else if(object == horizontalScrollBar()){//catch horizontal scroll
               return true;}
           break;
       case QEvent::GraphicsSceneMouseMove:
           {
           //NOTE: this will give scene pos without the offset (aka, not real map pos)
           //Example code for scene mouse pos:
           //QGraphicsSceneMouseEvent * gsme = static_cast<QGraphicsSceneMouseEvent*>(event);
           //std::cout<< "mouse pos in scene is: x" << gsme->scenePos().x() << " y" << gsme->scenePos().y() << std::endl;

           return true;
           break;
           }

        default:
            break;
    }
    return false;
}

MapTypes::TileType mapView::getTileType(r2d2::BoxInfo & tileInfo){
    bool nav = tileInfo.get_has_navigatable();
    bool obs = tileInfo.get_has_obstacle();
    bool unk = tileInfo.get_has_unknown();
    if(nav && !obs && !unk){
        return MapTypes::TileType::EMPTY;}
    else if (!nav && obs && !unk){
            return MapTypes::TileType::BLOCKED;}
    else if (!nav && !obs && unk){
            return MapTypes::TileType::UNKNOWN;}
    else{return MapTypes::TileType::MIXED;}
}



void mapView::drawMap(){
        scene->drawTile(-100,-100,200,200,Qt::green);
        int tileSize=10;
        //TODO:clear scene
        r2d2::Box map_bounding_box = map->get_map_bounding_box();
        //double test = map_bounding_box.get_top_right().get_x()/r2d2::Length::CENTIMETER;
        int xAxisMin = round(map_bounding_box.get_bottom_left().get_x()/r2d2::Length::CENTIMETER);
        int yAxisMin = round(map_bounding_box.get_bottom_left().get_y()/r2d2::Length::CENTIMETER);
        int xAxisMax = round(map_bounding_box.get_top_right().get_x()/r2d2::Length::CENTIMETER);
        int yAxisMax = round(map_bounding_box.get_top_right().get_y()/r2d2::Length::CENTIMETER);
        //TODO: set new origin offset in viewScene::draw stuff when out of scene
        //scene->setNewOriginOffset(abs(xAxisMin),abs(yAxisMin));
        r2d2::Translation tileSizeTranslation(r2d2::Length::CENTIMETER * tileSize,
                                              r2d2::Length::CENTIMETER * tileSize,
                                              r2d2::Length::CENTIMETER * 0);
        std::cout << "map size " << xAxisMin << std::endl;
        for (int x = xAxisMin; x < xAxisMax; x+=tileSize){
            for(int y = yAxisMin; y < yAxisMax; y+=tileSize){
                    //std::cout << "new tile @ x"<< x << " y"<<y<<std::endl;
                    r2d2::Coordinate topRight{r2d2::Length::CENTIMETER * x,
                                    r2d2::Length::CENTIMETER * y,
                                    r2d2::Length::CENTIMETER * 0};
                    r2d2::Box tileBox(topRight,tileSizeTranslation);
                    r2d2::BoxInfo tileInfo = map->get_box_info(tileBox);
                    scene->drawTile(x,y,tileSize,tileSize,tileColors[getTileType(tileInfo)]);
                }
            std::cout << "new tile row @ x"<< x <<std::endl;
            }
    }
//    std::vector<std::vector<RectInfo> > rectList = RectInfo_from_map_using_tiles(map, 50, 50);
//    for (int y = 0; y <= rectList.size()-1; y++){
//        for(int x = 0; x <= rectList[y].size()-1; x++){
//            RectInfo current = rectList[y][x];

//            Coordinate left_up = current.get_left_up();
//            Coordinate right_down = current.get_right_down();
//            //std::cout<<"De current: " << tileColors[current.get_state()];
//            drawTile((int)left_up.get_x(), (int)left_up.get_y(), (int)(right_down.get_x() - left_up.get_x()),
//                                        (int)(left_up.get_y() - right_down.get_y()), tileColors[current.get_state()] );
//        }

//    }
//}
