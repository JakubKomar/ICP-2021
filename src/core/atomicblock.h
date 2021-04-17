#ifndef ATOMICBLOCK_H
#define ATOMICBLOCK_H

#include <QObject>
#include "port.h"

class atomicBlock : public QObject
{
    Q_OBJECT
public:
    explicit atomicBlock(QObject *parent = nullptr);

private:
    QString name="";
    QString text="";
    QString category="";
    port *inputs=new port();
    port *outpus=new port();
    QString Code="";
signals:

};

#endif // ATOMICBLOCK_H
