#ifndef MAPEDITOR_HPP
#define MAPEDITOR_HPP

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "mapView.hpp"

class MapEditor : public mapView
    {
    Q_OBJECT
public:
    explicit MapEditor(QWidget *parent = 0);

signals:

public slots:
    };

#endif // MAPEDITOR_HPP
