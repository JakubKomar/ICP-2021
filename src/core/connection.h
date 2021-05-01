#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include "block.h"
class block;
class connection
{
public:
    enum TypeVal{
        Vint,
        Vdouble,
        Vstring,
        Vbool
    };
    connection(block * From,block * To,TypeVal Type);
    TypeVal type;
protected:
    block * from;
    block * to;
};

#endif // CONNECTION_H
