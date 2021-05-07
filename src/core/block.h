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
     /**
      * type is used, when the block is drawed to screen and for some cast in code
     */
     Type type{TonlyPort};
     /**
      * adding new port to block
      * @param isInput - false-OUTPUT , true-INPUT
      * @return pointer to new port
     */
     port* addPort(bool isInput);
     /**
      * geting max value from input and output counts
      * @return max value from input and output counts, value used for drawing blocks
     */
     int getMaxNumOfPort();
     /**
      * function for calculating width of block, used when painting blocks
      * @return max value from input and output counts, value used for drawing blocks
     */
     int getWidth();
     int x;     //pozition on graphic scene
     int y;
     /**
      * deleting exact port
      * @param  ptr -pointer to deleted param
     */
     void delPort(port * ptr);
     QList<port*> inputs;
     QList<port*> outputs;
protected :
    QString name;
    int id; 

};





#endif // BLOCK_H
