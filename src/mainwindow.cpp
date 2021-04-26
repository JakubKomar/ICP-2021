#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QObject>
#include <qdebug.h>
mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    auto *scene= new aplicationView(ui->apkView);
    ui->apkView->setScene(scene);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_pushButton_2_clicked()
{
    ui->screenSwitch->setCurrentIndex( (ui->screenSwitch->currentIndex())-1 );
}

void mainWindow::on_pushButton_clicked()
{
    ui->screenSwitch->setCurrentIndex( (ui->screenSwitch->currentIndex())+1 );
}

