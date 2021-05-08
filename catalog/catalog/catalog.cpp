#include "catalog.h"
#include "ui_catalog.h"

#include <QtWidgets>
#include <QDebug>
#include  <QMessageBox>  // for testing

catalog::catalog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::catalog)
{
    ui->setupUi(this);

    //--------------------------------------------
    QString path = QDir::currentPath();
    path=path+"/../../library/";                                // rootfolder to display = library folder



    folder = new QFileSystemModel(this);                        // create the new model
    folder -> setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);  // show only directories (hide other)
    folder -> setRootPath(path);                                // populate (folder) model (using set rootpath)
    ui -> treeView -> setModel(folder);

    QModelIndex index = folder->index(path, 0);
    ui->treeView->setRootIndex(index);

    //
    //connect(ui->AddFolderButton, SIGNAL(clicked), this, SLOT(on_treeView_clicked));
    //





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
    //qDebug()<<path;
    ui -> listView -> setRootIndex(file -> setRootPath(path));
}
//--------------------------------------------

void catalog::on_listView_clicked(const QModelIndex &index)     // get file path when clicked
{
    QString path = file -> fileInfo(index).absoluteFilePath();
    qDebug()<<path;
}

//--------------------------------------------


void catalog::on_AddFolderButton_clicked()                      // "Add Category Folder" button:
{
      QMessageBox::information(this, "Title Here", "ADD");   //TESTING

      QString path = QDir::currentPath();                                   // path for new folder in 'library'
      path=path+"/../../library/";


      // must know where to create the new folder:
      //   (click on folder to make subfolder or just click add to add in library):

      QModelIndex index = folder->index(path, 0);

      QString subpath = folder -> fileInfo(index).absoluteFilePath();       // path for the new SUBfolder in 'library'
      qDebug()<<subpath;


// attempts....
      // on_listView_clicked(index);

      //QString subpath = folder -> fileInfo(this->ui->treeView->indexAt(folder).data()).absoluteFilePath();

      //QString subpath = on_treeView_clicked(/*const QModelIndex &index*/);  // call to get folder 'click path' for the new subfolder

      //void itemClicked(QTreeWidgetItem* item);




// if click = path-> add to library, else take subpath:
//if clicked == path    QDir dir(path);...
// else                 QDir dir(subpath);...

/*
      QDir dir(path);       // new folder in 'library'

      if (!dir.exists("Category"))
          dir.mkpath(".");  //note: default name (if exists add counter +1 to the name) -> user must rename it
*/

      QString name = QString ("Category %1").arg(QDateTime::currentMSecsSinceEpoch());
          while(QDir(name).exists())
          {
               name = QString ("Category %1").arg(QDateTime::currentMSecsSinceEpoch());
          }
          QDir(path).mkdir(name);

}









void catalog::on_RemoveFolderButton_clicked()                               // "Remove Category Folder" button:
{
      QMessageBox::information(this, "Title Here", "REMOVE :)");   //TESTING

      //TODO
      // clicked folder = subpath
}






// doubleclick->file open (load into ???)
// TODO
//--------------------------------------------






