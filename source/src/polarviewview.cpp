#include "../include/polarviewview.hpp"

polarviewView::polarviewView(QWidget *parent) :
    mapView(parent)
    {
    }

void polarviewView::showPolarView(std::map<r2d2::Angle, DistanceReading> polarview, r2d2::Coordinate centerCoordinate)
    {
        for (const pair<r2d2::Angle, DistanceReading> & pv : polarview )
        {
            DistanceReading dr(pv.second);
            if (dr.get_result_type() == DistanceReading::ResultType::CHECKED){

                r2d2::Coordinate PolarPoint(centerCoordinate+r2d2::Translation{
                                                dr.get_length()*sin(pv.first/r2d2::Angle::deg),
                                                dr.get_length()*cos(pv.first/r2d2::Angle::deg),
                                                0*r2d2::Length::CENTIMETER
                                                });

                scene->drawLine(centerCoordinate,PolarPoint,Qt::red);

            }
        }
    }
