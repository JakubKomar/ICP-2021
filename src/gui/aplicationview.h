#ifndef APLICATIONVIEW_H
#define APLICATIONVIEW_H

#include <QGraphicsScene>

#include "./core/atomicblock.h"
class aplicationView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit aplicationView(QObject *parent = nullptr);
    bool selectedAddAtom=false;
    bool selectedAddComp=false;
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void addBlock(int x,int y);
signals:

};

#endif // APLICATIONVIEW_H
