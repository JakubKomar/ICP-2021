/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Main UI
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#ifndef mainWindow_H
#define mainWindow_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QObject>
#include <qdebug.h>
#include <QComboBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QXmlStreamWriter>
#include <QtXml>
#include <QDir>
#include <QDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileSystemModel>
#include <stdio.h>
#include <cstdio>

#include  "./gui/aplicationview.h"
#include  "./gui/portlayout.h"
#include  "./core/aplication.h"
#include  "./core/atomic.h"
#include  "./core/port.h"
#include  "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class aplicationView;
class mainWindow : public QMainWindow
{
Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();
    /**
     * swich ui to page from arg
     * @arg page - number of page to swich
    */
    void primarySwich(int page);
    /**
     * swich ui to page from arg - editing atomic /editing compozite
     * @arg page - number of page to swich
    */
    void secondarySwich(int page); 
    /**
     * deleting block from core
     * @arg pointer to deleted block
    */
    void deleteExactBlock(block *ptr);
    /**
     * pushing actual edited block to call stack
    */
    void callBackPush();
    /**
     * poping actual edited block to call stack
    */
    void callBackPop();
    /**
     * swich edited block
     * @arg pointer to new edited block
    */
    void swichToComp(compozit * targetPtr);
    /**
     * swich edited block
     * @arg pointer to new edited block
    */
    void swichToAtomic(atomic * targetPtr);
    /**
     * delete all graphic object of block and connections and reloding them
    */
    void refresh();
    /**
     * update editor before swiching to this page
    */
    void updateAtEditor();
    /**
     * saving atomic block to xml file
     * @param ptr-poiter to block which will be saved
     * @param saveConnections-save relation between blocks
     * @param saveposition- saving position in graphic scene
    */
    void saveAtom(atomic *ptr,bool saveConnections,bool savePosition);
    /**
     * saving atomic block to xml file
     * @param ptr-poiter to block which will be saved
     * @param saveConnections-save relation between blocks
     * @param saveposition- saving position in graphic scene
    */
    void saveBlock(QString path);
    /**
     * master swich for saving methods
     * @param path to where is block to be saved
    */
    void saveSocket(portSocket * ptr);
    /**
     * saving compozite block to xml file
     * @param ptr-poiter to block which will be saved
     * @param saveConnections-save relation between blocks
     * @param saveposition- saving position in graphic scene
    */
    void saveComp(compozit * ptr,bool saveConnections,bool savePosition,bool apk);
    /**
     * saving port to xml file
     * @param ptr-poiter to port which will be saved
     * @param saveConnections-save relation between blocks
    */
    void savePort(port *ptr,bool saveConnections);
    struct connLog{
        port * portPtr;
        int id;
        QString portName;
    };
    /**
     * loading atomic block from xml file
     * @param element-xml var where is  block saved
     * @param useIdFromSav-use id from the file
     * @param usePos- chose if position in scene is loaded to block
     * @param loadConnections- chozing if the connections are loaded
     * @param connections- pointer to list of connections
     * @param placeToLoad- where is blocked saved after load
    */
    void loadAtom(QDomElement element,bool useIdFromSav,bool usePos,bool loadConnections, QList<connLog> * connections,compozit * placeToLoad);
    /**
     * master loading switch - chozing how is block to be loaded
     * @param path-where is file saved
    */
    void loadBegin(QString path);
    /**
     * loading compozite block from xml file
     * @param element-xml var where is  block saved
     * @param useIdFromSav-use id from the file
     * @param usePos- chose if position in scene is loaded to block
     * @param usePos- where is blocked saved after load
    */
    void loadComp(QDomElement element,bool useIdFromSave,bool usePos,bool loadConnections,bool loadingApk, QList<connLog> * masterTable,compozit * placeToLoad);
    /**
     * loading port from xml file
     * @param element-xml var where is  block saved
     * @param ptr to block where port is to be loaded
     * @param loadConnections- chozing if the connections are loaded
     * @param connections- pointer to list of connections
    */
    void loadPort(QDomElement element,block * ptr,bool loadConections, QList<connLog> * connections);
    /**
     * loading socket from xml file
     * @param element-xml var where is  block saved
     * @param connections- pointer to list of connections
     * @param ptr- pointer to compozit block where is saved
    */
    void loadSocket(QDomElement element, QList<connLog> * connections,compozit * ptr);
    /**
     * loading socket from xml file
     * @param log-list of connections to be proccesed
     * @param compPtr- in which block the connection will be proccesed
    */
    void loadConnection(connLog log,compozit * compPtr);
    compozit * viewedBlock;
    bool destructorMod{false};
    bool loadingMod{false};
    QXmlStreamWriter * writer; 

    QString workingPath{""};
private slots:
    void refreshSlot();
    void on_newApk_clicked();
    void on_loadApk_clicked();
    void on_apkAddAtom_clicked();
    void on_addCompozite_clicked();
    void on_renameBlock_clicked();
    void on_pushButton_8_clicked();
    void on_AtAddInput_clicked();
    void on_AtAddOutput_clicked();
    void on_goBack_clicked();
    void on_addAtomic2_clicked();
    void on_AddComp2_clicked();
    void on_undo_clicked();
    void on_redo_clicked();
    void on_Build_clicked();
    void on_save_clicked();
    void on_load_clicked();
    void on_apkSave_clicked();
    void on_renameApkButt_clicked();

    void on_AddFolderButton_clicked();
    void on_RemoveFolderButton_clicked();
    void on_RenameCategoryButton_clicked();
    void on_treeView_clicked(const QModelIndex &index);
    void on_listView_clicked(const QModelIndex &index);

    void on_treeView_doubleClicked(const QModelIndex &index);
    void on_listView_doubleClicked(const QModelIndex &index);
    void on_goBackFromEditor_clicked();

private:
    /**
     * ading input to frame
     * @param place - where to put the new port
    */
    void addAtInput(QWidget * place);
    /**
     * removing all elements from port grapohic rep.
    */
    void removePort();
    /**
     * clearing all layouts for port editing
    */
    void clearPortLayouts();
    /**
     * deleting all layouts for port editing and relode new
    */
    void refreshPorts();
    /**
     * interpreting atomic block
     * @param file-file to writing
     * @param ptr-pointer to atomic block which will be interpreted
    */
    void buildAtomic(QFile * file,atomic * prt);
    /**
     * interpreting function
     * @param file-file to writing
     * @param ptr-pointer to composite block which will be interpreted
    */
    void buildCompozite(QFile * file,compozit * prt);
    /**
     * creating header of interpreting code
     * @param file-file to writing
    */
    void buildHead(QFile* file);
    void buildSwitch(QFile* file,compozit * prt);
    void buildCases(QFile *file, compozit *prt);
    void buildFillHashTable(QFile * file,compozit * ptr);
    /**
     * interpreting function
     * @param file-file to writing
     * @param ptr-pointer to port which will be interpreted
    */
    void buildInput(QFile * file,port * ptr);
    void buildOutput(QFile * file,port * ptr);
    QStack<compozit*> callBackStack;
    aplication * curentApk{nullptr};
    block * editedBlock{nullptr};
    atomic * editedAtBlock{nullptr};
    aplicationView * scene;
    Ui::mainWindow *ui;
    bool editingAtom{false};
    QList <portLayout*> layoutList;

    QFileSystemModel *folder;   // folder model = display folders
    QFileSystemModel *file;     // file model = display files
    bool loadMode{false};
    bool storMode{false};
    int pageHistory{0};
};
#endif // FILESELECTOR_H
