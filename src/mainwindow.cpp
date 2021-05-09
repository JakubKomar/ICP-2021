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

    //catalog setup
    QString path = QDir::currentPath();
    path=path+"/examples/";  // rootfolder to display = library folder
    workingPath = path;


    folder = new QFileSystemModel(this);                        // create the new model
    folder -> setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);  // show only directories (hide other)
    folder -> setRootPath(path);                                // populate (folder) model (using set rootpath)
    ui -> treeView -> setModel(folder);

    QModelIndex index = folder->index(path, 0);
    ui->treeView->setRootIndex(index);

    file = new QFileSystemModel(this);
    file -> setFilter(QDir::NoDotAndDotDot | QDir::Files);
    file -> setRootPath(path);

    file -> setNameFilters(QStringList() << "*.xml");           // show only xml files
    file -> setNameFilterDisables(false);                       // hides filtered (grey) files

    ui -> listView -> setModel(file);

    index = file->index(path, 0);
    ui->listView->setRootIndex(index);
}

mainWindow::~mainWindow(){
    destructorMod=true;
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
    if((!destructorMod)&&(!loadingMod))
        refresh();
}

void mainWindow::on_newApk_clicked(){
    if(curentApk!=NULL)
        delete curentApk;
    this->curentApk=new aplication();
    this->viewedBlock=this->curentApk;
    ui->renameApkEdit->setText(curentApk->getName());
    refresh();
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
    if(viewedBlock){
        scene->cleanScene();
        scene->loadScene(this->viewedBlock);
    }
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
        ui->AtNameEdit->clear();
        ui->AtNameEdit->insert(viewedBlock->getName());
        ui->id->clear();
        ui->id->insert(QString::number(viewedBlock->getId()));
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
void mainWindow::on_Build_clicked()
{
    QDir dir = QDir::current();
    dir.mkdir("apkBuild");

    QFile file("apkBuild/apk.cpp");
    if (!file.open(QIODevice::WriteOnly)){
         QMessageBox::information(this, "error", "File cant be opened.");
         return;
    }
    buildHead(&file);
    foreach(atomic * item,curentApk->atomVect){
        buildAtomic(&file,item);
    }

    file.close();
}
void mainWindow::buildAtomic(QFile * file,atomic * ptr)
{
    QTextStream stream(file);
    stream<<"\n\tvoid function"<<ptr->getId()<<("(int id){\n");
    foreach(port * item,ptr->inputs){buildInput(file,item);}

    stream<<ptr->code;
    stream<<"}\n";
}
void mainWindow::buildInput(QFile * file,port * ptr){
     QTextStream stream(file);
     switch (ptr->valType) {
         case port::Vint:
            stream<<"\t\t int "<<ptr->name<<"=memory["<<ptr->inBlock->getId()<<"]["<<ptr->name<<"].Int;";
            break;
         case port::Vdouble:
            stream<<"\t\t double "<<ptr->name<<"=memory["<<ptr->inBlock->getId()<<"]["<<ptr->name<<"].Double;";
            break;
         case port::Vstring:
            stream<<"\t\t string "<<ptr->name<<"=memory["<<ptr->inBlock->getId()<<"]["<<ptr->name<<"].String;";
            break;
         case port::Vbool:
            stream<<"\t\t bool "<<ptr->name<<"=memory["<<ptr->inBlock->getId()<<"]["<<ptr->name<<"].bool;";
            break;
     }
}

void mainWindow::buildCompozite(QFile * file,compozit * prt)
{

}

void mainWindow::buildHead(QFile * file){
file->write(R""""(#include <algorithm>
#include <iostream>
#include <list>
#include <stdio.h>
#include <string>
#include <string.h>
#include <signal.h>
#include <functional>
#include <QHash>
#include <QDebug>
using namespace std;


enum TypeVal{
    Vint,
    Vdouble,
    Vstring,
    Vbool
};
struct multiVar{
    TypeVal type{Vint};
    int  Int{0};
    double Double{0};
    bool Bool{false};
    string String{""};
};
void callBlock(int id);
QHash<int,QHash<QString,multiVar>> memory;)""""
);
}
void mainWindow::saveBlock(QString path)
{
    if(editingAtom){
        path=path+"/"+editedAtBlock->getName()+".xml";
    }
    else if(viewedBlock==curentApk)
    {
        path=path+"/"+viewedBlock->getName()+".xml";
    }
    else{
        path=path+"/"+viewedBlock->getName()+".xml";
    }
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::information(this, "error", "File cant be opened.");
        return;
    }

    QXmlStreamWriter xmlWriter(&file);
    writer=&xmlWriter;
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    if(editingAtom){
        saveAtom(editedAtBlock,false,false);
    }
    else if(viewedBlock==curentApk)
    {
        saveComp(viewedBlock,false,false,true);
    }
    else{
        saveComp(viewedBlock,false,false,false);
    }

    xmlWriter.writeEndElement();
    file.close();
}
void mainWindow::on_apkSave_clicked(){ on_save_clicked();}
void mainWindow::on_save_clicked()
{
    storMode=true;
    pageHistory= ui->screenSwitch->currentIndex();
    ui->screenSwitch->setCurrentIndex(2);
    ui->catologDisp->setText("store");
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

void mainWindow::saveComp(compozit *ptr, bool saveConnections, bool savePosition,bool apk)
{
    if(apk)
        writer->writeStartElement("aplikation");
    else
        writer->writeStartElement("compositeBlock");
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
    foreach(port * item,ptr->inputs){savePort(item,saveConnections);}
    foreach(port * item,ptr->outputs){savePort(item,saveConnections);}
    foreach(portSocket * item,ptr->insidePorts){saveSocket(item);}
    foreach(atomic * item,ptr->atomVect){saveAtom(item,true,true);}
    foreach(compozit * item,ptr->compVect){saveComp(item,true,true,false);}
    writer->writeEndElement();
}

void mainWindow::saveSocket(portSocket *ptr)
{
    writer->writeStartElement("socket");
    writer->writeAttribute("x",QString::number(ptr->x));
    writer->writeAttribute("y",QString::number(ptr->y));
    writer->writeAttribute("imitating",ptr->imitating->getName());
    if(ptr->imitating->type==port::Pout ){
        writer->writeAttribute("type","input");
        if((ptr->viewedPort->connectedTo!=nullptr)){
            writer->writeAttribute("connectedToBlock",QString::number(ptr->viewedPort->connectedTo->inBlock->getId()));
            writer->writeAttribute("connectedToPort",QString(ptr->viewedPort->connectedTo->getName()));
        }
    }
    else
        writer->writeAttribute("type","output");
    writer->writeEndElement();
}

void mainWindow::savePort(port *ptr,bool saveConnections)
{
     writer->writeStartElement("port");
     writer->writeAttribute("name",ptr->name);
     writer->writeAttribute("constant",ptr->constant);
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

void mainWindow::on_loadApk_clicked(){on_load_clicked();}
void mainWindow::on_load_clicked()
{    
    loadMode=true;
    pageHistory= ui->screenSwitch->currentIndex();
    ui->screenSwitch->setCurrentIndex(2);
    ui->catologDisp->setText("load");
}

void mainWindow::loadBegin(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this, "error", "File cant be opened.");
        return;
    }
    QDomDocument readData;
    readData.setContent(&file);
    QDomElement root=readData.documentElement();
    if((root.tagName()=="atomicBlock")&&(viewedBlock!=nullptr)){
        loadAtom(root,false,false,false,nullptr,viewedBlock);
    }
    else if((root.tagName()=="compositeBlock")&&(viewedBlock!=nullptr)){
        loadComp(root,false,false,false,false,nullptr,viewedBlock);

    }
    else if((root.tagName()=="aplikation")){
        if(curentApk!=NULL)
            delete curentApk;
        this->curentApk=new aplication();
        this->viewedBlock=this->curentApk;
        refresh();
        loadComp(root,false,false,false,true,nullptr,this->curentApk);
        ui->screenSwitch->setCurrentIndex(0);
    }
    else
        QMessageBox::information(this, "error", "Cant load block to empty aplikation .");
    file.close();
    ui->renameApkEdit->setText(curentApk->getName());
    on_goBackFromEditor_clicked();
}
void mainWindow::loadAtom(QDomElement element,bool useIdFromSave,bool usePos,bool loadConnections, QList<connLog> * connections,compozit * placeToLoad){
    atomic * pointer;
    if(!useIdFromSave){
        pointer=placeToLoad->addAtom(curentApk->getNewId());
        pointer->oldId=element.attribute("id","-7").toInt();
    }
    else
        pointer=placeToLoad->addAtom(element.attribute("id","-7").toInt());
    pointer->setName( element.attribute("name",""));
    if(usePos){
        pointer->x= element.attribute("x","0").toInt();
        pointer->y= element.attribute("y","0").toInt();
    }
    QDomElement Component=element.firstChild().toElement();
    while(!Component.isNull()){
        if(Component.tagName()=="code"){
            pointer->code=Component.firstChild().toText().data();
        }
        else if((Component.tagName())=="port"){
            loadPort(Component,pointer,loadConnections,connections);
        }
        else{
            qDebug()<<"unknown element in atomic block";
        }
        Component = Component.nextSibling().toElement();
    }
}

