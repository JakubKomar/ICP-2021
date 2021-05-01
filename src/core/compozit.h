/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of compozite block
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#ifndef COMPOZIT_H
#define COMPOZIT_H

#include "block.h"
#include "atomic.h"
#include <QObject>
#include <QDebug>
class compozit : public block
{
public:
    compozit();
    ~compozit()
    {
         qDebug()<<"compozit destructor engage";
    }
    QVector<compozit *> compVect;
    QVector<atomic *> atomVect;
};

#endif // COMPOZIT_H
