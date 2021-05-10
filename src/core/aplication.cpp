/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of aplikation
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "aplication.h"

aplication::aplication()
{
    this->setName("My Apk");
    this->setId(-1);
    this->idStack=-1;
}

aplication::~aplication()
{
}

int aplication::getNewId()
{
    idStack++;
    return idStack;
}

