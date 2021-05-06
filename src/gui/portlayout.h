/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Grup of widget for ports editing
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
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
#include  "./core/portsocket.h"
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
