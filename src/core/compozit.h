#ifndef COMPOZIT_H
#define COMPOZIT_H

#include "block.h"
#include "atomic.h"
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
    QVector<compozit *> compVect;
    QVector<atomic *> atomVect;
};

#endif // COMPOZIT_H
