#include "aplicationview.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include "blockmodel.h"
aplicationView::aplicationView(QObject *parent) : QGraphicsScene(parent)
{

}

void aplicationView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<event->scenePos();
    if(event->button()==Qt::RightButton)
    {
        addBlock(event->scenePos().rx(),event->scenePos().ry());
    }
    else
    {
        for(auto * item:items(event->scenePos()))
        {
            if(auto rect=dynamic_cast<QGraphicsRectItem*>(item);rect){
                qDebug()<<"clicket on rectangle";
            }
        }
    }

    QGraphicsScene::mousePressEvent(event);
}
void aplicationView::addBlock(int x,int y){


}

