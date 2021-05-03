#include "portmodel.h"

portModel::portModel(port * coreRepr):coreRepr(coreRepr)
{

}
QRectF portModel::boundingRect() const
{
    return QRectF(0,0,80,30);
}
void portModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen border(Qt::black, 1);

    if(coreRepr->valType==port::Vint){
        painter->setBrush(Qt::green);
    }
    else if(coreRepr->valType==port::Vbool)
    {
        painter->setBrush(Qt::red);
    }
    else if(coreRepr->valType==port::Vstring)
    {
        painter->setBrush(Qt::darkMagenta);
    }
    else
         painter->setBrush(Qt::blue);

    painter->setPen(border);
    painter->drawEllipse(0,0,30,30);
    painter->drawText(30,0,coreRepr->getName());
}
