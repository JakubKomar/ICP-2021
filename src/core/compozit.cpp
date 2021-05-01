/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of compozite block
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "compozit.h"

compozit::compozit()
{
    qDebug()<<"compozit constructor engage";
    this->type=Tcompozit;
}
