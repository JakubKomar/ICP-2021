#include "atomic.h"

atomic::atomic()
{
    qDebug()<<"atomic constructor engage";
}
void atomic::sayHallo()
{
    qDebug()<<"say Hallo id:"<<id;
}
