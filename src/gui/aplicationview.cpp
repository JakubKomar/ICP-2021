/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Graphic board-here is drawed blocks
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

#include "aplicationview.h"
#include "blockmodel.h"
aplicationView::aplicationView(QObject *parent,mainWindow *mainUI) : QGraphicsScene(parent),mainUi(mainUI)
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
        for(auto * item:items(event->scenePos()))
        {
             if (auto myrect=dynamic_cast<blockModel*>(item);myrect){
                 qDebug()<<"clicked on custom item id:"<<myrect->getId()<<" name:"<<myrect->getName();
                 if(myrect->getCrPtr()->type==block::Tatomic){
                      if(auto Cast=static_cast<atomic*>(myrect->getCrPtr());Cast){
                          mainUi->editedAtBlock=Cast;
                          mainUi->updateAtEditor();
                          mainUi->swich(2);
                      }
                  }
                  else if(myrect->getCrPtr()->type==block::Tcompozit){
                      if (auto Cast=static_cast<compozit*>(myrect->getCrPtr());Cast){
                          mainUi->swich(1);
                      }
                  }
                  else
                      qDebug()<<"nepovedený cast :(";

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
                 break;
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

