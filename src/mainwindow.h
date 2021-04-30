#ifndef mainWindow_H
#define mainWindow_H

#include <QMainWindow>
#include  "./gui/aplicationview.h"
#include  "./core/aplication.h"
#include  "./core/atomic.h"
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
    void kek();
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

private:
    aplication * curentApk;
    aplicationView * scene;
    void initView();
    Ui::mainWindow *ui;
};
#endif // FILESELECTOR_H
