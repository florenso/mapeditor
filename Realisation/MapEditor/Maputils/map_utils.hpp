#include "RectInfo.hpp"

#ifndef MAPUTILS
#define MAPUTILS

RectInfo[][] RectInfo_grid_from_map(Map map, int amountx, int amounty);
std::vector<RectInfo> RectInfo_from_map_using_tiles(Map map);
RectInfo get_rectinfo_recursive(Map map, Box total, RectInfo& parent)

#endif /* end of include guard:  */
