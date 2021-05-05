#ifndef PORTMODEL_H
#define PORTMODEL_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include "./core/port.h"

class port;
class portModel : public QGraphicsItem
{
public:
    portModel(port * coreRepm,int yOfset);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int yOfset{0};
    int xOfset{0};
    int xBindingOfs{7};
    int yBindingOfs{7};
     port * coreRepr;
public slots:
    void move();
private:
    QRectF boundingRect() const;

};

#endif // PORTMODEL_H
