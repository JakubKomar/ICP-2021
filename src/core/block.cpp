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
