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
    verticalScrollBar()->installEventFilter(this);
    horizontalScrollBar()->installEventFilter(this);
    setMouseTracking(true);

    scene->clear();
    scene->addOriginOffset(250,250);
    centerOn(QPointF(0,0)+scene->getOriginOffset());
}

mapView::~mapView(){
    delete scene;
}

void mapView::setSelectable(bool state){
    for(QGraphicsItem * item: items()){
        if(scene->isTile(item)){
            item->setFlag(QGraphicsItem::ItemIsSelectable, state);
        }
    }
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
    scaleSize = (maxScale / 2);
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

void mapView::set_z_bottom(float value)
{
    z_bottom = value;
}

void mapView::set_z_top(float value){
    z_top = value;
}


void mapView::setZoomSpeed(qreal speed){
    zoomSpeed = speed;
}

void mapView::deselectTiles(){
    for(QGraphicsItem * tile : scene->selectedItems()){
        tile->setSelected(false);
    }
}

void mapView::updateSelection(){
    selectedBoxes.clear();
    //QPoint offset = scene->getOriginOffset();
    //std::cout << offset.x() << std::endl;
    for(QGraphicsItem * item : scene->selectedItems()){
        //get coordinates of bottom left (bl) and top right (tr)
        QPointF pos = item->pos();
        QRectF rect = item->boundingRect();
        int width = rect.width();
        int height = rect.height();

        /* code from scene that gives insight why this doesn't work
         * (box.get_bottom_left().get_x()/r2d2::Length::CENTIMETER)+originOffset.x(),
         * ((box.get_bottom_left().get_y()/r2d2::Length::CENTIMETER)*-1)+originOffset.y(),
         * (box.get_axis_size().get_x()/r2d2::Length::CENTIMETER),
         * (box.get_axis_size().get_y()/r2d2::Length::CENTIMETER)*-1);
         */

        //QPointF bottomLeft(item->pos().x() - offset.x(), (item->pos().y() - offset.y()) - height);
        //QPointF topRight(item->pos().x() - offset.x() + width, (item->pos().y() - offset.y()));
        /*QPointF bottomLeft(rect.bottomLeft());

        QPointF topRight(rect.topRight());
        r2d2::Box box(
            r2d2::Coordinate(r2d2::Length::CENTIMETER * bottomLeft.x(),
                             r2d2::Length::CENTIMETER * bottomLeft.y(),
                             r2d2::Length::CENTIMETER * 0),
            r2d2::Coordinate(r2d2::Length::CENTIMETER * topRight.x(),
                             r2d2::Length::CENTIMETER * topRight.y(),
                             r2d2::Length::CENTIMETER * 1)
            );
        //std::cout << "item: " << bottomLeft.x() << "x" << bottomLeft.y() << " : " << topRight.x() <<"x"<< topRight.y() << std::endl;
        */
        r2d2::Coordinate leftBottom = scene->qpoint_2_box_coordinate(QPointF(pos.x(), pos.y() - height), 0);
        r2d2::Coordinate rightTop = scene->qpoint_2_box_coordinate(QPointF(pos.x() + width, pos.y()), 1);
        r2d2::Box box(leftBottom, rightTop);
        selectedBoxes.append(box);
    }
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
    }

void mapView::loadMapFile(string file)
    {
        map = new r2d2::BoxMap;
        map->load(file);
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

void mapView::drawBox(r2d2::Box box,int tileSize){
        int xAxisMin = round(box.get_bottom_left().get_x()/r2d2::Length::CENTIMETER);
        int yAxisMin = round(box.get_bottom_left().get_y()/r2d2::Length::CENTIMETER);
        int xAxisMax = round(box.get_top_right().get_x()/r2d2::Length::CENTIMETER);
        int yAxisMax = round(box.get_top_right().get_y()/r2d2::Length::CENTIMETER);
        r2d2::Translation tileSizeTranslation(r2d2::Length::CENTIMETER * tileSize,
                                              r2d2::Length::CENTIMETER * tileSize,
                                              r2d2::Length::CENTIMETER * z_top);
        int dis = abs(xAxisMin-xAxisMax);
        for (int x = xAxisMin; x < xAxisMax; x+=tileSize){
            for(int y = yAxisMin; y < yAxisMax; y+=tileSize){
                    r2d2::Coordinate bottemLeft{r2d2::Length::CENTIMETER * x,
                                    r2d2::Length::CENTIMETER * y,
                                    r2d2::Length::CENTIMETER * z_bottom};
                    r2d2::Box tileBox(bottemLeft,tileSizeTranslation);
                    r2d2::BoxInfo tileInfo = map->get_box_info(tileBox);
                    scene->drawTile(tileBox,tileColors[getTileType(tileInfo)]);
                }
            int loadingPercentage = (((float)x-(float)xAxisMin)/(float)dis)*100;
            //std::cout << "loading "<< loadingPercentage << "%"<<std::endl;
            }
        centerOn(scene->getOriginOffset());
        scene->drawAxes();
    }



void mapView::drawMap(){
        scene->clear();
        resetScale();
        scene->addOriginOffset(250,250);
        centerOn(QPointF(0,0)+scene->getOriginOffset());

        //this is not almost working code...
//        QPointF startPoint = mapToScene(QPoint(0,0));
//        QPointF endPoint = mapToScene(QPoint(width(),height()));
//        const r2d2::Coordinate bottemLeft1{
//                        r2d2::Length::CENTIMETER * ceil(((scene->getOriginOffset().x() - startPoint.x()+10)*-1)/10)*10,
//                        r2d2::Length::CENTIMETER * ceil((scene->getOriginOffset().y() - endPoint.y()-10)/10)*10,
//                        r2d2::Length::CENTIMETER * z_bottom};
//        const r2d2::Translation boxSize{
//                        r2d2::Length::CENTIMETER * (width()/2),
//                        r2d2::Length::CENTIMETER * (height()/2),
//                        r2d2::Length::CENTIMETER * z_top};

        const r2d2::Coordinate bottemLeft1{
                        r2d2::Length::CENTIMETER * -400,
                        r2d2::Length::CENTIMETER * -400,
                        r2d2::Length::CENTIMETER * z_bottom};
        const r2d2::Translation boxSize{
                        r2d2::Length::CENTIMETER * 800,
                        r2d2::Length::CENTIMETER * 800,
                        r2d2::Length::CENTIMETER * z_top};



        drawBox(r2d2::Box(bottemLeft1,boxSize));;
    }


