#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QGraphicsView>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionPan_triggered()
{
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    printf("drag hand\n");
    fflush(stdout);

}

void MainWindow::on_actionSelect_triggered()
{
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    printf("select cursor\n");
    fflush(stdout);
}
