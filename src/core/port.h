/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of block ports
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QDebug>

#include "./core/block.h"
#include "./core/connection.h"

class block;
class connection;
class port
{
public:
    ~port()
    {
         qDebug()<<"port destructor engage";
    }
    enum Type{
        Pin,
        Pout,
    };
    enum TypeVal{
        Vint,
        Vdouble,
        Vstring,
        Vbool
    };
    port(Type type);
    Type type;
    TypeVal valType;
protected:
    block *inBlock;
    int ID;
    QString name;
    connection * conect;
private:

signals:

};

#endif // PORT_H
