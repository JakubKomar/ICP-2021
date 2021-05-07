/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Graphics reprezentation of port in block
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#ifndef PORTMODEL_H
#define PORTMODEL_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include "./core/port.h"

class port;
class portModel : public QGraphicsItem
{
public:
    portModel(port * coreRepm,int yOfset);
    /**
     * function for graphic displaying
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int yOfset{0};
    int xOfset{0};
    int xBindingOfs{7};
    int yBindingOfs{7};
    port * coreRepr;
public slots:
    /**
     * function to move th block
     */
    void move();
private:
    QRectF boundingRect() const;

};

#endif // PORTMODEL_H
