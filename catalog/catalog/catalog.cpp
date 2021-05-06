#include "catalog.h"
#include "ui_catalog.h"

#include <QtWidgets>


catalog::catalog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::catalog)
{
    ui->setupUi(this);

    //--------------------------------------------
  //___{FIX TO SHOW ONLY WHAT IS IN THE LIBRARY FOLDER}_______
    QProcess getpath;
    QStringList commands;
    commands <<  "cd .." << "cd .." << "cd library" ;
    getpath.start(QDir::currentPath(), commands);           // (...ICP-2021\catalog\build-catalog-Desktop_Qt_5_15_2_MinGW_64_bit-Debug) -> (...ICP-2021\library)

    getpath.waitForFinished();

  //QString iferror = getpath.readAllStandardError();
    QString path = QDir::currentPath();                     // file system needs rootpath = main "library" folder

 //___
    folder = new QFileSystemModel(this);                        // create the new model
    folder -> setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);  // show only directories (hide other)
    folder -> setRootPath(path);                                // populate (folder) model (using set rootpath)
    ui -> treeView -> setModel(folder);

    QModelIndex index = folder->index(path, 0);
    ui->treeView->setRootIndex(index);


    file = new QFileSystemModel(this);
    file -> setFilter(QDir::NoDotAndDotDot | QDir::Files);    // show only files
    file -> setRootPath(path);
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
    ui -> listView -> setRootIndex(file -> setRootPath(path));
}
//--------------------------------------------
