/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of block ports
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "port.h"


port::port(port::Type type,int num,block *inBlock):type(type),inBlock(inBlock)
{
    this->valType=Vint;
    if(type==Pin)
        this->name=QString("input%1").arg(num);
    else
        this->name=QString("output%1").arg(num);
}

port::~port()
{
    qDebug()<<"port destruct";
    /*
    foreach(port * item,PortConnToThis ){
        item->connectedTo=nullptr;
    }
    if(connectedTo)
        connectedTo->removePortFromList(this);*/
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
    for(int i=0;i<PortConnToThis.count();i++){
        if(PortConnToThis.takeAt(i)==ptr)
            PortConnToThis.removeAt(i);
    }
}
