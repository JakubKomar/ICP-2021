#ifndef APLICATIONVIEW_H
#define APLICATIONVIEW_H

#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>
#include "blockmodel.h"
class aplicationView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit aplicationView(QObject *parent = nullptr);
    ~aplicationView();
    bool selectedAddAtom=false;
    bool selectedAddComp=false;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void addBlock(int x,int y);
    QVector<blockModel*>blockModels;
signals:

};

#endif // APLICATIONVIEW_H
