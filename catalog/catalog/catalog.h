#ifndef CATALOG_H
#define CATALOG_H

#include <QMainWindow>

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QDir>
#include <QListWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>



QT_BEGIN_NAMESPACE
namespace Ui { class catalog; }

QT_END_NAMESPACE

class catalog : public QMainWindow
{
    Q_OBJECT

public:
    catalog(QWidget *parent = nullptr);
    ~catalog();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);





    void on_AddFolderButton_clicked();

    void on_RemoveFolderButton_clicked();

private:
    Ui::catalog *ui;

    //---------------------------------------------
    QFileSystemModel *folder;   // folder model = display folders
    QFileSystemModel *file;     // file model = display files
    //---------------------------------------------
};

#endif // CATALOG_H

