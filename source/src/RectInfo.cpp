//#include "../include/RectInfo.hpp"

//RectInfo::RectInfo(Coordinate up, Coordinate down, MapTypes::TileType new_state) :
//    left_up(up),
//    right_down(down),
//    state(new_state)
//{}

//RectInfo::RectInfo(Coordinate bottomLeft, int sizex,  int sizey, MapTypes::TileType new_state) :
//    left_up(Coordinate(bottomLeft.get_x(), bottomLeft.get_y() - sizey, 0)),
//    right_down(Coordinate(bottomLeft.get_x() + sizex, bottomLeft.get_y(), 1)),
//    state(new_state)
//{}

//RectInfo::RectInfo(Box box, MapTypes::TileType new_state) {
//    int deltax = box.getTopRight().get_x() - box.getBottomLeft().get_x();
////    int deltay = box.getBottomLeft().get_y() - box.getTopRight().get_y();
//    left_up = Coordinate(box.getTopRight().get_x() - deltax, box.getTopRight().get_y(), 0);
//    right_down = Coordinate(box.getBottomLeft().get_x() + deltax, box.getBottomLeft().get_y(), 1); //Higher, so we actually get data later :I
//    state = new_state;
//}
