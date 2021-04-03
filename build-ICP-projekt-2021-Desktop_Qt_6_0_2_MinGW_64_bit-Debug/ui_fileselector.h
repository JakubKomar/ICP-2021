/********************************************************************************
** Form generated from reading UI file 'fileselector.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESELECTOR_H
#define UI_FILESELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileSelector
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QStackedWidget *screenSwitch;
    QWidget *fileSelector_2;
    QHBoxLayout *horizontalLayout_9;
    QTreeView *treeView;
    QWidget *apkEditor;
    QHBoxLayout *horizontalLayout_8;
    QGraphicsView *apkView;
    QWidget *compoziteEditor;
    QHBoxLayout *horizontalLayout_6;
    QListView *listView_3;
    QGraphicsView *compoziteView;
    QListView *listView_4;
    QWidget *atomEditor;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *load;
    QPushButton *save;
    QPushButton *undo;
    QPushButton *redo;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QListView *listView;
    QPlainTextEdit *plainTextEdit;
    QListView *listView_2;

    void setupUi(QMainWindow *fileSelector)
    {
        if (fileSelector->objectName().isEmpty())
            fileSelector->setObjectName(QString::fromUtf8("fileSelector"));
        fileSelector->resize(910, 581);
        centralwidget = new QWidget(fileSelector);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_4);

        screenSwitch = new QStackedWidget(centralwidget);
        screenSwitch->setObjectName(QString::fromUtf8("screenSwitch"));
        fileSelector_2 = new QWidget();
        fileSelector_2->setObjectName(QString::fromUtf8("fileSelector_2"));
        horizontalLayout_9 = new QHBoxLayout(fileSelector_2);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        treeView = new QTreeView(fileSelector_2);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        horizontalLayout_9->addWidget(treeView);

        screenSwitch->addWidget(fileSelector_2);
        apkEditor = new QWidget();
        apkEditor->setObjectName(QString::fromUtf8("apkEditor"));
        horizontalLayout_8 = new QHBoxLayout(apkEditor);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        apkView = new QGraphicsView(apkEditor);
        apkView->setObjectName(QString::fromUtf8("apkView"));

        horizontalLayout_8->addWidget(apkView);

        screenSwitch->addWidget(apkEditor);
        compoziteEditor = new QWidget();
        compoziteEditor->setObjectName(QString::fromUtf8("compoziteEditor"));
        horizontalLayout_6 = new QHBoxLayout(compoziteEditor);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        listView_3 = new QListView(compoziteEditor);
        listView_3->setObjectName(QString::fromUtf8("listView_3"));
        listView_3->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(listView_3);

        compoziteView = new QGraphicsView(compoziteEditor);
        compoziteView->setObjectName(QString::fromUtf8("compoziteView"));

        horizontalLayout_6->addWidget(compoziteView);

        listView_4 = new QListView(compoziteEditor);
        listView_4->setObjectName(QString::fromUtf8("listView_4"));
        listView_4->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(listView_4);

        screenSwitch->addWidget(compoziteEditor);
        atomEditor = new QWidget();
        atomEditor->setObjectName(QString::fromUtf8("atomEditor"));
        horizontalLayout = new QHBoxLayout(atomEditor);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        load = new QPushButton(atomEditor);
        load->setObjectName(QString::fromUtf8("load"));

        horizontalLayout_2->addWidget(load);

        save = new QPushButton(atomEditor);
        save->setObjectName(QString::fromUtf8("save"));

        horizontalLayout_2->addWidget(save);

        undo = new QPushButton(atomEditor);
        undo->setObjectName(QString::fromUtf8("undo"));

        horizontalLayout_2->addWidget(undo);

        redo = new QPushButton(atomEditor);
        redo->setObjectName(QString::fromUtf8("redo"));

        horizontalLayout_2->addWidget(redo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        listView = new QListView(atomEditor);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(listView);

        plainTextEdit = new QPlainTextEdit(atomEditor);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout_5->addWidget(plainTextEdit);

        listView_2 = new QListView(atomEditor);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        listView_2->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(listView_2);


        verticalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout->addLayout(verticalLayout_4);

        screenSwitch->addWidget(atomEditor);

        verticalLayout_3->addWidget(screenSwitch);

        fileSelector->setCentralWidget(centralwidget);

        retranslateUi(fileSelector);

        screenSwitch->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(fileSelector);
    } // setupUi

    void retranslateUi(QMainWindow *fileSelector)
    {
        fileSelector->setWindowTitle(QCoreApplication::translate("fileSelector", "fileSelector", nullptr));
        pushButton_2->setText(QCoreApplication::translate("fileSelector", "next Page", nullptr));
        pushButton->setText(QCoreApplication::translate("fileSelector", "pre Page", nullptr));
        load->setText(QCoreApplication::translate("fileSelector", "load", nullptr));
        save->setText(QCoreApplication::translate("fileSelector", "save", nullptr));
        undo->setText(QCoreApplication::translate("fileSelector", "undo", nullptr));
        redo->setText(QCoreApplication::translate("fileSelector", "redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fileSelector: public Ui_fileSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESELECTOR_H
