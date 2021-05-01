/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of block
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
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
     int getId();
     QString getName();
     void setName(QString newName);;
     enum Type{
         Tnone,
         Tatomic,
         Tcompozit,
         TonlyPort,
     };
     Type type;      //selektor pro grafickou reprezentace
protected :
    QVector<port*> inputs;
    QVector<port*> outputs;
    QString name;
    int id; 
private:

signals:

};





#endif // BLOCK_H
