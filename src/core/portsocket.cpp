#include "portsocket.h"

portSocket::portSocket(port * imitating):imitating(imitating)
{
    this->type=block::TonlyPort;
    this->id=-3;
    addPort();
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
}
