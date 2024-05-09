/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *leUrlPoslat;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *leNadpis;
    QLabel *label_2;
    QLineEdit *leObsah;
    QPushButton *pbOdeslat;
    QTextEdit *teOdpoved;
    QWidget *tab2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *leUrlNacist;
    QPushButton *pbNacti;
    QTextEdit *teJSON;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab1 = new QWidget();
        tab1->setObjectName("tab1");
        verticalLayout_3 = new QVBoxLayout(tab1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        leUrlPoslat = new QLineEdit(tab1);
        leUrlPoslat->setObjectName("leUrlPoslat");

        verticalLayout_3->addWidget(leUrlPoslat);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(tab1);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        leNadpis = new QLineEdit(tab1);
        leNadpis->setObjectName("leNadpis");

        gridLayout_2->addWidget(leNadpis, 0, 1, 1, 1);

        label_2 = new QLabel(tab1);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        leObsah = new QLineEdit(tab1);
        leObsah->setObjectName("leObsah");

        gridLayout_2->addWidget(leObsah, 1, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        pbOdeslat = new QPushButton(tab1);
        pbOdeslat->setObjectName("pbOdeslat");

        verticalLayout_3->addWidget(pbOdeslat);

        teOdpoved = new QTextEdit(tab1);
        teOdpoved->setObjectName("teOdpoved");

        verticalLayout_3->addWidget(teOdpoved);

        QIcon icon(QIcon::fromTheme(QString::fromUtf8("mail-send")));
        tabWidget->addTab(tab1, icon, QString());
        tab2 = new QWidget();
        tab2->setObjectName("tab2");
        verticalLayout_2 = new QVBoxLayout(tab2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        leUrlNacist = new QLineEdit(tab2);
        leUrlNacist->setObjectName("leUrlNacist");

        gridLayout->addWidget(leUrlNacist, 0, 0, 1, 1);

        pbNacti = new QPushButton(tab2);
        pbNacti->setObjectName("pbNacti");

        gridLayout->addWidget(pbNacti, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        teJSON = new QTextEdit(tab2);
        teJSON->setObjectName("teJSON");
        teJSON->setReadOnly(true);

        verticalLayout_2->addWidget(teJSON);

        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("mail-send-receive")));
        tabWidget->addTab(tab2, icon1, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        leUrlPoslat->setText(QCoreApplication::translate("MainWindow", "https://poznamky.cokoliv.eu/api/pridat", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nadpis", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Obsah", nullptr));
        pbOdeslat->setText(QCoreApplication::translate("MainWindow", "Odeslat", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QCoreApplication::translate("MainWindow", "Po\305\241li", nullptr));
        leUrlNacist->setText(QCoreApplication::translate("MainWindow", "https://poznamky.cokoliv.eu/seznam", nullptr));
        pbNacti->setText(QCoreApplication::translate("MainWindow", "Na\304\215\303\255st", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QCoreApplication::translate("MainWindow", "Na\304\215ti", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
