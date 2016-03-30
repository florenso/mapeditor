#pragma once
/* Half pseudocode because of the absense of Map and Box*/

class enum TileType {
    BLOCKED, UNKNOWN, NAVIGATABLE
}

class 2DBoxInfo {
    Coordinate left_up, right_down;
    State state;
public:
    2DBoxInfo(Coordinate up, Coordinate down, TileType state)
    2DBoxInfo(Box box, TileType state)

    TileType get_state() {
        return state;
    }

    Box get_2D_Box() {
        return Box(first, second)
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

}
