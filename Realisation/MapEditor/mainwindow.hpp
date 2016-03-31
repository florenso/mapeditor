#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "mapView.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool event(QEvent *event);
    void wheelEvent(QWheelEvent *event);
private slots:
    void on_actionRoboRescue_wiki_triggered();

    void on_actionSave_as_triggered();

    void on_actionLoad_triggered();

   // void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_zoomInButton_clicked();

    void on_zoomOutButtom_clicked();

  //  void on_inputX_cursorPositionChanged(int arg1, int arg2);
  //  void on_inputY_cursorPositionChanged(int arg1, int arg2);


    //
    // drag (pan) for the map viewer
    //
    void on_actionPan_toggled(bool);

private:
    Ui::MainWindow *ui;
    mapView *viewer;

};

#endif // MAINWINDOW_HPP
