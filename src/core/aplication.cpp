#include "aplication.h"

aplication::aplication():idStack(0)
{
    this->setName("My Apk");
    this->setId(-1);
    qDebug()<<"aplication constructor engage";
}

atomic* aplication::addAtom()
{
    atomic * New=new atomic;
    New->setId(idStack);
    idStack++;
    atomVect.append(New);
    return New;
}

void aplication::firstSays()    //debug  method
{
    if(!atomVect.empty())
        atomVect.last()->sayHallo();
}

