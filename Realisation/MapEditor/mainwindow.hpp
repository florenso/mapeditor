#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionRoboRescue_wiki_triggered();

    void on_actionSave_as_triggered();

    void on_actionLoad_triggered();

   // void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_zoomInButton_clicked();

    void on_zoomOutButtom_clicked();

  //  void on_inputX_cursorPositionChanged(int arg1, int arg2);

  //  void on_inputY_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_HPP
