/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of block
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "block.h"

block::block():type(Tnone),x(0),y(0)
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

void block::addPort(bool isInput)
{/*
    port * newPort=new port();

    if(isInput){
        this->inputs.append(newPort);
    }
    else{
         this->outputs.append(newPort);
    }
*/
}
