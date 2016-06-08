#ifndef POLARVIEWTAB_HPP
#define POLARVIEWTAB_HPP

#include <QMainWindow>
#include <QWidget>
#include "polarview/polarView.hpp"
#include "polarview.hpp"
#include "Angle.hpp"
#include "mapView.hpp"

namespace Ui {
    class polarViewTab;
    }

class polarViewTab : public QWidget
    {
    Q_OBJECT

public:
    explicit polarViewTab(mapView * MapViewQGS, QWidget *parent = 0);

    ~polarViewTab();

    void showPolarView(std::map<r2d2::Angle, r2d2::DistanceReading> polarview,r2d2::Coordinate centerCoordinate, QColor color = Qt::blue);


private slots:
    void on_pushButton_clicked();

private:
    Ui::polarViewTab *ui;
    mapView * mapViewer;
    };

#endif // POLARVIEWTAB_HPP
