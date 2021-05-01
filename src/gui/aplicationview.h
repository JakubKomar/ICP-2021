/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Graphic board-here is drawed blocks
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
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
    /**
     * adding graphic reprezentation of block
     * @param x - x axis pozition
     * @param y - y axis pozition
     * @param block - pointer to core reprezentation
    */
    void addGrapicRepr(int x,int y,block * coreRep);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;  
    QVector<blockModel*>blockModels;
    mainWindow * mainUi;
signals:

};

#endif // APLICATIONVIEW_H
