#pragma once

#include <rand>
#include <time>

class Box {
public:
    Box(Coordinate bottomLeft, Coordinate topRight) : bottomLeft(bottomLeft), topRight(topRight) {}
    Coordinate getTopRight() {
        return topRight;
    }
    Coordinate getBottomLeft() {
        return bottomLeft;
    }
private:
    Coordinate bottomLeft;
    Coordinate topRight;
}

class BoxInfo {
public:
    BoxInfo(bool has_unknown, bool, has_obstacles, bool has_navigatable) : has_unknown(has_unknown), has_obstacles(has_obstacles), has_navigatable(has_navigatable) {}
    const bool has_unknown;
    const bool has_obstacles;
    const bool has_navigatable;
}

class Coordinate {
public:
    Box(double x, double y, double z) : x(x), y(y), z(z) {}
    double get_x() {return x;}
    double get_y() {return y;}
    double get_z() {return z;}
private:
    double x, y, z;
}

class Map {
public:
    Map();
    BoxInfo get_box_info(Box box) {
        std::srand(std::time(0))
        int getal = std::rand() % 3;
        switch(getal) {
            case 0: {
                return BoxInfo(true, false false)
            },
            case 1: {
                return BoxInfo(false, true false)
            },
            case 2: {
                return BoxInfo(true, false true)
            }
        }
    }
}
