#ifndef ATOMIC_H
#define ATOMIC_H

#include "block.h"
#include <QObject>
#include <QDebug>
class atomic : public block
{
public:
    atomic();
    ~atomic()
    {
         qDebug()<<"atmoic destructor engage";
    }
};

#endif // ATOMIC_H
