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

class compozit : public block
{
public:
    compozit();
    ~compozit();
    QVector<compozit *> compVect;
    QVector<atomic *> atomVect;
    /**
     * Create new atomic block
     * @return current pointer to block
     */
    atomic* addAtom();
    /**
     * Create new compozite blcok
     * @return current pointer to block
     */
    compozit* addCompozite();
    void deleteBlock(block * ptr);
    private:
        int idStack;    //IDs for new blocks
};

#endif // COMPOZIT_H
