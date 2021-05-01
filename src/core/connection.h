/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of connection betwen ports
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
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
