#include "fileselector.h"
#include "ui_fileselector.h"
#include <qdebug.h>
fileSelector::fileSelector(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fileSelector)
{
    ui->setupUi(this);
}

fileSelector::~fileSelector()
{
    delete ui;
}


void fileSelector::on_pushButton_2_clicked()
{
    ui->screenSwitch->setCurrentIndex( (ui->screenSwitch->currentIndex())-1 );
}

void fileSelector::on_pushButton_clicked()
{
    ui->screenSwitch->setCurrentIndex( (ui->screenSwitch->currentIndex())+1 );
}
