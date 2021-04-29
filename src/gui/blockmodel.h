#ifndef BLOCKMODEL_H
#define BLOCKMODEL_H
#include <QPainter>
#include <QGraphicsItem>
#include "./core/block.h"
#include <QSet>

class blockModel : public QGraphicsItem
{
public:
    blockModel();
    ~blockModel();
    QRectF boundingRect() const;
    void paint(QPainter * painter,const QStyleOptionGraphicsItem * option,QWidget * widget);
    void resize(int newWidth,int newHeight);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int height;
    int width;
    block * coreRepr;
};

#endif // BLOCKMODEL_H