void mainWindow::loadComp(QDomElement element,bool useIdFromSave,bool usePos,bool loadConnections,bool loadingApk,QList<connLog> * list,compozit * placeToLoad)
{
    compozit * pointer;
    if(loadingApk){
        pointer=curentApk;
    }
    else{
        if(!useIdFromSave){
            pointer=placeToLoad->addCompozite(curentApk->getNewId());
            pointer->oldId=element.attribute("id","-7").toInt();
        }
        else
            pointer=placeToLoad->addCompozite(element.attribute("id","-7").toInt());
        if(usePos){
            pointer->x= element.attribute("x","0").toInt();
            pointer->y= element.attribute("y","0").toInt();
        }
    }
    pointer->setName( element.attribute("name",""));
    QList<connLog> connections;
    QDomElement Component=element.firstChild().toElement();
    while(!Component.isNull()){
        if((Component.tagName())=="port"){
            loadPort(Component,pointer,loadConnections,list);
        }
        else if((Component.tagName())=="atomicBlock"){
            loadAtom(Component,false,true,true,&connections,pointer);
        }
        else if((Component.tagName())=="compositeBlock"){
            loadComp(Component, false,true,true,false,&connections,pointer);
        }
        else if((Component.tagName())=="socket"){
            loadSocket(Component,&connections, pointer);
        }
        else{
            qDebug()<<"unknown element in atomic block";
        }
        Component = Component.nextSibling().toElement();
    }
    foreach(connLog item,connections){
        qDebug()<<item.id<<"  "<<item.portName<<"  "<<item.portPtr->name;
        loadConnection(item,pointer);
    }
}
void mainWindow::loadConnection(connLog log,compozit * compPtr){
    port * target=nullptr;
    foreach(atomic * item,compPtr->atomVect){
        if(target)
             break;
        else if(item->oldId==log.id){
            foreach(port * titem,item->outputs){
                if(titem->name==log.portName){
                    target=titem;
                    break;
                }
            }
        }
        else
            continue;
    }
    if(!target){
        foreach(compozit * item,compPtr->compVect){
            if(target)
                 break;
            else if(item->oldId==log.id){
                foreach(port * titem,item->outputs){
                    if(titem->name==log.portName){
                        target=titem;
                        break;
                    }
                }
            }
            else
                continue;
        }
    }
    if(!target){
        foreach(portSocket * item,compPtr->insidePorts){
            if(target)
                 break;
            else if(item->oldId==log.id){
                foreach(port * titem,item->inputs){
                    if(titem->name==log.portName){
                        target=titem;
                        break;
                    }
                }
            }
            else
                continue;
        }
    }

    if(target){
        log.portPtr->connectedTo=target;
        target->PortConnToThis.append(log.portPtr);
    }
    else
        qDebug()<<"connection not found";
}

