#ifndef CATALOG_H
#define CATALOG_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class catalog; }
QT_END_NAMESPACE

class catalog : public QMainWindow
{
    Q_OBJECT

public:
    catalog(QWidget *parent = nullptr);
    ~catalog();

private:
    Ui::catalog *ui;
};
#endif // CATALOG_H
