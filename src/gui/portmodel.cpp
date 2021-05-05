#include "portmodel.h"

portModel::portModel(port * coreRepr,int yOfset):yOfset(yOfset),coreRepr(coreRepr)
{
     if(coreRepr->type==port::Pin){
         xOfset=5;
     }
     else{
         xOfset=160;
     }
}

QRectF portModel::boundingRect() const
{
    return QRectF(0,0,15,15);
}

void portModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen border(Qt::black, 2);

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
    if(coreRepr->type==port::Pin){
        painter->drawEllipse(rect);
    }
    else{
        painter->drawEllipse(rect);
    }
}

void portModel::move()
{
    setPos((coreRepr->inBlock->x)+xOfset,(coreRepr->inBlock->y)+yOfset);
}

