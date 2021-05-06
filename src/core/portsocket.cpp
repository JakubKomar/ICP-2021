#include "portsocket.h"

portSocket::portSocket(port * imitating):imitating(imitating)
{
    this->type=block::TonlyPort;
}
