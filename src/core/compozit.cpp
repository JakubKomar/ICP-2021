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
    for(int i=0;i<atomVect.length();i++)
    {
        if(atomVect[i]==ptr)
        {
            atomVect.erase(atomVect.begin()+i);
        }
    }
    for(int i=0;i<compVect.length();i++)
    {
        if(compVect[i]==ptr)
        {
            compVect.erase(compVect.begin()+i);
        }
    }
    delete ptr;
}

