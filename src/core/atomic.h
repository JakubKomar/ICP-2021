/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of atomic block
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#ifndef ATOMIC_H
#define ATOMIC_H

#include <QObject>
#include <QDebug>
#include "block.h"

class atomic : public block
{
public:
    atomic();
    ~atomic();
    QString code;
private:

};

#endif // ATOMIC_H
