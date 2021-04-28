#include "blockmodel.h"

blockModel::blockModel(QGraphicsItem * parent):QGraphicsItem(parent),height(120),width(100)
{

}

void blockModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec=boundigRect();
    QBrush brush(Qt::red);
    painter->fillRect(rec,brush);
    painter->drawRect(rec);
}
/*
void blockModel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<< "extra kek";
    QGraphicsItem::mousePressEvent(event);
}
*/
QRectF blockModel::boundigRect()const
{
    return QRectF(0,0,height,width);
}


