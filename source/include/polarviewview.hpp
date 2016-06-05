#ifndef POLARVIEWVIEW_HPP
#define POLARVIEWVIEW_HPP
#include "mapView.hpp"
#include "Angle.hpp"
#include "DistanceReading.hpp"
#include "Coordinate.hpp"
#include "Translation.hpp"
#include "math.h"
#include "viewScene.hpp"

class polarviewView : public mapView
    {
public:
    explicit polarviewView(QWidget *parent = 0);






    void showPolarView(std::map<r2d2::Angle, DistanceReading> polarview,r2d2::Coordinate coordinate);

    };



#endif // POLARVIEWVIEW_HPP
