#include "map_utils.hpp"

std::vector<RectInfo> RectInfo_from_map_using_tiles(Map map, Box size) {
    std::vector<RectInfo> boxes;
    sizex = size.getTopRight().get_x() - size.getBottomLeft.get_x();
    sizey = size.getTopRight().get_y() - size.getBottomLeft.get_y();
    sizez = size.getTopRight().get_z() - size.getBottomLeft.get_z();

    Box origin_box(Coordinate(0,0,0), Coordinate(sizex, sizey, sizez))

    Box aabb = map.get_bounding_box(); //Axis Aligned Bounding Box
    totalx = aabb.getTopRight().get_x() - aabb.getBottomLeft.get_x();
    totaly = aabb.getTopRight().get_y() - aabb.getBottomLeft.get_y();
    totalz = aabb.getTopRight().get_z() - aabb.getBottomLeft.get_z();

    for (y = 0; y < (totaly / sizey); y++) {
            for (x = 0; y < (totalx / sizex); x++) {
                BoxInfo info = map.get_box_info();
                int i = 0;
                std::map<std::string, std::string> animals;
                if (info.has_navigatable) i++;
                if (info.has_unknown) i++;
                if (info.has_obstacles) i++;

                if (i > 1) {
                    //Smaller resolution
                }
                else {
                    int x_l = sizex * x;
                    int y_l = sizey * y;
                    int x_r = (x + 1) * sizex;
                    int y_r = (y + 1) * sizey
                    int z_r = sizez;

                    TileType new_type = TileType::None;
                    if (info.has_navigatable) new_type = TileType::EMPTY;
                    if (info.has_unknown) new_type = TileType::UNKNOWN;
                    if (info.has_obstacles) new_type = TileType::BLOCKED;

                    Box new_box = Box(Coordinate(x_l, y_l, 0),
                                    Coordinate(x_r, y_r, z_r))
                    boxes.push_back(RectInfo(new_box, new_type);
                }
            }
    }

}