void mainWindow::loadPort(QDomElement element,block * ptr,bool loadConections, QList<connLog> * connections){
    if(element.tagName()=="port"){
        QString type=element.attribute("type","");
        port * portPtr;
        if(type=="input")
            portPtr=ptr->addPort(true);
        else if(type=="output")
            portPtr=ptr->addPort(false);
        else{
             qDebug()<<"missing port type";
             return;
        }
        portPtr->name=element.attribute("name","name didnt load");
        portPtr->constant=element.attribute("constant","");
        QString valType=element.attribute("valType","");
        if(valType=="int"){
           portPtr->valType=port::Vint;
        }
        else if(valType=="double"){

           portPtr->valType=port::Vdouble;
        }
        else if(valType=="string"){
           portPtr->valType=port::Vstring;
        }
        else if(valType=="bool"){
           portPtr->valType=port::Vbool;
        }
        if(loadConections&&(connections!=nullptr)){
            connLog item;
            QString id=element.attribute("connectedToBlock","NAN");
            QString connectedTo=element.attribute("connectedToPort","");
            if((id!="NAN")&&(connectedTo!="")){
                item.id=id.toInt();
                item.portName=connectedTo;
                item.portPtr=portPtr;
                connections->append(item);
            }
        }
    }
    else
    {
        qDebug()<<"invalid port";
    }
}

