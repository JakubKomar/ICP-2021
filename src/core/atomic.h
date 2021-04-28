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
         qDebug()<<"atomic destructor engage";
    }
    void sayHallo();
};

#endif // ATOMIC_H
