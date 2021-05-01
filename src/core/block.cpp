/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of block
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "block.h"

block::block():type(Tnone)
{
    this->name="";
}

void block::setId(int newId)
{
    id=newId;
}

int block::getId()
{
    return id;
}

QString block::getName()
{
    return name;
}

void block::setName(QString newName)
{
    name=newName;
}
