//**************************************
//! Class responsible for dispaying all the UI elements
//! \authors
//! 	- Daniel Klomp
//!		- Jop van Buuren
//!     - Koen de Guijter
//!     - jessy Visch
//!
//! \context
//!		- part of TH7-8 assignment 2016 / Project: MapEditer
//**************************************

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
//#include "mapView.hpp"
#include "mapEditor.hpp"
#include "stubs.hpp"
#include <QDesktopServices>
#include <QFileDialog>
#include <QUrl>
#include <QString>
#include <iostream>
#include <QMouseEvent>
#include <QScrollBar>
#include <QInputEvent>
#include <QEnterEvent>
#include <QEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! Constructor for MainWindow.
    explicit MainWindow(QWidget *parent = 0);

    //! Deconstructor for MainWindow.
    ~MainWindow();

protected:
    //! Catches all events and returns true when a event is caught.
    bool eventFilter(QObject *object, QEvent *event);
private slots:

    //! Opens the RoboRescue wiki page on click.
    void on_actionRoboRescue_wiki_triggered();

    //! Saves the edited map of a location of choice.
    void on_actionSave_as_triggered();

    void on_actionLoad_triggered();

   // void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_zoomInButton_clicked();

    void on_zoomOutButtom_clicked();

  //  void on_inputX_cursorPositionChanged(int arg1, int arg2);
  //  void on_inputY_cursorPositionChanged(int arg1, int arg2);


    //! Enables the drag mode for the map viewer
    void on_actionPan_toggled(bool);

    void on_pushButton_clicked();

    void on_placeTagButton_clicked();

    void on_clearButton_clicked();

    void on_actionSave_triggered();


    void on_zoomResetButton_clicked();

    void on_rotateLeftButton_clicked();

    void on_rotateRightButton_clicked();

    void on_resetRotationButton_clicked();

    void on_zoomSpeedSlider_valueChanged(int value);

    void on_actionSelectMode_toggled(bool arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
