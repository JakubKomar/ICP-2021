/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of atomic block
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "atomic.h"

atomic::atomic()
{
    qDebug()<<"atomic constructor engage";
    this->type=Tatomic;
    this->code="Test 1 2 3\n\ttabulator\n";
}
