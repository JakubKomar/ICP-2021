#include "block.h"

block::block():type(Tnone)
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
