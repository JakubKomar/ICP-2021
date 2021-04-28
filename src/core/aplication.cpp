#include "aplication.h"

aplication::aplication():idStack(0)
{
    this->setName("My Apk");
    this->setId(-1);
    qDebug()<<"aplication constructor engage";
}

void aplication::addAtom()
{
    atomic New;
    New.setId(idStack);
    idStack++;
    atomVect.append(New);
}

void aplication::firstSays()    //debug  method
{
    if(!atomVect.empty())
        atomVect.last().sayHallo();
}

