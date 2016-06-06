#include "polarViewTab.hpp"
#include "ui_polarViewTab.h"


polarViewTab::polarViewTab(mapView * MapViewQGS, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::polarViewTab)
    {
        mapViewer = MapViewQGS;
        ui->setupUi(this);
    }

polarViewTab::~polarViewTab()
    {
        delete ui;
    }


void polarViewTab::on_pushButton_clicked()
{
        std::map<r2d2::Angle, r2d2::DistanceReading> testpolar;
        for( int a = 0; a < 20; a = a + 1 )
        {
                testpolar.insert(std::pair<r2d2::Angle, r2d2::DistanceReading>(
                                     r2d2::Angle((rand()%360)*r2d2::Angle::deg),
                                     r2d2::DistanceReading((rand()%100+10)*r2d2::Length::CENTIMETER,r2d2::DistanceReading::ResultType::CHECKED)
                                     ));
        }

        std::map<r2d2::Angle, r2d2::DistanceReading> testpolar2;
        for( int a = 0; a < 20; a = a + 1 )
        {
                testpolar2.insert(std::pair<r2d2::Angle, r2d2::DistanceReading>(
                                     r2d2::Angle((rand()%360)*r2d2::Angle::deg),
                                     r2d2::DistanceReading((rand()%100+10)*r2d2::Length::CENTIMETER, r2d2::DistanceReading::ResultType::CHECKED)
                                     ));
        }

        showPolarView(testpolar,r2d2::Coordinate(-30*r2d2::Length::CENTIMETER,0*r2d2::Length::CENTIMETER,0*r2d2::Length::CENTIMETER));
        showPolarView(testpolar2,r2d2::Coordinate(30*r2d2::Length::CENTIMETER,0*r2d2::Length::CENTIMETER,0*r2d2::Length::CENTIMETER));

}

void polarViewTab::showPolarView(std::map<r2d2::Angle, r2d2::DistanceReading> polarview, r2d2::Coordinate centerCoordinate)
    {
        {
            for (const pair<r2d2::Angle, r2d2::DistanceReading> & pv : polarview )
            {
                r2d2::DistanceReading dr(pv.second);
                if (dr.get_result_type() == r2d2::DistanceReading::ResultType::CHECKED){

                    r2d2::Coordinate PolarPoint(centerCoordinate+r2d2::Translation{
                                                    dr.get_length()*sin(pv.first/r2d2::Angle::deg),
                                                    dr.get_length()*cos(pv.first/r2d2::Angle::deg),
                                                    0*r2d2::Length::CENTIMETER
                                                    });

                    mapViewer->scene->drawLine(centerCoordinate,PolarPoint,Qt::blue);

                }
            }
    }
}
