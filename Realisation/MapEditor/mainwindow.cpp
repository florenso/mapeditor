

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    viewer = new mapView(ui->graphicsView, 1000, 1000);

    viewer->drawTile(10,10,10,10,"blocked");
    viewer->drawTile(10,10,10,10,"blocked");
    viewer->clear();
    viewer->drawTile(10,100,100,1000,"unkown");
    viewer->drawTile(900,100,100,1000,"unkown");
    viewer->drawTile(200,10,10,10,"free");
    viewer->setTag(100, 100, QString("Hallo! Dit is een test"));

    //hijacking scrolbar events
    ui->graphicsView->verticalScrollBar()->installEventFilter(this);
    ui->graphicsView->horizontalScrollBar()->installEventFilter(this);
    //install event filter for graphicsView
    ui->graphicsView->installEventFilter(this);
    ui->graphicsView->setMouseTracking(true);
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
        return QWidget::event(event);

        //::cout<<"mainWindow event type"<< event->type()<<std::endl;
        if (event->type() == QEvent::MouseButtonPress){
                QPoint p = ui->graphicsView->mapFromGlobal(QCursor::pos());
                //QPoint p = viewer->view->mapFromGlobal(QCursor::pos());
                std::cout << "mouse pos: x"<< p.x() << " y" <<p.y()<<std::endl;
                ui->xposLabel->setText(QString::number(p.x()));
                ui->yposLabel->setText(QString::number(p.y()));

                if (viewer->mouseInMapView(p)){

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

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    switch(event->type()){

        case QEvent::Wheel:
            if (object == ui->graphicsView->verticalScrollBar()){//catch
                QWheelEvent* we = static_cast<QWheelEvent*>(event);
                int num = we->delta();
                std::cout << "delta: "<< num<< std::endl;
                fflush(stdout);
                return true;
                }
            else if(object == ui->graphicsView->horizontalScrollBar()){//catch horizontal scroll
                return true;}
            break;

        case QEvent::MouseMove:
            {
            QMouseEvent* me = static_cast<QMouseEvent*>(event);
            if(viewer->mouseInMapView(me->pos())){
                ui->xposLabel->setText(QString::number(me->pos().x()));
                ui->yposLabel->setText(QString::number(me->pos().y()));
            } else if(true) {ui->graphicsView->releaseMouse();
                std::cout << "leaving view" << std::endl;
                }
            }
            break;
        case QEvent::MouseButtonPress:
            {QPoint p = ui->graphicsView->mapFromGlobal(QCursor::pos());
            std::cout << "mouse press @ pos: x"<< p.x() << " y" <<p.y()<<std::endl;
            fflush(stdout);}
            break;
        case QEvent::Enter:
            {
            std::cout << "succecvol enter " << object << std::endl;
            if(! ui->actionPan->isChecked()){
                ui->graphicsView->grabMouse();}
            }
            break;
        default:
            std::cout << "mapview event filter event type " << event->type() << std::endl;
            fflush(stdout);
            break;
        }
    fflush(stdout);
    return QWidget::eventFilter(object,event);
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

void MainWindow::on_placeTagButton_clicked()
{
    int x = ui->xposTag->value();
    int y = ui->yposTag->value();

    QString tag(ui->tagName->text());
    viewer->setTag(x, y, tag);
}

void MainWindow::on_clearButton_clicked()
{
    viewer->clear();
}

void MainWindow::on_actionSave_triggered()
{

}

