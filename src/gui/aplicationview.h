#ifndef APLICATIONVIEW_H
#define APLICATIONVIEW_H

#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>
#include "blockmodel.h"
#include "./core/atomic.h"
#include "./core/compozit.h"
#include "./mainwindow.h"
class mainWindow;
class aplicationView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit aplicationView(QObject *parent = nullptr,mainWindow *mainUi=nullptr);
    ~aplicationView();
    void addGrapicRepr(int x,int y,block * coreRep);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;  
    QVector<blockModel*>blockModels;
    mainWindow * mainUi;

signals:

};

#endif // APLICATIONVIEW_H
