#ifndef APLIKATION_H
#define APLIKATION_H

#include <QObject>
#include "core/atomicblock.h"
class aplikation : public QObject
{
    Q_OBJECT
public:
    explicit aplikation(QObject *parent = nullptr);
private:
    atomicBlock *blockList=new(atomicBlock);
signals:

};

#endif // APLIKATION_H