void mainWindow::loadSocket(QDomElement element, QList<connLog> * connections, compozit *ptr)
{
    QString nameForSearch=element.attribute("imitating","");

    port * finded=nullptr;
    foreach(port * item,ptr->inputs){
        if(item->name==nameForSearch){
            finded=item;
            break;
        }
    }
    if(!finded){
        foreach(port * item,ptr->outputs){
            if(item->name==nameForSearch){
                finded=item;
                break;
            }
        }
    }
    if(!finded){
        qDebug()<<"for socket is not findet internal reprezentation";
        return;
    }
    portSocket * newSocket=new portSocket(finded);
    connect(newSocket,SIGNAL(destroyed()),this,SLOT(refreshSlot()));
    newSocket->x=element.attribute("x","0").toInt();
    newSocket->y=element.attribute("y","0").toInt();
    ptr->insidePorts.append(newSocket);
    finded->socketPtr=newSocket;

    if(connections!=nullptr){
        connLog item;
        QString id=element.attribute("connectedToBlock","NAN");
        QString connectedTo=element.attribute("connectedToPort","");
        if((id!="NAN")&&(connectedTo!="")){
            item.id=id.toInt();
            item.portName=connectedTo;
            item.portPtr=newSocket->viewedPort;
            connections->append(item);
        }
    }
}

void mainWindow::on_renameApkButt_clicked()
{
   if(curentApk!=nullptr){
       curentApk->setName(ui->renameApkEdit->text());
   }
   else
        QMessageBox::information(this, "error", "Cant rename non existing apk.");
}

void mainWindow::on_treeView_clicked(const QModelIndex &index)     // when user clicks on a node in treeView (extract and set path in listView
{
    QString path = folder -> fileInfo(index).absoluteFilePath();
    workingPath = path;
    ui -> listView -> setRootIndex(file -> setRootPath(path));
}

void mainWindow::on_listView_clicked(const QModelIndex &index)     // get file path when clicked
{
    QString path = file -> fileInfo(index).absoluteFilePath();
}

