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
    qDebug()<<path;



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
    qDebug()<<path;
    ui -> listView -> setRootIndex(file -> setRootPath(path));
}
//--------------------------------------------

//--------------------------------------------
void catalog::on_listView_clicked(const QModelIndex &index)     // get file path when clicked
{
    QString path = file -> fileInfo(index).absoluteFilePath();
    qDebug()<<path;
}



// "Add Category Folder" button:

    // TODO
    //QString path = QDir::currentPath();
    //path=path+"/../../library/";


    //QString subpath = on_treeView_clicked(/*const QModelIndex &index*/);  // call to get folder 'click path' for the new subfolder



/* // if click = path-> add to library, else take subpath

    //if clicked == path    QDir dir(path);...
    // else                 QDir dir(subpath);...

    QDir dir(path);
    dir.mkdir("m_Name");  //note: default name (if exists add counter +1 to the name) -> user must rename it
                          // + must know where to create it
                          //   (click on folder to make subfolder or just click add to add in library)
*/











// "Remove Category Folder" button:








// doubleclick->file open (load into ???)
// TODO
//--------------------------------------------



void catalog::on_AddFolderButton_clicked()
{
      QMessageBox::information(this, "Title Here", "ADD");
}

void catalog::on_RemoveFolderButton_clicked()
{
      QMessageBox::information(this, "Title Here", "REMOVE :)");
}
