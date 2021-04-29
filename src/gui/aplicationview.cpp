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

    if(event->button()==Qt::LeftButton)
    {
        for(auto * item:items(event->scenePos()))
        {
            if(auto rect=dynamic_cast<QGraphicsRectItem*>(item);rect){
                qDebug()<<"clicked on rectangle";
            }
            else if (auto myrect=dynamic_cast<blockModel*>(item);myrect){
                 qDebug()<<"clicked on custom item id:"<<myrect->getId()<<" name:"<<myrect->getName();
                  if (auto uhOh=static_cast<atomic*>(myrect->getCrPtr());uhOh){
                      qDebug()<<"castnutej atomickej blok";
                  }
                  else if (auto uhOh=static_cast<compozit*>(myrect->getCrPtr());uhOh){
                      qDebug()<<"castnutej atomickej blok";
                  }
                  else
                      qDebug()<<"nepovedlo se :(";

            }
        }     
    }
    else  if(event->button()==Qt::MiddleButton)
    {
        for(auto * item:items(event->scenePos()))
        {
            if (auto myrect=dynamic_cast<blockModel*>(item);myrect){
                 delete myrect->getCrPtr();
                 delete myrect;
            }
        }
    }

    QGraphicsScene::mousePressEvent(event);
}
void aplicationView::addGrapicRepr(int x,int y,block * CoreRep){
    blockModel * newBlock = new blockModel(CoreRep);
    blockModels.append(newBlock);
    addItem(newBlock);
}

