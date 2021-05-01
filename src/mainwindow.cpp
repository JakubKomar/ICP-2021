/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Main UI
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "mainwindow.h"


mainWindow::mainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    scene= new aplicationView(ui->apkView,this);
    ui->apkView->setScene(scene);
    ui->compoziteView->setScene(scene);
    this->curentApk=NULL;
}

mainWindow::~mainWindow()
{
    delete ui;
    if(curentApk)
        delete curentApk;
}

void mainWindow::swich(int page)
{
    ui->screenSwitch->setCurrentIndex(page);
}

void mainWindow::updateAtEditor()
{
    ui->AtNameEdit->clear();
    ui->codeTextEditor->clear();
    ui->AtNameEdit->insert(editedAtBlock->getName());
    ui->codeTextEditor->insertPlainText(editedAtBlock->code);
}

//----------debug buttons---------
void mainWindow::on_pushButton_2_clicked()
{
    ui->screenSwitch->setCurrentIndex( (ui->screenSwitch->currentIndex())-1 );
}

void mainWindow::on_pushButton_clicked()
{
    ui->screenSwitch->setCurrentIndex( (ui->screenSwitch->currentIndex())+1 );
}
//------------------------------

void mainWindow::on_newApk_clicked()
{
    if(curentApk!=NULL)
        delete curentApk;
    this->curentApk=new aplication;
}

void mainWindow::on_loadApk_clicked()
{
    if(curentApk!=NULL)
        delete curentApk;
    this->curentApk=new aplication;
}

void mainWindow::on_apkAddAtom_clicked()
{
    if(curentApk!=NULL)
    {
        atomic * pointer=curentApk->addAtom();
        scene->addGrapicRepr(0,0,pointer);
    }
}

void mainWindow::on_pushButton_4_clicked()
{
    if(curentApk!=NULL)
    {
        compozit * pointer=curentApk->addCompozite();
        scene->addGrapicRepr(0,0,pointer);
    }
}

void mainWindow::on_RenameAtom_clicked()
{
    editedAtBlock->setName( ui->AtNameEdit->text());
}

void mainWindow::on_AtNameEdit_cursorPositionChanged(int arg1, int arg2)
{

}

void mainWindow::on_pushButton_8_clicked()
{
    editedAtBlock->code=ui->codeTextEditor->toPlainText();
}

void mainWindow::on_AtAddInput_clicked()
{
    addAtInput(ui->atInputArea);
}
void mainWindow::on_AtAddOutput_clicked()
{
    addAtInput(ui->AtOutputArea);
}
void mainWindow::addAtInput(QWidget * place)
{
    QVBoxLayout * layout=qobject_cast<QVBoxLayout*>(place->layout());
    QHBoxLayout * newHorizontal1=new QHBoxLayout(place);
    QHBoxLayout * newHorizontal2=new QHBoxLayout(place);
    QVBoxLayout * newVertical=new QVBoxLayout(place);
    QString name=tr("input%1 ").arg(layout->count());

    const QSize BUTTON_SIZE = QSize(20, 20);
    QPushButton* button=new QPushButton("x",place);
    button->setMaximumSize(BUTTON_SIZE);
    portItemMap.insert(button,newVertical);
    QObject::connect(button,&QPushButton::clicked,this,&mainWindow::removePort);

    QLineEdit* lineEdit=new QLineEdit(name,place);

    QComboBox* comboBox=new QComboBox(place);
    comboBox->addItems({"int","string","bool","double"});

    newHorizontal1->insertWidget(0,button);
    newHorizontal1->insertWidget(0,lineEdit);
    newVertical->insertLayout(0,newHorizontal1);

    newHorizontal2->insertWidget(0,comboBox);
    newVertical->insertLayout(1,newHorizontal2);

    layout->insertLayout(layout->count()-1,newVertical);

}

void mainWindow::removePort()
{
   QPushButton* button=qobject_cast<QPushButton*>(sender());
   QVBoxLayout* Vertikal=portItemMap.value(button);

   while(Vertikal->count()!=0)
   {
       QLayoutItem* item=Vertikal->takeAt(0);
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
       delete horizontal->widget();
       delete horizontal;
   }
   delete Vertikal->widget();
   delete Vertikal;
}


