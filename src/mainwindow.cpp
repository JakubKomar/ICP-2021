/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Main UI
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::mainWindow){
    ui->setupUi(this);
    scene= new aplicationView(ui->apkView,this);
    ui->apkView->setScene(scene);
    ui->apkView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    ui->compoziteView->setScene(scene);
    ui->compoziteView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    this->curentApk=NULL;
    this->viewedBlock=NULL;
}

mainWindow::~mainWindow(){
    delete ui;
    if(curentApk)
        delete curentApk;
}

void mainWindow::primarySwich(int page){
    ui->screenSwitch->setCurrentIndex(page);
}

void mainWindow::secondarySwich(int page){
     ui->editingAreaWidget->setCurrentIndex(page);
}

void mainWindow::deleteExactBlock(block *ptr){
    viewedBlock->deleteBlock(ptr);
}

void mainWindow::callBackPush(){
    this->callBackStack.push(viewedBlock);
}

void mainWindow::callBackPop()
{
    if(!callBackStack.empty())
        viewedBlock=this->callBackStack.pop();
    else
        viewedBlock=this->curentApk;
}

void mainWindow::updateAtEditor(){
    ui->AtNameEdit->clear();
    ui->codeTextEditor->clear();
    ui->AtNameEdit->insert(editedAtBlock->getName());
    ui->codeTextEditor->insertPlainText(editedAtBlock->code);
}

void mainWindow::on_newApk_clicked(){
    scene->clear();
    if(curentApk!=NULL)
        delete curentApk;
    this->curentApk=new aplication;
    this->viewedBlock=this->curentApk;
}

void mainWindow::on_loadApk_clicked(){
    scene->clear();
    if(curentApk!=NULL)
        delete curentApk;
   //to do
}

void mainWindow::on_addAtomic2_clicked(){on_apkAddAtom_clicked();}
void mainWindow::on_apkAddAtom_clicked(){
    if(viewedBlock!=NULL)
    {
        atomic * pointer=viewedBlock->addAtom();
        scene->addGrapicRepr(0,0,pointer);
    }
}

void mainWindow::on_AddComp2_clicked(){on_addCompozite_clicked();}
void mainWindow::on_addCompozite_clicked(){
    if(viewedBlock!=NULL)
    {
        compozit * pointer=viewedBlock->addCompozite();
        scene->addGrapicRepr(0,0,pointer);
    }
}

void mainWindow::on_renameBlock_clicked(){
    editedBlock->setName( ui->AtNameEdit->text());
}

void mainWindow::on_AtNameEdit_cursorPositionChanged(int arg1, int arg2){

}

void mainWindow::on_pushButton_8_clicked()
{
    editedAtBlock->code=ui->codeTextEditor->toPlainText();
}

void mainWindow::on_AtAddInput_clicked(){
    this->editedAtBlock->addPort(TRUE);
    addAtInput(ui->atInputArea);
}
void mainWindow::on_AtAddOutput_clicked(){
    addAtInput(ui->AtOutputArea);
}
void mainWindow::addAtInput(QWidget * place){
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

void mainWindow::removePort(){
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


void mainWindow::refresh()
{
    scene->clear();
    scene->loadScene(this->viewedBlock);
}

void mainWindow::on_goBack_clicked()
{
    callBackPop();
    refresh();
    if(curentApk==viewedBlock)
        primarySwich(0);
    else
    {
        primarySwich(1);
        secondarySwich(1);
        editedAtBlock=NULL;
    }

}

void mainWindow::swichToComp(compozit *targetPtr)
{
    callBackPush();
    viewedBlock=targetPtr;
    editedBlock=targetPtr;
    refresh();
    primarySwich(1);
    secondarySwich(1);
}

void mainWindow::swichToAtomic(atomic *targetPtr)
{
    callBackPush();
    editedAtBlock=targetPtr;
    editedBlock=targetPtr;
    updateAtEditor();
    primarySwich(1);
    secondarySwich(0);
}

void mainWindow::on_undo_clicked()
{
    ui->codeTextEditor->undo();
}

void mainWindow::on_redo_clicked()
{
    ui->codeTextEditor->redo();
}
