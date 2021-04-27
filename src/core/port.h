#ifndef PORT_H
#define PORT_H

#include <QObject>
#include "./core/block.h"
class block;
class port
{
public:
    port();
private:
    block *conector1;
    block *conector2;
signals:

};

#endif // PORT_H
