#ifndef PORTLAYOUT_H
#define PORTLAYOUT_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QObject>
#include <qdebug.h>
#include <QComboBox>
#include  "ui_mainwindow.h"
#include  "./core/port.h"
class portLayout
{
public:
    portLayout(QWidget * place,port * corePtr);
    ~portLayout();
private:
    port * corePtr;
    QVBoxLayout * mainLayout;
};

#endif // PORTLAYOUT_H
