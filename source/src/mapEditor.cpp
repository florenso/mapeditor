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

    for(auto & tile: selectedTiles){
       // RectInfo newTile = new RectInfo(Coordinate tile->pos(), , int sizey, MapTypes::TileType new_state);
    }
}

void mapEditor::getBuffer(){
    //return map;
}
