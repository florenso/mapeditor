#ifndef MAPEDITOR_HPP
#define MAPEDITOR_HPP

//this class contains functions to edit a map (this does not call draw functions for the map, only for ghosting purposes)

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "mapView.hpp"
//#include "stubs.hpp"

//! The class that represents a map editor for the r2d2 map.
/*!
 * The mapEditor class represents a mapeditor for the r2d2 map.
 * It extends the mapView class and adds functionality that allows the user
 * to edit the maps as well. It lets the user change tiles to various types,
 * like BLOCKED, NAVIGATABLE or MIXED.
 */
class mapEditor : public mapView
    {
    //Q_OBJECT
public:
    //! Constructor of the mapeditor object
    //! @param parent A pointer to the parent QWidget
    explicit mapEditor(QWidget *parent = 0);
    void createTile();
    void removeTile();
    void editTile();
    //Map getBuffer();
signals:

public slots:

private:
    //Map saveBuffer;
    };

#endif // MAPEDITOR_HPP
