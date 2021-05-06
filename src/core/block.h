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
class block: public QObject
{
Q_OBJECT;
public:
     block();
     ~block();
     /**
      * Set ID to block
      * @param newId new ID
     */
     void setId(int newId);
     /**
      * get ID of block
      * @return ID
     */
     int getId();
     /**
      * get Name of block
      * @return name of block
     */
     QString getName();
     /**
      * set Name of block
      * @param new name of block
     */
     void setName(QString newName);;
     enum Type{
         Tnone,
         Tatomic,
         Tcompozit,
         TonlyPort,
     };
     Type type{TonlyPort};
     port* addPort(bool isInput);
     int getMaxNumOfPort();
     int getWidth();
     int x;     //pozition on graphic scene
     int y;
     void delPort(port * ptr);
     QList<port*> inputs;
     QList<port*> outputs;
protected :
    QString name;
    int id; 
private:

signals:

};





#endif // BLOCK_H
