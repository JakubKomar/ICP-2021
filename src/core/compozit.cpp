/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of compozite block
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "compozit.h"

compozit::compozit()
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
atomic* compozit::addAtom(int id)
{
    atomic * New=new atomic;
    New->setId(id);
    atomVect.append(New);
    return New;
}

compozit *compozit::addCompozite(int id)
{
    compozit * New=new compozit;
    New->setId(id);
    compVect.append(New);
    return New;
}

void compozit::deleteBlock(block *ptr)
{
    if(ptr->type==block::Tatomic)
        atomVect.removeAll(static_cast<atomic*>(ptr));
    else if(ptr->type==block::Tcompozit)
        compVect.removeAll(static_cast<compozit*>(ptr));
    delete ptr;
}

