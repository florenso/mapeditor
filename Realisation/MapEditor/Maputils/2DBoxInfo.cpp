#include "2DBoxInfo.hpp"

2DBoxInfo::2DBoxInfo(Coordinate up, Coordinate down, TileType new_state){
    left_up = up;
    right_down = down;
    state = new_state;
}
2DBoxInfo::2DBoxInfo(Box box, TileType new_state) {
    int deltax = box.getTopRght().get_x() - box.getBottomLeft().get_x();
    int deltay = box.getTopRght().get_y() - box.getBottomLeft().get_y();
    left_up = Coordinate(box.getBottomLeft() + deltax, box.getBottomLeft().getY(), 0);
    right_down = Coordinate(box.getTopRight().get_x(), box.getTopRight().get_y() - deltay, 0);
    state = new_state;
}
