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

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_HPP
