#ifndef PORT_H
#define PORT_H

#include <QObject>
#include "./core/block.h"
#include <QDebug>
class block;
class port
{
public:
    port();
    ~port()
    {
         qDebug()<<"port destructor engage";
    }
protected:
    block *conector1;
    block *conector2;
private:

signals:

};

#endif // PORT_H
