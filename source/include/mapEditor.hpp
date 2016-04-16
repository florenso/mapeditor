#ifndef MAPEDITOR_HPP
#define MAPEDITOR_HPP

//this class contains functions to edit a map (this does not call draw functions for the map, only for ghosting purposes)

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "mapView.hpp"
//#include "stubs.hpp"

class mapEditor : public mapView
    {
    Q_OBJECT
public:
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
