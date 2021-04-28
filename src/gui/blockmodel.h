#ifndef BLOCKMODEL_H
#define BLOCKMODEL_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
class blockModel: public QGraphicsItem
{
public:
    blockModel(QGraphicsItem * parent=NULL) ;
    QRectF boundigRect()const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
protected:
    //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    int height=0;
    int width=0;

};

#endif // BLOCKMODEL_H
