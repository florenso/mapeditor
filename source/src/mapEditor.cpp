#include "mapEditor.hpp"

mapEditor::mapEditor(QWidget *parent) : mapView(parent)
    {
        //construct new editor
    }

void mapEditor::createTile(){
    //create new Tile
}

void mapEditor::removeTile(){
    //Remove Tile
}

void mapEditor::editTile(){
    //edit Tile
}

Map mapEditor::getBuffer(){
    return saveBuffer;
}
