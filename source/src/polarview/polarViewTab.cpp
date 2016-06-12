#include "polarViewTab.hpp"



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
        mapViewer->scene->clear();

        (&testpolar1)->~MapPolarView();
        new (&testpolar1) r2d2::MapPolarView();
        (&testpolar2)->~MapPolarView();
        new (&testpolar2) r2d2::MapPolarView();

        for( int a = 0; a < 20; a = a + 1 )
        {
                testpolar1.add_distancereading(r2d2::Angle((rand()%360)*r2d2::Angle::deg),r2d2::DistanceReading(
                                                   (rand()%100+10)*r2d2::Length::CENTIMETER,
                                                   r2d2::DistanceReading::ResultType::CHECKED));
                testpolar2.add_distancereading(r2d2::Angle((rand()%360)*r2d2::Angle::deg),r2d2::DistanceReading(
                                                   (rand()%100+10)*r2d2::Length::CENTIMETER,
                                                   r2d2::DistanceReading::ResultType::CHECKED));
        }

        showPolarView(testpolar1,trans1);
        showPolarView(testpolar2,trans2);

}

void polarViewTab::showPolarView(r2d2::MapPolarView polarview, r2d2::Coordinate centerCoordinate, QColor color)
    {
        for (const pair<r2d2::Angle, r2d2::DistanceReading> & pv : polarview.get_distances() )
        {
            if (pv.second.get_result_type() == r2d2::DistanceReading::ResultType::CHECKED){

                r2d2::Coordinate PolarPoint(centerCoordinate+r2d2::Translation{
                                                pv.second.get_length()*cos(pv.first/r2d2::Angle::rad),
                                                pv.second.get_length()*sin(pv.first/r2d2::Angle::rad),
                                                0*r2d2::Length::CENTIMETER
                                                });

                std::pair<r2d2::Angle, r2d2::DistanceReading> tmp(pv);
                //std::cout<<"Angle: " << tmp.first.get_angle() <<"rad, dis: " << tmp.second.get_length()/r2d2::Length::CENTIMETER << std::endl;
                //std::cout << "x: " << PolarPoint.get_x()/r2d2::Length::CENTIMETER << ", y: " << PolarPoint.get_y()/r2d2::Length::CENTIMETER << std::endl;

                mapViewer->scene->drawLine(centerCoordinate,PolarPoint,color);

            }
        }
}

void polarViewTab::on_pushButton_2_clicked()
{

    mapViewer->scene->clear();

    std::forward_list<std::pair<const r2d2::MapPolarView&,const r2d2::Coordinate &>> fw_polar_list;
    fw_polar_list.push_front( std::pair<const r2d2::MapPolarView &,
                             const r2d2::Coordinate &>(testpolar1,trans1));
    fw_polar_list.push_front( std::pair<const r2d2::MapPolarView &,
                             const r2d2::Coordinate &>(testpolar2,trans2));

    showPolarView(r2d2::PolarViewAggregator::aggregate_polarviews(fw_polar_list),r2d2::Coordinate::origin);
}

void polarViewTab::on_pushButton_3_clicked()
{
        mapViewer->scene->clear();
        showPolarView(testpolar1,trans1);
        showPolarView(testpolar2,trans2);
}
