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

private:
    Ui::MainWindow *ui;

    void on_actionR2d2_triggered();
    void on_actionRoboRescue_wiki_triggered();
    void on_actionLoad_triggered();
    void on_actionSave_as_triggered();
};

#endif // MAINWINDOW_HPP
