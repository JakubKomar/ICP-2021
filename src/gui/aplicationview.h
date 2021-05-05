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

#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
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
    void cleanScene();
    void loadScene(compozit * CompPtr);
    void swichEditedComp(compozit *targetPtr);
protected:
    bool conectMod;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;  
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QGraphicsLineItem * actualConnection{nullptr};
    QVector<blockModel*>blockModels;
    mainWindow * mainUi;
signals:

};

#endif // APLICATIONVIEW_H
