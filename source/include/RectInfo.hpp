//#pragma once

//#include "stubs.hpp"
//#include <vector>

//class RectInfo {
//private:
//    Coordinate left_up, right_down;
//    MapTypes::TileType state;
//    std::vector<RectInfo> children;
//public:
//    RectInfo(Coordinate pos, int sizex, int sizey, MapTypes::TileType new_state);
//    RectInfo(Coordinate up, Coordinate down, MapTypes::TileType state);
//    RectInfo(Box box, MapTypes::TileType state);

//    MapTypes::TileType get_state() {
//        return state;
//    }

//    Box get_box() {
//        return Box(left_up, right_down);
//    }

//    Coordinate get_left_up() {
//        return left_up;
//    }

//    Coordinate get_right_down() {
//        return right_down;
//    }

//    MapTypes::TileType set_type(MapTypes::TileType new_state) {
//        state = new_state;
//    }

//    std::vector<RectInfo> get_rekt() {
//        return children;
//    }

//    void add_rekt(RectInfo child) {
//        children.push_back(child);
//    }

//};
