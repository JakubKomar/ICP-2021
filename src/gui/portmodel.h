#ifndef PORTMODEL_H
#define PORTMODEL_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include "./core/port.h"

class portModel : public QGraphicsItem
{
public:
    portModel(port * coreRepm,int yOfset);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int yOfset{0};
    int xOfset{0};
    int xBindingOfs{7};
    int yBindingOfs{7};
public slots:
    void move();
private:
    port * coreRepr;
    QRectF boundingRect() const;

};

#endif // PORTMODEL_H
