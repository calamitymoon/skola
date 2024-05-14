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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNova;
    QAction *actionPridat;
    QAction *actionOtevrit;
    QAction *actionKonec;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *vyhledavac;
    QLineEdit *leVyhledavac;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menuSoubor;
    QMenu *menuZ_znam;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNova = new QAction(MainWindow);
        actionNova->setObjectName("actionNova");
        actionPridat = new QAction(MainWindow);
        actionPridat->setObjectName("actionPridat");
        actionOtevrit = new QAction(MainWindow);
        actionOtevrit->setObjectName("actionOtevrit");
        actionKonec = new QAction(MainWindow);
        actionKonec->setObjectName("actionKonec");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        vyhledavac = new QLabel(centralwidget);
        vyhledavac->setObjectName("vyhledavac");

        horizontalLayout->addWidget(vyhledavac);

        leVyhledavac = new QLineEdit(centralwidget);
        leVyhledavac->setObjectName("leVyhledavac");
        leVyhledavac->setContextMenuPolicy(Qt::DefaultContextMenu);

        horizontalLayout->addWidget(leVyhledavac);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(tableView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuSoubor = new QMenu(menubar);
        menuSoubor->setObjectName("menuSoubor");
        menuZ_znam = new QMenu(menubar);
        menuZ_znam->setObjectName("menuZ_znam");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSoubor->menuAction());
        menubar->addAction(menuZ_znam->menuAction());
        menuSoubor->addAction(actionNova);
        menuSoubor->addAction(actionOtevrit);
        menuSoubor->addSeparator();
        menuSoubor->addAction(actionKonec);
        menuZ_znam->addAction(actionPridat);

        retranslateUi(MainWindow);
        QObject::connect(actionKonec, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNova->setText(QCoreApplication::translate("MainWindow", "Nov\303\241", nullptr));
#if QT_CONFIG(tooltip)
        actionNova->setToolTip(QCoreApplication::translate("MainWindow", "Nov\303\241 novou datab\303\241zi", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNova->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPridat->setText(QCoreApplication::translate("MainWindow", "P\305\231idat", nullptr));
#if QT_CONFIG(tooltip)
        actionPridat->setToolTip(QCoreApplication::translate("MainWindow", "P\305\231idat z\303\241pis", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPridat->setShortcut(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOtevrit->setText(QCoreApplication::translate("MainWindow", "Otev\305\231\303\255t", nullptr));
#if QT_CONFIG(tooltip)
        actionOtevrit->setToolTip(QCoreApplication::translate("MainWindow", "Otev\305\231\303\255t ji\305\276 existuj\303\255c\303\255 datab\303\241zi", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOtevrit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionKonec->setText(QCoreApplication::translate("MainWindow", "Konec", nullptr));
#if QT_CONFIG(tooltip)
        actionKonec->setToolTip(QCoreApplication::translate("MainWindow", "Ukon\304\215it program", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionKonec->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        vyhledavac->setText(QCoreApplication::translate("MainWindow", "Vyhled\303\241va\304\215", nullptr));
        menuSoubor->setTitle(QCoreApplication::translate("MainWindow", "Datab\303\241ze", nullptr));
        menuZ_znam->setTitle(QCoreApplication::translate("MainWindow", "Z\303\241znam", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
