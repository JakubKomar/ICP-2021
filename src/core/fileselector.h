#ifndef FILESELECTOR_H
#define FILESELECTOR_H

#include <QMainWindow>
#include  "./gui/aplicationview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class fileSelector; }
QT_END_NAMESPACE

class fileSelector : public QMainWindow
{
    Q_OBJECT

public:
    fileSelector(QWidget *parent = nullptr);
    ~fileSelector();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    void initView();
    Ui::fileSelector *ui;
};
#endif // FILESELECTOR_H
