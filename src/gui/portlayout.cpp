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

    connect(button,&QPushButton::clicked,this,&portLayout::destructButt);
    //connect(button,&QPushButton::clicked,this,&mainWindow::deletePortL);

    QLineEdit* lineEdit=new QLineEdit(name,place);

    QComboBox* comboBox=new QComboBox(place);
    comboBox->addItems({"int","string","bool","double"});

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

