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
    if(!callBackStack.empty()){
        viewedBlock=this->callBackStack.pop();
        editedBlock=viewedBlock;
    }
    else{
        viewedBlock=this->curentApk;
        editedBlock=viewedBlock;
    }
}

void mainWindow::updateAtEditor(){
    ui->codeTextEditor->clear();
    ui->AtNameEdit->insert(editedAtBlock->getName());
    ui->codeTextEditor->insertPlainText(editedAtBlock->code);
}


void mainWindow::refreshSlot()
{
    if(!destructorMod)
        refresh();
}

void mainWindow::on_newApk_clicked(){
    if(curentApk!=NULL)
        delete curentApk;
    this->curentApk=new aplication();
    this->viewedBlock=this->curentApk;
    refresh();
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
        atomic * pointer=viewedBlock->addAtom(curentApk->getNewId());
        scene->addGrapicRepr(0,0,pointer);

    }
}

void mainWindow::on_AddComp2_clicked(){on_addCompozite_clicked();}
void mainWindow::on_addCompozite_clicked(){
    if(viewedBlock!=NULL)
    {
        compozit * pointer=viewedBlock->addCompozite(curentApk->getNewId());
        scene->addGrapicRepr(0,0,pointer);
    }
}

void mainWindow::on_renameBlock_clicked(){
    editedBlock->setName( ui->AtNameEdit->text());
}

void mainWindow::on_pushButton_8_clicked()
{
    editedAtBlock->code=ui->codeTextEditor->toPlainText();
}

void mainWindow::on_AtAddInput_clicked(){
    port * corePtr=this->editedBlock->addPort(true);
    auto layout=new portLayout(ui->InputArea,corePtr);
    layoutList.append(layout);

    if(editedBlock->type==block::Tcompozit){
        compozit * comp= static_cast<compozit*>(editedBlock);
        portSocket * newSocket=new portSocket(corePtr);
        connect(newSocket,SIGNAL(destroyed()),this,SLOT(refreshSlot()));
        comp->insidePorts.append(newSocket);
        corePtr->socketPtr=newSocket;
        refresh();
    }

}
void mainWindow::on_AtAddOutput_clicked(){
    port * corePtr=this->editedBlock->addPort(false);
    auto layout= new portLayout(ui->OutputArea,corePtr);
    layoutList.append(layout);

    if(editedBlock->type==block::Tcompozit){
        compozit * comp= static_cast<compozit*>(editedBlock);
        portSocket * newSocket=new portSocket(corePtr);
        connect(newSocket,SIGNAL(destroyed()),this,SLOT(refreshSlot()));
        comp->insidePorts.append(newSocket);
        corePtr->socketPtr=newSocket;
        refresh();
    }
}

void mainWindow::refresh()
{
    scene->cleanScene();
    scene->loadScene(this->viewedBlock);
}

void mainWindow::on_goBack_clicked()
{
    editingAtom=false;
    callBackPop();
    refresh();
    refreshPorts();
    scene->drawConnections();
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
    ui->AtNameEdit->insert(viewedBlock->getName());
    ui->id->clear();
    ui->id->insert(QString::number(viewedBlock->getId()));
    refresh();
    refreshPorts();
    primarySwich(1);
    secondarySwich(1);
}

void mainWindow::swichToAtomic(atomic *targetPtr)
{
    editingAtom=true;
    refresh();
    callBackPush();
    editedAtBlock=targetPtr;
    editedBlock=targetPtr;
    ui->AtNameEdit->clear();
    ui->id->clear();
    ui->id->insert(QString::number(editedAtBlock->getId()));
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

void mainWindow::buildAtomic(atomic * ptr)
{

}

void mainWindow::buildCompozite(compozit * prt)
{

}

void mainWindow::on_Build_clicked()
{
    QDir dir = QDir::current();
    dir.mkdir("build");

    QFile file("build/BuildedApk");
    if (!file.open(QIODevice::WriteOnly  | QIODevice::Text))
          return;
    QTextStream out(&file);
     out << "The magic number is: " << 49 << "\n";
     return;

    foreach(atomic * item,curentApk->atomVect){
        buildAtomic(item);
    }
}

void mainWindow::on_save_clicked()
{
    QFile file("MyXml.xml");
    if(!file.open(QIODevice::WriteOnly)){
        qDebug()<<"error while opening file";
        return;
    }

    QXmlStreamWriter xmlWriter(&file);
    writer=&xmlWriter;
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    if(editingAtom){
        saveAtom(editedAtBlock,false,false);
    }

    xmlWriter.writeEndElement();
    file.close();
}

void mainWindow::saveAtom(atomic *ptr,bool saveConnections,bool savePosition)
{
    writer->writeStartElement("atomicBlock");
    writer->writeAttribute("id",QString::number(ptr->getId()));
    writer->writeAttribute("name",ptr->getName());
    if(savePosition){
        writer->writeAttribute("x",QString::number(ptr->x));
        writer->writeAttribute("y",QString::number(ptr->y));
    }
    else{
        writer->writeAttribute("x","0");
        writer->writeAttribute("y","0");
    }
    writer->writeTextElement("code",ptr->code);
    foreach(port * item,ptr->inputs){savePort(item,saveConnections);}
    foreach(port * item,ptr->outputs){savePort(item,saveConnections);}
    writer->writeEndElement();

}
void mainWindow::savePort(port *ptr,bool saveConnections)
{
     writer->writeStartElement("port");
     writer->writeAttribute("name",ptr->name);
     switch (ptr->valType) {
        case port::Vint:
            writer->writeAttribute("valType","int");
            break;
        case port::Vdouble:
            writer->writeAttribute("valType","double");
            break;
        case port::Vstring:
            writer->writeAttribute("valType","string");
            break;
        case port::Vbool:
            writer->writeAttribute("valType","bool");
            break;
     }
     if(ptr->type==port::Pin){
         writer->writeAttribute("type","input");
         if((ptr->connectedTo!=nullptr)&&saveConnections){
             writer->writeAttribute("connectedToBlock",QString::number(ptr->connectedTo->inBlock->getId()));
             writer->writeAttribute("connectedToPort",QString(ptr->connectedTo->getName()));
         }
     }
     else
         writer->writeAttribute("type","output");
     writer->writeEndElement();
}
