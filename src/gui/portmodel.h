#ifndef PORTMODEL_H
#define PORTMODEL_H

#include <QGraphicsItem>
#include "./core/port.h"
class portModel : public QGraphicsItem
{
public:
    portModel();
private:
    port * coreRepr;
};

#endif // PORTMODEL_H
