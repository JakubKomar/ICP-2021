#ifndef PORT_H
#define PORT_H

#include <QObject>
#include "./core/block.h"
#include "./core/connection.h"
#include <QDebug>
class block;
class connection;
class port
{
public:
    port();
    ~port()
    {
         qDebug()<<"port destructor engage";
    }
    enum Type{
        Pin,
        Pout,
    };
    Type type;
protected:
    block *inBlock;
    int ID;
    QString name;
    connection * conect;
private:

signals:

};

#endif // PORT_H
