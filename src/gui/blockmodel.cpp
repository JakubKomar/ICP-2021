#include "blockmodel.h"
#include <QDebug>
blockModel::blockModel()
{
    setFlag(ItemIsMovable);
    qDebug()<<"model created";
}

blockModel::~blockModel()
{
    qDebug()<<"model deleted";
}

QRectF blockModel::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void blockModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::red, 3);
    painter->setPen(pen);
    painter->drawEllipse(rect);

}

void blockModel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"fuuu";
}

void blockModel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
