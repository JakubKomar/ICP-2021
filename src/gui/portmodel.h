#ifndef PORTMODEL_H
#define PORTMODEL_H

#include <QGraphicsItem>
#include <QPainter>
#include "./core/port.h"
class portModel : public QGraphicsItem
{
public:
    portModel(port * coreRep);

private:
    port * coreRepr;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PORTMODEL_H
