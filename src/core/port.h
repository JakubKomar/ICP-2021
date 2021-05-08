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
class portSocket;
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
    /**
     * Constructor for atomic and compozit blocks
     */
    port(Type type,int num,block *inBlock);
    /**
     * Constructor for sockets
     */
    port(Type type,block *inBlock);
    ~port();
    Type type;  //input/output
    TypeVal valType;//string,int,...
    QString name;
    block *inBlock;
    port *connectedTo{nullptr};
    portModel *graphicRep{nullptr};
    /**
     * returning name of port
     * @return string name of port
     */
    QString getName();
    /**
     * seting name of port
     * @param new string name of port
     */
    void setName(QString newName);
    /**
     * returning type of port - input/output
     * @return type of port
     */
    TypeVal getType();
    /**
     * change type of port
     * @param new type
     */
    void changeType(TypeVal newType);
    QList<port*>PortConnToThis;
    /**
     * deleting port from connected list
     * @param deleted port
     */
    void removePortFromList(port *ptr);
    portSocket * socketPtr{nullptr};
protected:
    int ID;
};

#endif // PORT_H
