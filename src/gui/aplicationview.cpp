/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Graphic board-here is drawed blocks
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "aplicationview.h"

aplicationView::aplicationView(QObject *parent,mainWindow *mainUI) : QGraphicsScene(parent),mainUi(mainUI){

}
aplicationView::~aplicationView(){}

void aplicationView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<event->scenePos();

    if(event->button()==Qt::RightButton)
    {
        for(auto * item:items(event->scenePos()))
        {
            qDebug()<<item;
             if (auto myrect=dynamic_cast<blockModel*>(item);myrect){
                 qDebug()<<"clicked on custom item id:"<<myrect->getId()<<" name:"<<myrect->getName();
                 if(myrect->getCrPtr()->type==block::Tatomic){
                      if(auto Cast=static_cast<atomic*>(myrect->getCrPtr());Cast){
                          mainUi->swichToAtomic(Cast);
                      }
                  }
                  else if(myrect->getCrPtr()->type==block::Tcompozit){
                      if (auto Cast=static_cast<compozit*>(myrect->getCrPtr());Cast){
                          mainUi->swichToComp(Cast);
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
                 mainUi->deleteExactBlock(myrect->getCrPtr());
                 delete myrect;
                 break;
            }
        }
    }
    QGraphicsScene::mousePressEvent(event);
}
void aplicationView::addGrapicRepr(int x,int y,block * coreRepr){
    QGraphicsItemGroup *Group = new QGraphicsItemGroup();
    Group->setFlags( QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    blockModel * newBlock = new blockModel(coreRepr,x,y);
    Group->addToGroup(newBlock);
    blockModels.append(newBlock);

    int space=20;
    foreach(port * item ,coreRepr->inputs)
    {
        portModel * object=new portModel(item);
        object->setPos(5,space);
        space=space+30;
        Group->addToGroup(object);
    }
    space=20;
    foreach(port * item ,coreRepr->outputs)
    {
        portModel * object=new portModel(item);
        object->setPos(50,space);
        space=space+30;
        Group->addToGroup(object);
    }
    addItem(Group);
}

void aplicationView::cleanScene()
{
    qDeleteAll(blockModels.begin(), blockModels.end());
    blockModels.clear();
}

void aplicationView::loadScene(compozit * CompPtr)
{
    if(CompPtr!=NULL){
        foreach(atomic * item,CompPtr->atomVect)
            addGrapicRepr(item->x,item->y,item);
        foreach(compozit * item,CompPtr->compVect)
            addGrapicRepr(item->x,item->y,item);
    }
}

void aplicationView::swichEditedComp(compozit *targetPtr)
{
    mainUi->swichToComp(targetPtr);
}

