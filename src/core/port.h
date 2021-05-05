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
class port:public QObject
{
    Q_OBJECT
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
    port(Type type,int num,block *inBlock);
    Type type;
    TypeVal valType;
    QString name;
    block *inBlock;
    QString getName();
    void setName(QString newName);
    TypeVal getType();
    void changeType(TypeVal newType);
    connection * conect;
protected:
    int ID;
private:

signals:

};

#endif // PORT_H
