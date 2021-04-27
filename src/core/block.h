#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include "./core/port.h"
class port;
class block
{
public:
    block();
private:
    QVector<port> inputs;
    QVector<port> outputs;
    QString name;
    int id;
signals:

};



#endif // BLOCK_H
