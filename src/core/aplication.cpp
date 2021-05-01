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

compozit *aplication::addCompozite()
{
    compozit * New=new compozit;
    New->setId(idStack);
    idStack++;
    compVect.append(New);
    return New;
}

