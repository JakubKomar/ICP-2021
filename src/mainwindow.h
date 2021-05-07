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
#include <QMessageBox>

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
    compozit * viewedBlock;
    bool destructorMod{false};
    void saveAtom(atomic *ptr,bool saveConnections,bool savePosition);
    void savePort(port *ptr,bool saveConnections);
    void loadAtom(QDomElement element,bool useIdFromSav,bool usePos);
    void loadPort(QDomElement element,atomic * ptr,bool loadConections);
    QXmlStreamWriter * writer;
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
    QStack<compozit*> callBackStack;
    aplication * curentApk;
    block * editedBlock;
    atomic * editedAtBlock;
    aplicationView * scene;
    Ui::mainWindow *ui;
    bool editingAtom{false};
    /**
     * clearing all layouts for port editing
    */
    void clearPortLayouts();
    /**
     * deleting all layouts for port editing and relode new
    */
    void refreshPorts();
    /**
     * interpreting function
    */
    void buildAtomic(atomic * prt);
    /**
     * interpreting function
    */
    void buildCompozite(compozit * prt);
    /**
     * interpreting function
    */
    void buildHeader(compozit * prt);
    QList <portLayout*> layoutList;
};
#endif // FILESELECTOR_H
