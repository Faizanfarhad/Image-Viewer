/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton4;

    void setupUi(QMainWindow *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QString::fromUtf8("ImageViewer"));
        ImageViewer->resize(800, 600);
        actionExit = new QAction(ImageViewer);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(ImageViewer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton1 = new QPushButton(centralWidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setGeometry(QRect(10, 1, 65, 20));
        pushButton2 = new QPushButton(centralWidget);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        pushButton2->setGeometry(QRect(80, 1, 75, 20));
        pushButton3 = new QPushButton(centralWidget);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));
        pushButton3->setGeometry(QRect(155, 1, 65, 20));
        pushButton4 = new QPushButton(centralWidget);
        pushButton4->setObjectName(QString::fromUtf8("pushButton4"));
        pushButton4->setGeometry(QRect(220, 1, 65, 20));
        ImageViewer->setCentralWidget(centralWidget);

        retranslateUi(ImageViewer);

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ImageViewer)
    {
        ImageViewer->setWindowTitle(QCoreApplication::translate("MainWindow", "Image viewer", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        centralWidget->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                    QWidget#centralWidget {\n"
"                        background-color: white;\n"
"                    }\n"
"                    QPushButton#pushButton1 {\n"
"                        background-color: red;\n"
"                        color: white;\n"
"                        margin: 1px;\n"
"                        padding: 1px;\n"
"                        border-radius: 3px;\n"
"                    }\n"
"                    QPushButton#pushButton2 {\n"
"                        background-color: green;\n"
"                        color: white;\n"
"                        margin: 1px;\n"
"                        padding: 1px;\n"
"                        border-radius: 3px;\n"
"                    }\n"
"                    QPushButton#pushButton3 {\n"
"                        background-color: blue;\n"
"                        color: white;\n"
"                        margin: 1px;\n"
"                        padding: 1px;\n"
"                        border-radius: 3px;\n"
"                "
                        "    }\n"
"                    QPushButton#pushButton4 {\n"
"                        background-color: yellow;\n"
"                        color: black;\n"
"                        margin: 1px;\n"
"                        padding: 1px;\n"
"                        border-radius: 3px;\n"
"                    }\n"
"                ", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
        pushButton2->setText(QCoreApplication::translate("MainWindow", "zoom Out", nullptr));
        pushButton3->setText(QCoreApplication::translate("MainWindow", "Files", nullptr));
        pushButton4->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
