#include "portmodel.h"

portModel::portModel(port * coreRepr,int yOfset):yOfset(yOfset),coreRepr(coreRepr)
{
     if(coreRepr->type==port::Pin){
         xOfset=5;
         xBindingOfs=7;
     }
     else{
         xOfset=110;
         xBindingOfs=55;
     }
}


QRectF portModel::boundingRect() const
{
    return QRectF(0,0,60,30);
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
        painter->drawEllipse(0,0,15,15);
        painter->drawText(20,10,coreRepr->getName());
    }
    else{
        painter->drawEllipse(50,0,15,15);
        painter->drawText(0,10,coreRepr->getName());
    }
}

void portModel::move()
{
    setPos((coreRepr->inBlock->x)+xOfset,(coreRepr->inBlock->y)+yOfset);
}

