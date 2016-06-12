#ifndef POLARVIEWTAB_HPP
#define POLARVIEWTAB_HPP

#include <QMainWindow>
#include <QWidget>
#include "MapPolarView.hpp"
#include "polarview.hpp"
#include "Angle.hpp"
#include "mapView.hpp"
#include "DistanceReading.hpp"
#include <forward_list>
#include "ui_polarViewTab.h"
#include "PolarViewAggregator.hpp"
#include "SensorAggregator.hpp"

namespace Ui {
    class polarViewTab;
    }

class polarViewTab : public QWidget
    {
    Q_OBJECT

public:
    explicit polarViewTab(mapView * MapViewQGS, QWidget *parent = 0);

    ~polarViewTab();

    void showPolarView(r2d2::MapPolarView polarview,r2d2::Coordinate centerCoordinate, QColor color = Qt::blue);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

private:
    Ui::polarViewTab *ui;
    mapView * mapViewer;


    r2d2::Coordinate trans1{60*r2d2::Length::CENTIMETER,30*r2d2::Length::CENTIMETER,0*r2d2::Length::CENTIMETER};
    r2d2::Coordinate trans2{-60*r2d2::Length::CENTIMETER,30*r2d2::Length::CENTIMETER,0*r2d2::Length::CENTIMETER};
    std::unique_ptr<r2d2::MapPolarView> testpolar1{new r2d2::MapPolarView};
    std::unique_ptr<r2d2::MapPolarView> testpolar2;


    };

#endif // POLARVIEWTAB_HPP
