/********************************************************************************
** Form generated from reading UI file 'fileselector.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Build;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSlider *horizontalSlider;
    QGraphicsView *apkView;
    QWidget *compoziteEditor;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout_7;
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
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Build = new QPushButton(apkEditor);
        Build->setObjectName(QString::fromUtf8("Build"));

        horizontalLayout_3->addWidget(Build);

        pushButton_3 = new QPushButton(apkEditor);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(apkEditor);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_3->addWidget(pushButton_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label = new QLabel(apkEditor);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSlider = new QSlider(apkEditor);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);


        verticalLayout->addLayout(horizontalLayout_3);

        apkView = new QGraphicsView(apkEditor);
        apkView->setObjectName(QString::fromUtf8("apkView"));

        verticalLayout->addWidget(apkView);


        horizontalLayout_8->addLayout(verticalLayout);

        screenSwitch->addWidget(apkEditor);
        compoziteEditor = new QWidget();
        compoziteEditor->setObjectName(QString::fromUtf8("compoziteEditor"));
        horizontalLayout_6 = new QHBoxLayout(compoziteEditor);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_5 = new QPushButton(compoziteEditor);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_10->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(compoziteEditor);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_10->addWidget(pushButton_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        label_2 = new QLabel(compoziteEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_10->addWidget(label_2);

        horizontalSlider_2 = new QSlider(compoziteEditor);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        sizePolicy.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(horizontalSlider_2);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        listView_3 = new QListView(compoziteEditor);
        listView_3->setObjectName(QString::fromUtf8("listView_3"));
        listView_3->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_7->addWidget(listView_3);

        compoziteView = new QGraphicsView(compoziteEditor);
        compoziteView->setObjectName(QString::fromUtf8("compoziteView"));

        horizontalLayout_7->addWidget(compoziteView);

        listView_4 = new QListView(compoziteEditor);
        listView_4->setObjectName(QString::fromUtf8("listView_4"));
        listView_4->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_7->addWidget(listView_4);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_6->addLayout(verticalLayout_2);

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

        screenSwitch->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(fileSelector);
    } // setupUi

    void retranslateUi(QMainWindow *fileSelector)
    {
        fileSelector->setWindowTitle(QCoreApplication::translate("fileSelector", "fileSelector", nullptr));
        pushButton_2->setText(QCoreApplication::translate("fileSelector", "next Page", nullptr));
        pushButton->setText(QCoreApplication::translate("fileSelector", "prev Page", nullptr));
        Build->setText(QCoreApplication::translate("fileSelector", "Build", nullptr));
        pushButton_3->setText(QCoreApplication::translate("fileSelector", "Add Atomic", nullptr));
        pushButton_4->setText(QCoreApplication::translate("fileSelector", "Add Compozit", nullptr));
        label->setText(QCoreApplication::translate("fileSelector", "Zoom", nullptr));
        pushButton_5->setText(QCoreApplication::translate("fileSelector", "Add atomic", nullptr));
        pushButton_6->setText(QCoreApplication::translate("fileSelector", "Add compozit", nullptr));
        label_2->setText(QCoreApplication::translate("fileSelector", "Zoom", nullptr));
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
