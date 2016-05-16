//! \addtogroup 0008 Mapviewer/-editor
//! \brief Functions for Viewing and navigating a loaded map
//!
//! this class extends QGraphicsScene (the qt Scene class).
//! The viewScene handels all the visual objects in the QGraphicsView.
//! It translates the the map coordinates to scene coordinated and back.
//! This is done because the Y axis is fliped and the scene cannot draw in negative coordinates.
//!
//! \file   viewScene.hpp
//! \author Koen de Guijter, 1671103
//!         Jop van Buuren, 1658718
//!         Daniel Klomp, 1661521
//! \date   Created: 30-03-2016
//! \date   Last Modified: 16-05-2016
//! \brief  Header for viewScene
//!
//! This is the header file for viewScene
//!
//! \copyright Copyright © 2016, HU University of Applied Sciences Utrecht.
//! All rights reserved.
//!
//! License: newBSD
//!
//! Redistribution and use in source and binary forms,
//! with or without modification, are permitted provided that
//! the following conditions are met:
//! - Redistributions of source code must retain the above copyright notice,
//!   this list of conditions and the following disclaimer.
//! - Redistributions in binary form must reproduce the above copyright notice,
//!   this list of conditions and the following disclaimer in the documentation
//!   and/or other materials provided with the distribution.
//! - Neither the name of the HU University of Applied Sciences Utrecht
//!   nor the names of its contributors may be used to endorse or promote
//!   products derived from this software without specific prior written
//!   permission.
//!
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
//! BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
//! AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
//! IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
//! BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//! PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
//! OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
//! WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
//! OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
//! EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ~< HEADER_VERSION 2016 04 12 >~

#ifndef VIEWSCENE_HPP
#define VIEWSCENE_HPP

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <map>
#include <iostream>
#include <map>
#include <QPoint>
#include <QPen>
#include "Box.hpp"
#include "Coordinate.hpp"
#include "Translation.hpp"
#include "Length.hpp"

class viewScene : public QGraphicsScene
    {
    Q_OBJECT

private:

    QPoint originOffset{0,0};

    QGraphicsLineItem * xAxis = addLine(0,0,0,0);
    QGraphicsLineItem * yAxis = addLine(0,0,0,0);


public:

    void drawAxes();
    QPoint getOriginOffset();

    void addOriginOffset(int unsigned x, int unsigned y);

    void setNewOriginOffset(int unsigned xOffset,int unsigned yOffset);

    explicit viewScene(QObject *parent = 0);

    //! Draws a line from position x1,y1 to position x2,y2 on the scene.
    void drawLine(int x1, int y1, int x2, int y2, QRgb color);

    //! Draws a the text value on the scene on position x,y.
    void setTag(int x, int y, QString value);

    //! delete selected items
    void deleteSelectedItems();

    //! Clears all the objects in the scene.
    void clear();

    void drawTile(r2d2::Box box, QColor color);

    bool isTile(QGraphicsItem * item);

    void setTag(r2d2::Coordinate pos, QString value);

    QPointF box_coordinate_2_qpoint(r2d2::Coordinate);
    QRectF box_tile_2_qrect(r2d2::Box box);
    r2d2::Coordinate qpoint_2_box_coordinate(QPointF point, double z = 0);
    r2d2::Box qrect_2_box_coordinate(QRectF rect, double min_z = 0, double max_z = 1);
signals:

public slots:


    };

#endif // VIEWSCENE_HPP
