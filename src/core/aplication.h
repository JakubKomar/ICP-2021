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

#include <QObject>
#include <QDebug>

#include "atomic.h"
#include "compozit.h"

class aplication : public compozit
{
public:
    aplication();
    ~aplication();
    /**
     * Geting new id from the apk
     * @return returning id
     */
    int getNewId();
private:
    int idStack;    //IDs for new blocks

};

#endif // APLICATION_H
