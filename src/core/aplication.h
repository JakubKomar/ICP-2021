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
    atomic* addAtom();
    compozit* addCompozite();
private:
    int idStack;
};

#endif // APLICATION_H
