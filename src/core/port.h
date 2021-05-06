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
#include <QList>


#include "./core/block.h"
#include "./gui/portmodel.h"

class block;
class portModel;
class port: public QObject
{
    Q_OBJECT
public:
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
    port(Type type,block *inBlock);
    ~port();
    Type type;
    TypeVal valType;
    QString name;
    block *inBlock;
    port *connectedTo{nullptr};
    portModel *graphicRep{nullptr};
    QString getName();
    void setName(QString newName);
    TypeVal getType();
    void changeType(TypeVal newType);
    QList<port*>PortConnToThis;
    void removePortFromList(port *ptr);
protected:
    int ID;
private:

signals:

};

#endif // PORT_H
