#ifndef BLOCKMODEL_H
#define BLOCKMODEL_H
#include <QPainter>
#include <QGraphicsItem>

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
};

#endif // BLOCKMODEL_H
