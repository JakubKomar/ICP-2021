/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of socket
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "portsocket.h"

portSocket::portSocket(port * imitating):imitating(imitating)
{
    this->type=block::TonlyPort;
    this->id=-3;
    this->oldId=-3;
    addPort();
}

portSocket::~portSocket()
{
}

void portSocket::addPort()
{
    port * newPort;
    if(imitating->type==port::Pin){
        newPort=new port(port::Pout,this);
        this->inputs.append(newPort);
    }
    else{
         newPort=new port(port::Pin,this);
         this->outputs.append(newPort);
    }
    viewedPort=newPort;
}

void portSocket::update()
{
    viewedPort->name=imitating->name;
    viewedPort->valType=imitating->valType;
    viewedPort->constant=imitating->constant;
}
