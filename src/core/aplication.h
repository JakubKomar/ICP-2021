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
    atomic* addAtom();
    compozit* addCompozite();
private:
    int idStack;
};

#endif // APLICATION_H
