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
    /**
     * slot for deleting the layout when deleting button is pressed
     */
   void destructButt();
   /**
    * updating name from core repr.
    */
   void cheangeName();
   /**
    * updating value type from core repr.
    */
   void cheangeValType();
private:
    QLineEdit * lineEdit;
    QComboBox * comboBox;
    port * corePtr;
    QVBoxLayout * mainLayout;
    bool deletedGraphic;
    /**
     * delete all layout assigned to port
     */
    void deleteElements();
    /**
     * updating combobox from core reptr.
     */
    void setComboBox();
};

#endif // PORTLAYOUT_H
