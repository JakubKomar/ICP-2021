#ifndef PORTSOCKET_H
#define PORTSOCKET_H

#include <QObject>
#include <QDebug>

#include "port.h"

class portSocket:public block
{
public:
    portSocket(port * imitating);
    port * imitating{nullptr};
};

#endif // PORTSOCKET_H
