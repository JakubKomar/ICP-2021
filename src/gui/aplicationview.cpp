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
        auto rect =addRect(event->scenePos().rx(),event->scenePos().ry(),100,100,QPen({Qt::black},3),QBrush({Qt::green}));
        rect->setFlag(QGraphicsItem::ItemIsSelectable);
        rect->setFlag(QGraphicsItem::ItemIsMovable);
    }

    QGraphicsScene::mousePressEvent(event);
}

