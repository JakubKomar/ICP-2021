#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QObject>
#include <QDebug>
#include "myscene.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zoomSlider,&QSlider::valueChanged,this,&MainWindow::zoom);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    auto *scene= new MyScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    auto rect = scene->addRect(100,100,100,100,QPen({Qt::black},3),QBrush({Qt::red}));
    rect->setFlag(QGraphicsItem::ItemIsSelectable);
    rect->setFlag(QGraphicsItem::ItemIsMovable);
    auto rect2 = scene->addRect(100,100,100,100,QPen({Qt::black},3),QBrush({Qt::blue}));
    rect2->setFlag(QGraphicsItem::ItemIsSelectable);
    rect2->setFlag(QGraphicsItem::ItemIsMovable);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::zoom(int value)
{
    qreal scale=value/10.0;
    auto org=ui->graphicsView->transform();

    ui->graphicsView->setTransform(QTransform(scale,org.m12(),org.m21(),scale,org.dx(),org.dy()));
}



