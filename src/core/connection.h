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

#include <QDebug>
#include "port.h"

class port;
class connection: public QObject
{
public:
    connection(port * From,port * To);
    ~connection();
protected:
    port * from;
    port * to;
};

#endif // CONNECTION_H
