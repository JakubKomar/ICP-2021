/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of connection betwen ports
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "connection.h"

connection::connection(block * From,block * To,TypeVal Type):type(Type),from(From),to(To)
{

}
