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

#include <QObject>
#include <QDebug>

#include "block.h"
#include "atomic.h"
#include "portsocket.h"
class compozit : public block
{
public:
    compozit();
    ~compozit();
    QList<compozit *> compVect;
    QList<atomic *> atomVect;
    QList<portSocket*>insidePorts;
    /**
     * Create new atomic block
     * @return current pointer to block
     */
    atomic* addAtom(int id);
    /**
     * Create new compozite blcok
     * @return current pointer to block
     */
    compozit* addCompozite(int id);
    /**
     * Deleting exact block from compozite
     * @param pointer to deleted block
     */
    void deleteBlock(block * ptr);
};

#endif // COMPOZIT_H
