/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Graphic reprezentation of blocks
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include <QDebug>

#include "blockmodel.h"

blockModel::blockModel(block * coreRep):height(120),width(100),coreRepr(coreRep)
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    qDebug()<<"model created";
}

blockModel::~blockModel()
{
    qDebug()<<"model deleted";
}

QRectF blockModel::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void blockModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen border(Qt::black, 2);
    if(coreRepr->type==block::Tatomic){
        painter->setBrush(Qt::darkGreen);
    }
    else if(coreRepr->type==block::Tcompozit)
    {
        painter->setBrush(Qt::blue);
    }
    else
         painter->setBrush(Qt::red);

    painter->setPen(border);
    painter->drawRoundedRect(rect,20,20);
    if(coreRepr->getName()=="")
        painter->drawText(15,20,QString::number(coreRepr->getId()));
    else
        painter->drawText(15,20,coreRepr->getName());
}

void blockModel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}

void blockModel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

void blockModel::resize(int newWidth, int newHeight)
{
    width=newWidth;
    height=newHeight;
    update();
}

QString blockModel::getName()
{
    if(coreRepr!=NULL)
        return coreRepr->getName();
    else
        return "pt. not connected";
}

int blockModel::getId()
{
    if(coreRepr!=NULL)
        return coreRepr->getId();
    else
        return -2;
}

block *blockModel::getCrPtr()
{
    return coreRepr;
}