void mainWindow::on_AddFolderButton_clicked()                      // "Add Category Folder" button
{
      qDebug()<<"tady";
      QString path = QDir::currentPath();                       // path for new folder in 'library'
      path=path+"/examples/";

      QString subpath = workingPath;                            // path for the new SUBfolder in 'library'


      if(workingPath == path)
      {
          QString name = QString ("Category_%1").arg(QDateTime::currentMSecsSinceEpoch());
              while(QDir(name).exists())
              {
                   name = QString ("Category_%1").arg(QDateTime::currentMSecsSinceEpoch());
              }
              QDir(path).mkdir(name);
      }

      else
      {
          QString name = QString ("Category_%1").arg(QDateTime::currentMSecsSinceEpoch());
              while(QDir(name).exists())
              {
                   name = QString ("Category_%1").arg(QDateTime::currentMSecsSinceEpoch());
              }
              QDir(subpath).mkdir(name);
      }
}

void mainWindow::on_RemoveFolderButton_clicked()                    // "Remove Category Folder" button
{
    QString path = QDir::currentPath();                          // path for new folder in 'library'
    path=path+"/examples/";

    QString subpath = workingPath;                               // path for the new SUBfolder in 'library'

    if(workingPath == path)
    {
        QDir dir(path);
        dir.removeRecursively();
    }
    else
    {
        QDir dir(subpath);
        dir.removeRecursively();
    }

}

bool copyDirRecursively(QString sourceFolder, QString destFolder)
{
   bool success = false;
   QDir sourceDir(sourceFolder);

   if(!sourceDir.exists())
       return false;

   QDir destDir(destFolder);
   if(!destDir.exists())
       destDir.mkdir(destFolder);

   QStringList files = sourceDir.entryList(QDir::Files);
   for(int i = 0; i< files.count(); i++) {
       QString srcName = sourceFolder + QDir::separator() + files[i];
       QString destName = destFolder + QDir::separator() + files[i];
       success = QFile::copy(srcName, destName);
       if(!success)
           return false;
   }

   files.clear();
   files = sourceDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
   for(int i = 0; i< files.count(); i++)
   {
       QString srcName = sourceFolder + QDir::separator() + files[i];
       QString destName = destFolder + QDir::separator() + files[i];
       success = copyDirRecursively(srcName, destName);
       if(!success)
           return false;
   }

   return true;
}

void mainWindow::on_RenameCategoryButton_clicked()                  // "ReName Category Folder" button:
{
    //QMessageBox::information(this, "ReName", "Please enter a new name: ");   //TESTING

    QString path = QDir::currentPath();                          // path for new folder in 'library'
    path=path+"/examples/";

    QString subpath = workingPath;                               // path for the new SUBfolder in 'library'

    QString new_name = QInputDialog::getText(this, "Rename Catalog Folder", "Please enter a the new name: ");

    if(workingPath == path)
    {
        QString path_update_final = path + new_name;

        QDir(path).mkdir(new_name);

        copyDirRecursively(path, path_update_final);

        QDir dir(path);
        dir.removeRecursively();
    }

    else
    {
        QString path_update1 = subpath+"/../";
        QString path_update_final = path_update1 + new_name;


        QDir(subpath).mkdir(new_name);

        copyDirRecursively(subpath, path_update_final);

        QDir dir(subpath);
        dir.removeRecursively();
    }
}

void mainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    if(storMode){
        QString path = folder -> fileInfo(index).absoluteFilePath();
        saveBlock(path);
        QMessageBox::information(this, "success", "Block was saved.");
        storMode=false;
    }
}

void mainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    if(loadMode){
        QString path = file -> fileInfo(index).absoluteFilePath();
        if(path.endsWith(".xml")){
            loadingMod=true;
            loadBegin(path);
            loadingMod=false;
            loadMode=false;
            refresh();
            on_goBackFromEditor_clicked();
         }
        else
             QMessageBox::information(this, "error", "Folder cant be loaded");
    }
}

void mainWindow::on_goBackFromEditor_clicked()
{
    ui->screenSwitch->setCurrentIndex(pageHistory);
    loadMode=false;
    storMode=false;
}

