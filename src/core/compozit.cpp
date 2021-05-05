/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of compozite block
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "compozit.h"

compozit::compozit():idStack(0)
{
    qDebug()<<"compozit constructor engage";
    this->type=Tcompozit;
}

compozit::~compozit()
{
    qDebug()<<"compozite destructor";
    qDeleteAll(compVect.begin(), compVect.end());
    compVect.clear();
    qDeleteAll(atomVect.begin(), atomVect.end());
    atomVect.clear();
}
atomic* compozit::addAtom()
{
    atomic * New=new atomic;
    New->setId(idStack);
    idStack++;
    atomVect.append(New);
    return New;
}

compozit *compozit::addCompozite()
{
    compozit * New=new compozit;
    New->setId(idStack);
    idStack++;
    compVect.append(New);
    return New;
}

void compozit::deleteBlock(block *ptr)
{
    while(atomVect.removeOne(ptr)){}
    while(compVect.removeOne(ptr)){}
    delete ptr;
}

