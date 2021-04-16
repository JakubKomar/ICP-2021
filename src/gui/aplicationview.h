#ifndef APLICATIONVIEW_H
#define APLICATIONVIEW_H

#include <QGraphicsScene>

class aplicationView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit aplicationView(QObject *parent = nullptr);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
signals:

};

#endif // APLICATIONVIEW_H
