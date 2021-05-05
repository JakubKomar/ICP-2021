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
     this->conectMod=false;
}
aplicationView::~aplicationView(){
}

void aplicationView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::RightButton)
    {
        for(auto * item:items(event->scenePos()))
        {           
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
                 break;

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
    else  if(event->button()==Qt::LeftButton){
        for(auto * item:items(event->scenePos()))
        {
            if (auto port=dynamic_cast<portModel*>(item);port){
                if(actualConnection!=nullptr)
                   delete actualConnection;
                qDebug()<<"boží trest je tenhle projekt";
                conectMod=true;
                actualConnection=addLine(QLineF((port->x()+port->xBindingOfs),(port->y()+port->yBindingOfs),event->scenePos().x(),event->scenePos().y()));
                return;

            }
        }
    }
    if (!conectMod)
        QGraphicsScene::mousePressEvent(event);
}

void aplicationView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (conectMod){
        if(actualConnection){
             actualConnection->setLine(QLineF(actualConnection->line().p1(),event->scenePos()));
        }
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void aplicationView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (conectMod){
        if(actualConnection){
             actualConnection->setLine(QLineF(actualConnection->line().p1(),event->scenePos()));

        }
    }
    conectMod=false;
    QGraphicsScene::mouseReleaseEvent(event);
}
void aplicationView::addGrapicRepr(int x,int y,block * coreRepr){

    blockModel * newBlock = new blockModel(coreRepr,x,y);
    addItem(newBlock);
    int space=30;
    foreach(port * item ,coreRepr->inputs)
    {
        portModel * object=new portModel(item,space);

        object->move();
        space=space+30;
        newBlock->ports.append(object);
        addItem(object);
    }
    space=30;
    foreach(port * item ,coreRepr->outputs)
    {
        portModel * object=new portModel(item,space);
        object->move();
        space=space+30;
        newBlock->ports.append(object);
        addItem(object);
    }
    blockModels.append(newBlock);

}

void aplicationView::cleanScene()
{
    qDeleteAll(blockModels.begin(), blockModels.end());
    blockModels.clear();
    actualConnection=nullptr;
    clear();
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

