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
    delete scene;
    if(curentApk)
        delete curentApk;
    clearPortLayouts();
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

    /*scene->clear();
    if(curentApk!=NULL)
        delete curentApk;*/
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
    port * corePtr=this->editedBlock->addPort(true);
    auto layout=new portLayout(ui->InputArea,corePtr);
    layoutList.append(layout);
}
void mainWindow::on_AtAddOutput_clicked(){
    port * corePtr=this->editedBlock->addPort(false);
    auto layout= new portLayout(ui->OutputArea,corePtr);
    layoutList.append(layout);
}

void mainWindow::refresh()
{
    scene->cleanScene();
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
    ui->AtNameEdit->clear();
    refresh();
    refreshPorts();
    primarySwich(1);
    secondarySwich(1);
}

void mainWindow::swichToAtomic(atomic *targetPtr)
{
    refresh();
    callBackPush();
    editedAtBlock=targetPtr;
    editedBlock=targetPtr;
    ui->AtNameEdit->clear();
    updateAtEditor();
    refreshPorts();
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

void mainWindow::clearPortLayouts()
{
    while(!layoutList.empty()){
        delete layoutList.takeAt(0);
    }
}

void mainWindow::refreshPorts()
{
     clearPortLayouts();
     foreach(port * item,editedBlock->inputs)
     {
         auto layout=new portLayout(ui->InputArea,item);
         layoutList.append(layout);
     }
     foreach(port * item,editedBlock->outputs)
     {
         auto layout=new portLayout(ui->OutputArea,item);
         layoutList.append(layout);
     }
}

void mainWindow::on_debugClear_clicked()
{
    refresh();

}
