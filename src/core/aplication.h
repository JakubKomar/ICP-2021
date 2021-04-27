#ifndef APLICATION_H
#define APLICATION_H

#include "compozit.h"
#include <QObject>
#include <QDebug>
class aplication : public compozit
{
public:
    aplication();
    ~aplication()
    {
         qDebug()<<"aplication destructor engade";
    }

private:

};

#endif // APLICATION_H
