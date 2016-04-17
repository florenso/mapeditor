#ifndef MAPEDITOR_HPP
#define MAPEDITOR_HPP

//this class contains functions to edit a map (this does not call draw functions for the map, only for ghosting purposes)

#include "mapView.hpp"
#include "stubs.hpp"
#include "../../../map/source/include/MapInterface.hpp"


class mapEditor : public mapView
{
public:
    explicit mapEditor(QWidget *parent = 0);
    void createTile();
    void removeTile();
    void editTile(QString type);
    void getBuffer(); //will return map but is disabled for now
    void displayEdit();

signals:

public slots:

private:
    std::vector<std::pair<r2d2::Box, r2d2::BoxInfo> > saveBuffer;
    };

#endif // MAPEDITOR_HPP
