#include "../include/mapEditor.hpp"


mapEditor::mapEditor(QWidget *parent) :
    mapView(parent)
    {
        //saveBuffer = RectInfo_from_map_using_tiles(map, 50, 50);
    }

void mapEditor::createTile(){
    //create new Tile

}

void mapEditor::removeTile(){
    //Remove Tile
}

void mapEditor::editTile(QString type){

    //set new boxInfo
    r2d2::BoxInfo info;
    if(type == "Navigatable"){
        info = r2d2::BoxInfo(false, false, true);
    }else if(type == "Obstacle"){
        info = r2d2::BoxInfo(true, false, false);
    }else{
        info = r2d2::BoxInfo(false, true, false);
    }

    //store temporary tile
    for(r2d2::Box * tile: selectedBoxes){
        //const std::pair<tile, info>;
        saveBuffer.push_back(std::pair<r2d2::Box *, r2d2::BoxInfo>(tile, info));
    }

    std::cout << "Saved Tiles: " << saveBuffer.size() << std::endl;
}

void mapEditor::displayEdit(){
    int tileSize=10;
    scene->clearSelection();
    for(std::pair<r2d2::Box *, r2d2::BoxInfo> box: saveBuffer){
        //drawBox here
        /*qreal xPosition = box.first->get_bottom_left().get_x();
        qreal yPosition = box.first->get - tileSize;*/
        scene->drawTile(static_cast<int>(box.first->get_bottom_left().get_x()), static_cast<int>(box.first->get_bottom_left().get_y() - tileSize), getTileType(box.second) );
    }

    r2d2::Translation tileSizeTranslation(r2d2::Length::CENTIMETER * tileSize,
                                          r2d2::Length::CENTIMETER * tileSize,
                                          r2d2::Length::CENTIMETER * 0);



}

//std::vector<std::pair<r2d2::Box, r2d2::BoxInfo>> mapEditor::getBuffer(){
//    return saveBuffer;
//}
