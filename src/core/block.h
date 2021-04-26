#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include "./core/port.h"
class block : public QObject
{
    Q_OBJECT
public:
    //block();
    explicit block(QObject *parent = nullptr);
private:
    port * inputs;
    port * outputs;
    QString name;
    int id;
signals:

};
/*
block::block()
{
    this->inputs=NULL;
    this->outputs=NULL;
    this->name="";
}
*/
#endif // BLOCK_H
