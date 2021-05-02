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

#include  "./gui/aplicationview.h"
#include  "./core/aplication.h"
#include  "./core/atomic.h"
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
    void secondarySwich(int page); 
    void deleteExactBlock(block *ptr);
    void callBackPush();
    void callBackPop();
    void swichToComp(compozit * targetPtr);
    void swichToAtomic(atomic * targetPtr);
    void refresh();
    /**
     * update editor before swiching to this page
    */
    void updateAtEditor();
private slots:
    void on_newApk_clicked();
    void on_loadApk_clicked();
    void on_apkAddAtom_clicked();
    void on_addCompozite_clicked();
    void on_renameBlock_clicked();
    void on_AtNameEdit_cursorPositionChanged(int arg1, int arg2);
    void on_pushButton_8_clicked();
    void on_AtAddInput_clicked();
    void on_AtAddOutput_clicked();
    void on_goBack_clicked();
    void on_addAtomic2_clicked();
    void on_AddComp2_clicked();

    void on_undo_clicked();

    void on_redo_clicked();

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
    compozit * viewedBlock;
    aplicationView * scene;
    Ui::mainWindow *ui;
    QHash<QPushButton*,QVBoxLayout*>portItemMap;
};
#endif // FILESELECTOR_H
