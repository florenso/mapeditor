#include "polarViewTab.hpp"
#include "ui_polarViewTab.h"
#include "PolarViewAggregator.hpp"


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

        r2d2::Coordinate origin(0*r2d2::Length::CENTIMETER,0*r2d2::Length::CENTIMETER,0*r2d2::Length::CENTIMETER);
        r2d2::Translation trans(60*r2d2::Length::CENTIMETER,30*r2d2::Length::CENTIMETER,0*r2d2::Length::CENTIMETER);


        std::map<r2d2::Angle, r2d2::DistanceReading> testpolar;
        for( int a = 0; a < 20; a = a + 1 )
        {
                testpolar.insert(std::pair<r2d2::Angle, r2d2::DistanceReading>(
                                     r2d2::Angle((rand()%360)*r2d2::Angle::deg),
                                     r2d2::DistanceReading(
                                         (rand()%100+10)*r2d2::Length::CENTIMETER,
                                         r2d2::DistanceReading::ResultType::CHECKED)
                                     ));
        }



        std::map<r2d2::Angle, r2d2::DistanceReading> testpolar2  = r2d2::PolarViewAggregator().translate_base_polarview(testpolar,trans);
//        for( int a = 0; a < 20; a = a + 1 )
//        {
//                testpolar2.insert(std::pair<r2d2::Angle, r2d2::DistanceReading>(
//                                     r2d2::Angle((rand()%360)*r2d2::Angle::deg),
//                                     r2d2::DistanceReading((rand()%100+10)*r2d2::Length::CENTIMETER, r2d2::DistanceReading::ResultType::CHECKED)
//                                     ));
//        }

        showPolarView(testpolar,origin+trans);
        showPolarView(testpolar2,origin,Qt::green);

}

void polarViewTab::showPolarView(std::map<r2d2::Angle, r2d2::DistanceReading> polarview, r2d2::Coordinate centerCoordinate, QColor color)
    {
        {
            for (const pair<r2d2::Angle, r2d2::DistanceReading> & pv : polarview )
            {
                if (pv.second.get_result_type() == r2d2::DistanceReading::ResultType::CHECKED){

                    r2d2::Coordinate PolarPoint(centerCoordinate+r2d2::Translation{
                                                    pv.second.get_length()*cos(pv.first/r2d2::Angle::rad),
                                                    pv.second.get_length()*sin(pv.first/r2d2::Angle::rad),
                                                    0*r2d2::Length::CENTIMETER
                                                    });

                    std::pair<r2d2::Angle, r2d2::DistanceReading> tmp(pv);
                    std::cout<<"Angle: " << tmp.first.get_angle() <<"rad, dis: " << tmp.second.get_length()/r2d2::Length::CENTIMETER << std::endl;
                    std::cout << "x: " << PolarPoint.get_x()/r2d2::Length::CENTIMETER << ", y: " << PolarPoint.get_y()/r2d2::Length::CENTIMETER << std::endl;

                    mapViewer->scene->drawLine(centerCoordinate,PolarPoint,color);

                }
            }
    }
}
