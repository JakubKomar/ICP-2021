/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of connection betwen ports
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "connection.h"

connection::connection(port * From,port * To):from(From),to(To)
{
    this->from->conect=this;
    this->to->conect=this;
    qDebug()<<"conection added";
}

connection::~connection()
{
    from->conect=nullptr;
    to->conect=nullptr;
}
