#ifndef PORTLAYOUT_H
#define PORTLAYOUT_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <qdebug.h>
#include <QComboBox>
#include  "ui_mainwindow.h"
#include  "./core/port.h"
class portLayout: public QObject
{
public:
    portLayout(QWidget * place,port * corePtr);
    ~portLayout();
public slots:
   void destructButt();
private:
    port * corePtr;
    QVBoxLayout * mainLayout;
};

#endif // PORTLAYOUT_H
