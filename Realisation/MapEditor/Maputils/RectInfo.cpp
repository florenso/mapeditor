#include "RectInfo.hpp"

RectInfo::RectInfo(Coordinate up, Coordinate down, TileType new_state){
    left_up = up;
    right_down = down;
    state = new_state;
}

RectInfo::RectInfo(Coordinate bottomLeft, int sizex,  int sizey, TileType new_state){
    left_up = Coordinate(bottomLeft.get_x(), bottomLeft.get_y() - sizey, 0);
    right_down = Coordinate(bottomLeft.get_x() + sizex, bottomLeft.get_y());
    state = new_state;
}

RectInfo::RectInfo(Box box, TileType new_state) {
    int deltax = box.getTopRight().get_x() - box.getBottomLeft().get_x();
    int deltay = box.getBottomLeft().get_y() - box.getTopRight().get_y();
    left_up = Coordinate(box.getBottomLeft() + deltax, box.getBottomLeft().getY(), 0);
    right_down = Coordinate(box.getTopRight().get_x(), box.getTopRight().get_y() - deltay, 1); //Higher, so we actually get data later :I
    state = new_state;
}
