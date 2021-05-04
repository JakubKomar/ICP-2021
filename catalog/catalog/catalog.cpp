#include "catalog.h"
#include "ui_catalog.h"

catalog::catalog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::catalog)
{
    ui->setupUi(this);
}

catalog::~catalog()
{
    delete ui;
}

