#include "atomic.h"

atomic::atomic()
{
    qDebug()<<"atomic constructor engage";
    this->type=Tatomic;
    this->code="Test 1 2 3\n\ttabulator\n";
}
