/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Graphic reprezentation of blocks
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#ifndef BLOCKMODEL_H
#define BLOCKMODEL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDrag>

#include "./core/block.h"
#include "./core/port.h"
#include "./gui/portmodel.h"
class blockModel : public QGraphicsItem
{
public:
    blockModel(block * coreRep,int x,int y);
    ~blockModel();
    /**
     * bounding rectangle
     * @return bounding rectangle
    */
    QRectF boundingRect() const;
    /**
     * drawing block model
    */
    void paint(QPainter * painter,const QStyleOptionGraphicsItem * option,QWidget * widget);
    /**
     * resizing the block model
     * @param newWidth
     * @param newHeight
    */
    void resize();
    /**
     * geting name from core of block
     * @return name of block
    */
    QString getName();
    /**
     * geting id from core of block
     * @return id of block
    */
    int getId();
    /**
     * geting pointer from core reprezentation
     * @return pointer to core rep
    */
    block * getCrPtr();
protected:
private:
    void displayPorts();
    int height;
    int width;
    block * coreRepr;
    QList<portModel*>inputsModels;
    QList<portModel*>outputsModels;
};

#endif // BLOCKMODEL_H
