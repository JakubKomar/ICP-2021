#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QObject>
#include <qdebug.h>
mainWindow::mainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    scene= new aplicationView(ui->apkView);
    ui->apkView->setScene(scene);
    ui->compoziteView->setScene(scene);
    this->curentApk=NULL;
}

mainWindow::~mainWindow()
{
    delete ui;
    if(curentApk)
        delete curentApk;
}

//----------debug buttons---------
void mainWindow::on_pushButton_2_clicked()
{
    ui->screenSwitch->setCurrentIndex( (ui->screenSwitch->currentIndex())-1 );
}

void mainWindow::on_pushButton_clicked()
{
    ui->screenSwitch->setCurrentIndex( (ui->screenSwitch->currentIndex())+1 );
}
//------------------------------

void mainWindow::on_newApk_clicked()
{
    if(curentApk!=NULL)
        delete curentApk;
    this->curentApk=new aplication;
}

void mainWindow::on_loadApk_clicked()
{
    if(curentApk!=NULL)
        delete curentApk;
    this->curentApk=new aplication;
}

void mainWindow::on_apkAddAtom_clicked()
{
    if(curentApk!=NULL)
    {
        atomic * pointer=curentApk->addAtom();
        scene->addGrapicRepr(0,0,pointer);
    }
}

void mainWindow::on_pushButton_4_clicked()
{
    if(curentApk!=NULL)
    {
          curentApk->firstSays();
    }
}
