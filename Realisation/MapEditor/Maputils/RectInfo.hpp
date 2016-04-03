#pragma once

#include "stubs.hpp"
#include <vector>

class RectInfo {
private:
    Coordinate left_up, right_down;
    TileType state;
    std::vector<RectInfo> children;
public:
    RectInfo(Coordinate pos, int sizex, int sizey, TileType new_state);
    RectInfo(Coordinate up, Coordinate down, TileType state);
    RectInfo(Box box, TileType state);

    TileType get_state() {
        return state;
    }

    Box get_box() {
        return Box(left_up, right_down)
    }

    Coordinate get_left_up() {
        return left_up;
    }

    Coordinate get_right_down() {
        return right_down;
    }

    TileType set_type(TileType new_state) {
        state = new_state
    }

    std::vector<RectInfo> get_rekt() {
        return children;
    }

    void add_rekt(RectInfo child) {
        children.push_back(child);
    }

};
