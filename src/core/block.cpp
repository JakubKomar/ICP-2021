#include "block.h"

block::block()
{
    this->name="";
}

void block::setId(int newId)
{
    id=newId;
}

void block::setName(QString newName)
{
    name=newName;
}
