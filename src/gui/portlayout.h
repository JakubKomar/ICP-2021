#ifndef PORTLAYOUT_H
#define PORTLAYOUT_H

#include <QGraphicsItem>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <qdebug.h>
#include <QComboBox>
#include  "ui_mainwindow.h"
#include  "./core/port.h"
#include  "./gui/blockmodel.h"
class portLayout: public QObject
{
    Q_OBJECT
public:
    portLayout(QWidget * place,port * corePtr);
    ~portLayout();
public slots:
   void destructButt();
   void cheangeName();
   void cheangeValType();
private:
    QLineEdit * lineEdit;
    QComboBox * comboBox;
    port * corePtr;
    QVBoxLayout * mainLayout;
    bool deletedGraphic;
    void deleteElements();
    void setComboBox();
};

#endif // PORTLAYOUT_H
