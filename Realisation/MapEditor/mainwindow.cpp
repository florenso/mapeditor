#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QFileDialog>
#include <QUrl>
#include <QString>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    viewer = new mapView(parent, ui->graphicsView, 1000, 1000);
    //ui->mousePos->setStyleSheet("background-color:grey;");
    viewer->drawTile(10,10,10,10,"Blocked");
    viewer->drawTile(10,10,10,10,"Blocked");
    viewer->clear();
    viewer->drawTile(10,100,100,1000,"Unknown");
    viewer->drawTile(900,100,100,1000,"Unknown");
    viewer->drawTile(200,10,10,10,"Free");
    viewer->setTag(200, 10, QString("20deg"));
    viewer->setTag(100, 100, QString("Hallo! Dit is een test"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete viewer;
}


void MainWindow::on_actionRoboRescue_wiki_triggered()
{
    QString link = "https://www.roborescue.nl";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_actionSave_as_triggered()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.exec();
}

void MainWindow::on_actionLoad_triggered()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.exec();
}

//void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
//{
// commented to avoid linker error "Unused parameter"
//}

void MainWindow::on_zoomInButton_clicked()
{

}

void MainWindow::on_zoomOutButtom_clicked()
{

}

bool MainWindow::event(QEvent *event)
{
        //::cout<<"mainWindow event type"<< event->type()<<std::endl;
        if (event->type() == QEvent::MouseButtonPress){
                QPoint p = ui->graphicsView->mapFromGlobal(QCursor::pos());
                //QPoint p = viewer->view->mapFromGlobal(QCursor::pos());
                std::cout << "mouse pos: x"<< p.x() << " y" <<p.y()<<std::endl;
                ui->xposLabel->setText(QString::number(p.x()));
                ui->yposLabel->setText(QString::number(p.y()));
                if (viewer->mouseInMapView()){
                std::cout << "mouse click is in viewer"  <<std::endl;}
                else {std::cout << "mouse click is not in viewer"  <<std::endl;}
            }
        fflush(stdout);
    return QWidget::event(event);
}

void MainWindow::on_actionPan_toggled(bool activatePan)
{
    if(activatePan){
            ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
            printf("drag hand\n");
            fflush(stdout);
        }
    else{
            ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
            printf("select cursor\n");
            fflush(stdout);
        }
    }

void MainWindow::wheelEvent(QWheelEvent *event)
    {
        if (viewer->mouseInMapView()){
            int num = event->delta();
            printf("delta: %d \n",num);
            fflush(stdout);
        }
    }


//void MainWindow::on_inputX_cursorPositionChanged(int arg1, int arg2)
//{
// commented to avoid linker error "Unused parameter"
//}

//void MainWindow::on_inputY_cursorPositionChanged(int arg1, int arg2)
//{
// commented to avoid linker error "Unused parameter"
//}

//testcode
void MainWindow::on_pushButton_clicked()
{
    int x = ui->xpos->value();
    int y = ui->ypos->value();
    int w = ui->width->value();
    int h = ui->Height->value();

    QString type(ui->type->currentText());
    viewer->drawTile(x, y, w, h, type);
}
