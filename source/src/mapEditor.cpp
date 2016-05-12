#include "../include/mapEditor.hpp"


mapEditor::mapEditor(QWidget *parent) :
    mapView(parent)
    {
    }

void mapEditor::removeTile(){
    editTile(QString("Unknown"));
}

void mapEditor::editTile(QString type){

    //set new boxInfo
    r2d2::BoxInfo info;
    if(type == "Navigatable"){
        info = r2d2::BoxInfo(false, false, true);
    }else if(type == "Obstacle"){
        info = r2d2::BoxInfo(true, false, false);
    }else if(type == "Unknown"){
        info = r2d2::BoxInfo(false, true, false);
    }else{
        info = r2d2::BoxInfo(true, false, true);
    }

    //store

    for(r2d2::Box tile: selectedBoxes){
        saveBuffer.push_back(std::pair<r2d2::Box, r2d2::BoxInfo>(tile, info));
        map->set_box_info(tile, info);
        std:: cout << "write: " << saveBuffer.size() << std::endl;
    }
    scene->deleteSelectedItems();
    deselectTiles();
    std::cout << "Saved Tiles: " << saveBuffer.size() << std::endl;
}

void mapEditor::displayEdit(){
    int tileSize=10;
    scene->clearSelection();

    while(!saveBuffer.empty()){
        std::pair<r2d2::Box, r2d2::BoxInfo> box = saveBuffer.back();
        saveBuffer.pop_back();
        drawBox(box.first, tileSize, false);
    }
    this->setSelectable(true);
}
