#ifndef COMPOZIT_H
#define COMPOZIT_H

#include "block.h"
#include <QObject>
#include <QDebug>
class compozit : public block
{
public:
    compozit();
    ~compozit()
    {
         qDebug()<<"compozit destructor engage";
    }
};

#endif // COMPOZIT_H
