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

block::~block()
{
    qDeleteAll(inputs.begin(), inputs.end());
    inputs.clear();
    qDeleteAll(outputs.begin(), outputs.end());
    outputs.clear();
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

port* block::addPort(bool isInput)
{
    port * newPort;
    if(isInput){
        newPort=new port(port::Pin,inputs.count()+1,this);
        this->inputs.append(newPort);
    }
    else{
         newPort=new port(port::Pout,outputs.count()+1,this);
         this->outputs.append(newPort);
    }
    return newPort;

}

int block::getMaxNumOfPort()
{
    return fmax(inputs.count(),outputs.count());
}

int block::getWidth()
{
    int i=0;
    if(!inputs.empty())
        i++;
    if(!outputs.empty())
        i++;
    return i;
}

void block::delPort(port *ptr)
{
    for(int i=0;i<inputs.length();i++)
        {
            if(inputs[i]==ptr)
            {
                inputs.erase(inputs.begin()+i);
            }
        }
    for(int i=0;i<outputs.length();i++)
    {
        if(outputs[i]==ptr)
        {
            outputs.erase(inputs.begin()+i);
        }
    }
    delete ptr;
}

