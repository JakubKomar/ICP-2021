/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of block ports
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "port.h"


port::port(port::Type type,int num):type(type)
{
    this->conect=NULL;
    this->valType=Vint;
    this->name=QString("input%1").arg(num);

}
