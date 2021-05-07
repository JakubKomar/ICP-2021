#include "catalog.h"
#include "ui_catalog.h"

#include <QtWidgets>
#include <QDebug>

catalog::catalog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::catalog)
{
    ui->setupUi(this);

    //--------------------------------------------
    QString path = QDir::currentPath();
    path=path+"/../../library/";
    qDebug()<<path;


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

    QDir libdir(path);
    QString filter = "*.xml";
    libdir.setNameFilters(filter.split(' '));

/*
    QStringList nameFilter("*.xml");
    QDir libdir(path);
    QStringList FilesAndDirectories = libdir.entryList(nameFilter);
*/


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
