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
    void swich(int page);
    atomic * editedAtBlock;
    void updateAtEditor();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_newApk_clicked();
    void on_loadApk_clicked();
    void on_apkAddAtom_clicked();
    void on_pushButton_4_clicked();
    void on_RenameAtom_clicked();
    void on_AtNameEdit_cursorPositionChanged(int arg1, int arg2);
    void on_pushButton_8_clicked();
    void on_AtAddInput_clicked();
    void on_AtAddOutput_clicked();
private:
    void addAtInput(QWidget * place);
    void removePort();
    aplication * curentApk;
    aplicationView * scene;
    void initView();
    Ui::mainWindow *ui;
    QHash<QPushButton*,QVBoxLayout*>portItemMap;
};
#endif // FILESELECTOR_H
