#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include "./core/port.h"
class port;
class block
{
public:
    block();
     void setId(int newId);
     void setName(QString newName);
protected :
    QVector<port> inputs;
    QVector<port> outputs;
    QString name;
    int id;
private:

signals:

};





#endif // BLOCK_H
