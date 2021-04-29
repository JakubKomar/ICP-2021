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
     void addGrapicRepr(int x,int y,block * coreRep);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;  
    QVector<blockModel*>blockModels;
    aplicationView * editor;
signals:

};

#endif // APLICATIONVIEW_H
