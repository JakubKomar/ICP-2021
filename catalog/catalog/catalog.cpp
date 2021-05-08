#include "catalog.h"
#include "ui_catalog.h"

#include <stdio.h>
#include <cstdio>

#include <QtWidgets>
#include <QDebug>


catalog::catalog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::catalog)
{
    ui->setupUi(this);

    //--------------------------------------------
    QString path = QDir::currentPath();
    path=path+"/../../library/";                                // rootfolder to display = library folder
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
    //--------------------------------------------
}

catalog::~catalog()
{
    delete ui;
}



//--------------------------------------------
void catalog::on_treeView_clicked(const QModelIndex &index)     // when user clicks on a node in treeView (extract and set path in listView
{
    QString path = folder -> fileInfo(index).absoluteFilePath();
    workingPath = path;
    ui -> listView -> setRootIndex(file -> setRootPath(path));
}
//--------------------------------------------

void catalog::on_listView_clicked(const QModelIndex &index)     // get file path when clicked
{
    QString path = file -> fileInfo(index).absoluteFilePath();
    qDebug()<<path;
}
//--------------------------------------------

void catalog::on_AddFolderButton_clicked()                      // "Add Category Folder" button
{
      QString path = QDir::currentPath();                       // path for new folder in 'library'
      path=path+"/../../library/";

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




void catalog::on_RemoveFolderButton_clicked()                    // "Remove Category Folder" button
{
    QString path = QDir::currentPath();                          // path for new folder in 'library'
    path=path+"/../../library/";

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
//--------------------------------------------

bool copyDirRecursively(QString sourceFolder, QString destFolder)       // function to copy a folder's contents into another folder (if it doesn't exist, it is created)
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



void catalog::on_RenameCategoryButton_clicked()                  // "ReName Category Folder" button (WARNING: do not click without selecting a folder or library is deleted)
{
    QString path = QDir::currentPath();                          // path for new folder in 'library'
    path=path+"/../../library/";

    QString subpath = workingPath;                               // path for the new SUBfolder in 'library'





    QString new_name = QInputDialog::getText(this, "Rename Catalog Folder", "Please enter a the new name: ");


    if(workingPath == path)
    {
        QString path_update_final = path + new_name;


        copyDirRecursively(path, path_update_final);

        QDir dir(path);
        dir.removeRecursively();
    }

    else
    {
        QString path_update1 = subpath+"/../";
        QString path_update_final = path_update1 + new_name;


        copyDirRecursively(subpath, path_update_final);

        QDir dir(subpath);
        dir.removeRecursively();
    }

}



// doubleclick->file open (load into ???)
// TODO
//--------------------------------------------









