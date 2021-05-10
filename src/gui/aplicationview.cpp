/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Graphic board-here are drawed blocks
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
                 break;
            }
        }     
    }
    else  if(event->button()==Qt::MiddleButton)
    {
        for(auto * item:items(event->scenePos()))
        {
            mainUi->destructorMod=true;
            if (auto myrect=dynamic_cast<blockModel*>(item);myrect){
                if(myrect->getCrPtr()->type!=block::TonlyPort){
                     mainUi->deleteExactBlock(myrect->getCrPtr());
                     mainUi->refresh();
                     drawConnections();
                }
                break;
            }
        }
         mainUi->destructorMod=false;
    }
    else  if(event->button()==Qt::LeftButton){
        for(auto * item:items(event->scenePos()))
        {
            if (auto port=dynamic_cast<portModel*>(item);port){
                bindingPort=port->coreRepr;
                if(actualConnection!=nullptr)
                   delete actualConnection;
                conectMod=true;
                actualConnection=addLine(QLineF((port->x()+port->xBindingOfs),(port->y()+port->yBindingOfs),event->scenePos().x(),event->scenePos().y()));
                actualConnection->setPen(QPen(Qt::red, 4));
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
    else
        drawConnections();

    QGraphicsScene::mouseMoveEvent(event);
}

void aplicationView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (conectMod){
        for(auto * item:items(event->scenePos()))
        {
            if (auto port=dynamic_cast<portModel*>(item);port){
                if(port->coreRepr->valType==bindingPort->valType && port->coreRepr->type!=bindingPort->type)
                {
                    if( port->coreRepr->type==port::Pout){
                        if( bindingPort->connectedTo==port->coreRepr){
                             bindingPort->connectedTo=nullptr;
                             port->coreRepr->PortConnToThis.removeAll(bindingPort);
                        }
                        else{
                            bindingPort->connectedTo=port->coreRepr;
                            port->coreRepr->PortConnToThis.append(bindingPort);
                        }
                    }
                    else{
                        if( port->coreRepr->connectedTo==bindingPort){
                             port->coreRepr->connectedTo=nullptr;
                             bindingPort->PortConnToThis.removeAll(port->coreRepr);
                        }
                        else{
                             port->coreRepr->connectedTo=bindingPort;
                             bindingPort->PortConnToThis.append(port->coreRepr);
                        }
                    }
                    drawConnections();             
                }
                else
                    qDebug()<<"failed connection";

            }

        }
        delete actualConnection;
        actualConnection=nullptr;
    }
    conectMod=false;
    QGraphicsScene::mouseReleaseEvent(event);
}

void aplicationView::deleteGraphicBlock(blockModel * ptr)
{
    while(blockModels.removeOne(ptr)){}
    //delete ptr;
}

void aplicationView::addGrapicRepr(int x,int y,block * coreRepr){

    blockModel * newBlock = new blockModel(coreRepr,x,y);
    addItem(newBlock);
    int space;
    if(coreRepr->type==block::TonlyPort)
        space=12;
    else
        space=30;
    foreach(port * item ,coreRepr->inputs)
    {
        portModel * object=new portModel(item,space);
        object->move();
        space=space+30;
        newBlock->ports.append(object);
        addItem(object);
        item->graphicRep=object;
    }
    if(coreRepr->type==block::TonlyPort)
        space=12;
    else
        space=30;
    foreach(port * item ,coreRepr->outputs)
    {
        portModel * object=new portModel(item,space);
        object->move();
        space=space+30;
        newBlock->ports.append(object);
        addItem(object);
        item->graphicRep=object;
    }
    blockModels.append(newBlock);

}

void aplicationView::cleanScene()
{
    qDeleteAll(lines);
    lines.clear();
    qDeleteAll(blockModels.begin(), blockModels.end());
    blockModels.clear();
    actualConnection=nullptr;

}

void aplicationView::loadScene(compozit * CompPtr)
{
    if(CompPtr!=NULL){
        foreach(atomic * item,CompPtr->atomVect)
            addGrapicRepr(item->x,item->y,item);
        foreach(compozit * item,CompPtr->compVect)
            addGrapicRepr(item->x,item->y,item);
        foreach(portSocket * item,CompPtr->insidePorts)
            addGrapicRepr(item->x,item->y,item);
    }
    drawConnections();
}

void aplicationView::swichEditedComp(compozit *targetPtr)
{
    mainUi->swichToComp(targetPtr);
}

void aplicationView::drawConnections()
{
    qDeleteAll(lines);
    lines.clear();

    foreach(block * bItem,mainUi->viewedBlock->atomVect){
        foreach(port * pItem,bItem->inputs){
            if(pItem->connectedTo!=nullptr){
                QGraphicsLineItem * newLine= addLine(QLineF(pItem->graphicRep->pos()+QPoint(7,7),pItem->connectedTo->graphicRep->pos()+QPoint(7,7)));
                newLine->setPen(QPen(Qt::blue, 4));
                lines.append(newLine);
            }
        }
    }
    foreach(block * bItem,mainUi->viewedBlock->compVect){
        foreach(port * pItem,bItem->inputs){
            if(pItem->connectedTo!=nullptr){
                QGraphicsLineItem * newLine= addLine(QLineF(pItem->graphicRep->pos()+QPoint(7,7),pItem->connectedTo->graphicRep->pos()+QPoint(7,7)));
                newLine->setPen(QPen(Qt::blue, 4));
                lines.append(newLine);
            }
        }
    }
    foreach(block * bItem,mainUi->viewedBlock->insidePorts){
        foreach(port * pItem,bItem->outputs){
            if(pItem->connectedTo!=nullptr){
                QGraphicsLineItem * newLine= addLine(QLineF(pItem->graphicRep->pos()+QPoint(7,7),pItem->connectedTo->graphicRep->pos()+QPoint(7,7)));
                newLine->setPen(QPen(Qt::blue, 4));
                lines.append(newLine);
            }
        }
    }
}

