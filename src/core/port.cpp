/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of block ports
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "port.h"
#include "portsocket.h"
#include "compozit.h"

port::port(port::Type type,int num,block *inBlock):type(type),inBlock(inBlock)
{
    this->valType=Vint;
    if(type==Pin)
        this->name=QString("input%1").arg(num);
    else
        this->name=QString("output%1").arg(num);
    this->socketPtr=nullptr;
}
port::port(port::Type type,block *inBlock):type(type),inBlock(inBlock)
{
    auto cast=static_cast<portSocket*>(inBlock);
    this->valType=cast->imitating->valType;
    this->name=cast->imitating->name;
}
port::~port()
{
    foreach(port * item,PortConnToThis ){
        item->connectedTo=nullptr;
    }
    if(connectedTo)
        connectedTo->removePortFromList(this);
    if((socketPtr!=nullptr)&&(inBlock->type==block::Tcompozit)){
        auto cast=dynamic_cast<compozit*>(inBlock);
        if(cast){
            cast->insidePorts.removeAll(socketPtr);
            delete socketPtr;
        }
    }
}

QString port::getName()
{
    return name;
}

void port::setName(QString newName)
{
    name=newName;
}

port::TypeVal port::getType()
{
    return valType;
}

void port::changeType(TypeVal newType)
{
    valType=newType;
}

void port::removePortFromList(port *ptr)
{
    while(PortConnToThis.removeOne(ptr)){}
}
