#ifndef mainWindow_H
#define mainWindow_H

#include <QMainWindow>
#include  "./gui/aplicationview.h"
#include  "./core/aplikation.h"
QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    void initView();
    void createNewAp(QString name);
    Ui::mainWindow *ui;
    aplikation * currentAp=NULL;

};
#endif // FILESELECTOR_H
