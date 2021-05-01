/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of aplikation
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
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
    /**
     * Create new atomic blcok
     * @return current pointer to block
     */
    atomic* addAtom();
    /**
     * Create new compozite blcok
     * @return current pointer to block
     */
    compozit* addCompozite();
private:
    int idStack;    //IDs for new blocks
};

#endif // APLICATION_H
