/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Grup of widget for ports editing
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "portlayout.h"

portLayout::portLayout(QWidget * place,port * corePtr):corePtr(corePtr)
{
    this->deletedGraphic=false;
    QVBoxLayout * layout=qobject_cast<QVBoxLayout*>(place->layout());
    QHBoxLayout * newHorizontal1=new QHBoxLayout(place);
    QHBoxLayout * newHorizontal2=new QHBoxLayout(place);
    mainLayout=new QVBoxLayout(place);
    QString name=corePtr->name;

    const QSize BUTTON_SIZE = QSize(20, 20);
    QPushButton* button=new QPushButton("x",place);
    button->setMaximumSize(BUTTON_SIZE);

    QObject::connect(button,&QPushButton::clicked,this,&portLayout::destructButt);

    lineEdit=new QLineEdit(name,place);
    QObject::connect(lineEdit,&QLineEdit::textEdited,this,&portLayout::cheangeName);

    comboBox=new QComboBox(place);
    comboBox->addItems({"int","string","bool","double"});
    setComboBox();
     QObject::connect(comboBox,SIGNAL(activated(int)),this,SLOT(cheangeValType()));

    newHorizontal1->insertWidget(0,button);
    newHorizontal1->insertWidget(0,lineEdit);
    mainLayout->insertLayout(0,newHorizontal1);

    newHorizontal2->insertWidget(0,comboBox);
    mainLayout->insertLayout(1,newHorizontal2);

    layout->insertLayout(layout->count()-1,mainLayout);

}
portLayout::~portLayout(){
    deleteElements();
}

void portLayout::destructButt()
{
    corePtr->inBlock->delPort(corePtr); 
    deleteElements();
}

void portLayout::cheangeName()
{
    corePtr->setName(lineEdit->text());
}

void portLayout::cheangeValType()
{
    int index =comboBox->currentIndex();
    if(index==0)
        corePtr->changeType(port::Vint);
    else if(index==1)
        corePtr->changeType(port::Vstring);
    else if(index==2)
        corePtr->changeType(port::Vbool);
    else if(index==3)
        corePtr->changeType(port::Vdouble);
    else
        qDebug()<<"unexpected type";
}

void portLayout::deleteElements()
{
    if(!deletedGraphic)
    {
        while(mainLayout->count()!=0)
        {
            QLayoutItem* item=mainLayout->takeAt(0);
            auto horizontal=dynamic_cast<QHBoxLayout*>(item);
            if(horizontal!=NULL)
            {
                while(horizontal->count()!=0)
                {
                    QLayoutItem* titem=horizontal->takeAt(0);
                    delete titem->widget();
                    delete titem;
                }
            }
            delete horizontal;
        }
        delete mainLayout->widget();
        delete mainLayout;
    }
    deletedGraphic=true;
}

void portLayout::setComboBox()
{
    port::TypeVal type=corePtr->getType();
    int newIndex=-1;
    if(type==port::Vint)
        newIndex=0;
    else if(type==port::Vstring)
        newIndex=1;
    else if(type==port::Vbool)
        newIndex=2;
    else if(type==port::Vdouble)
       newIndex=3;
    else
        qDebug()<<"unexpected type";
    comboBox->setCurrentIndex(newIndex);
}

