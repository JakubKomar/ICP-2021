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

blockModel::blockModel(block * coreRep,int x,int y):height(60),width(100),coreRepr(coreRep)
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    this->setPos(x,y);
}

blockModel::~blockModel()
{
    qDebug()<<"blockModel dest";
   foreach(portModel * item,ports){
        delete item;
   }
}

QRectF blockModel::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void blockModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    resize();
    QRectF rect = boundingRect();
    QPen border(Qt::black, 2);
    if(coreRepr->type==block::Tatomic){
        painter->setBrush(Qt::darkGreen);
    }
    else if(coreRepr->type==block::Tcompozit)
    {
        painter->setBrush(QColor(255, 174, 0, 255));
    }
    else
         painter->setBrush(Qt::darkCyan);

    painter->setPen(border);
    painter->drawRoundedRect(rect,20,20);

    if(!(coreRepr->type==block::TonlyPort)){
        if(coreRepr->getName()=="")
            painter->drawText(15,20,QString::number(coreRepr->getId()));
        else{
            painter->drawText(15,20,(coreRepr->getName()).mid(0,21)+(coreRepr->getName().length()>21?"..." : ""));
        }
    }
    moveAllSubports();


    int space;
    if(coreRepr->type==block::TonlyPort)
        space=23;
    else
        space=40;
    foreach(port * item ,coreRepr->inputs)
    {
        painter->drawText(25,space,(item->getName().mid(0,9))+(item->getName().length()>9?".." : ""));
        space=space+30;
    }
    if(coreRepr->type==block::TonlyPort)
        space=23;
    else
        space=40;
    foreach(port * item ,coreRepr->outputs)
    {
        painter->drawText(95,space,(item->getName().mid(0,9))+(item->getName().length()>9?".." : ""));
        space=space+30;
    }
    update();
}


void blockModel::resize()
{
    if(coreRepr->type==block::TonlyPort)
    {
        height=40;
        width=180;
    }
    else
    {
        int newHeight=coreRepr->getMaxNumOfPort()*30;
        if(newHeight==0)
            height=60;
        else
            height=newHeight+30;

        width=180;
    }
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

void blockModel::moveAllSubports()
{
    coreRepr->x=this->x();
    coreRepr->y=this->y();
    foreach(portModel * item,ports){
        item->move();
    }
}

