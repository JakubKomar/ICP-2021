#ifndef APLICATION_H
#define APLICATION_H

#include "compozit.h"
#include <QObject>
#include <QDebug>
#include "atomic.h"

class aplication : public compozit
{
public:
    aplication();
    ~aplication()
    {
         qDebug()<<"aplication destructor engage";
    }
    QVector<compozit> compVect;
    QVector<atomic> atomVect;
private:

};

#endif // APLICATION_H
