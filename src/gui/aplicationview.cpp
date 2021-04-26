#include "aplicationview.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
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

    QGraphicsScene::mousePressEvent(event);
}
void aplicationView::addBlock(int x,int y){
     auto rect =addRect(x,y,100,100,QPen({Qt::black},3),QBrush(Qt::green));
     rect->setFlag(QGraphicsItem::ItemIsSelectable);
     rect->setFlag(QGraphicsItem::ItemIsMovable);
}

