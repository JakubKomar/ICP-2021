#include "aplicationview.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

aplicationView::aplicationView(QObject *parent) : QGraphicsScene(parent)
{


}

aplicationView::~aplicationView()
{
   /* if (!blockModels.empty()){
        for(auto *item:blockModels)
            delete item;
    }*/
}

void aplicationView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<event->scenePos();
    if(event->button()==Qt::RightButton)
    {
        addBlock(event->scenePos().rx(),event->scenePos().ry());
    }
    else if(event->button()==Qt::LeftButton)
    {
        for(auto * item:items(event->scenePos()))
        {
            if(auto rect=dynamic_cast<QGraphicsRectItem*>(item);rect){
                qDebug()<<"clicket on rectangle";
            }
            else if (auto myrect=dynamic_cast<blockModel*>(item);myrect){
                 qDebug()<<"clicket on custom item";
            }
        }     
    }
    else  if(event->button()==Qt::MiddleButton)
    {
        for(auto * item:items(event->scenePos()))
        {
            if(auto rect=dynamic_cast<QGraphicsRectItem*>(item);rect){
                qDebug()<<"clicket on rectangle";
            }
            else if (auto myrect=dynamic_cast<blockModel*>(item);myrect){
                 qDebug()<<"clicket on custom item";
                 delete myrect;
            }
        }
    }

    QGraphicsScene::mousePressEvent(event);
}
void aplicationView::addBlock(int x,int y){
    blockModel * newBlock = new blockModel;

    blockModels.append(newBlock);
    addItem(newBlock);
}

