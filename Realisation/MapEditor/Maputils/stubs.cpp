
class Box {
public:
    Box(Coordinate bottomLeft, Coordinate topRight);
    Coordinate getTopRight();
    Coordinate getBottomLeft();
private:
    Coordinate bottomLeft;
    Coordinate topRight;
}


class BoxInfo {
public:
    BoxInfo(bool has_unknown, bool, has_obstacles, bool has_navigatable);
    const bool has_unknown;
    const bool has_obstacles;
    const bool has_navigatable;
}

class Coordinate {
public:
    Coordinate(double x, double y, double z);
    double get_x();
    double get_y();
    double get_z();
private:
    double x, y, z;
}
