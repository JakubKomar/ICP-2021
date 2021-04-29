#include "atomic.h"

atomic::atomic()
{
    qDebug()<<"atomic constructor engage";
    this->type=Tatomic;
}
void atomic::sayHallo()
{
    qDebug()<<"say Hallo id:"<<id;
}
