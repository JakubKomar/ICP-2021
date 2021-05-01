/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Main
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;
    w.show();
    return a.exec();
}
