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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSecistSloupec;
    QAction *actionVycistitTabulku;
    QAction *actionUkoncit;
    QAction *actionSecistRadek;
    QAction *actionOtevrit;
    QAction *actionUlozit;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuMo_nosti;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionSecistSloupec = new QAction(MainWindow);
        actionSecistSloupec->setObjectName("actionSecistSloupec");
        actionVycistitTabulku = new QAction(MainWindow);
        actionVycistitTabulku->setObjectName("actionVycistitTabulku");
        actionUkoncit = new QAction(MainWindow);
        actionUkoncit->setObjectName("actionUkoncit");
        actionSecistRadek = new QAction(MainWindow);
        actionSecistRadek->setObjectName("actionSecistRadek");
        actionSecistRadek->setMenuRole(QAction::TextHeuristicRole);
        actionOtevrit = new QAction(MainWindow);
        actionOtevrit->setObjectName("actionOtevrit");
        actionOtevrit->setMenuRole(QAction::NoRole);
        actionUlozit = new QAction(MainWindow);
        actionUlozit->setObjectName("actionUlozit");
        actionUlozit->setMenuRole(QAction::TextHeuristicRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");

        horizontalLayout->addWidget(tableWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        menuMo_nosti = new QMenu(menuBar);
        menuMo_nosti->setObjectName("menuMo_nosti");
        MainWindow->setMenuBar(menuBar);

        toolBar->addSeparator();
        toolBar->addAction(actionSecistSloupec);
        toolBar->addAction(actionSecistRadek);
        menuBar->addAction(menuMo_nosti->menuAction());
        menuMo_nosti->addAction(actionOtevrit);
        menuMo_nosti->addAction(actionUlozit);
        menuMo_nosti->addSeparator();
        menuMo_nosti->addAction(actionVycistitTabulku);
        menuMo_nosti->addSeparator();
        menuMo_nosti->addAction(actionUkoncit);

        retranslateUi(MainWindow);
        QObject::connect(actionUkoncit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSecistSloupec->setText(QCoreApplication::translate("MainWindow", "Se\304\215\303\255st sloupec", nullptr));
#if QT_CONFIG(tooltip)
        actionSecistSloupec->setToolTip(QCoreApplication::translate("MainWindow", "Se\304\215te cel\303\275 sloupec a v\303\275sledek se se\304\215te do posledn\303\255 bu\305\210ky ka\305\276d\303\251ho sloupce", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSecistSloupec->setShortcut(QCoreApplication::translate("MainWindow", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        actionVycistitTabulku->setText(QCoreApplication::translate("MainWindow", "Vy\304\215istit tabulku", nullptr));
#if QT_CONFIG(shortcut)
        actionVycistitTabulku->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUkoncit->setText(QCoreApplication::translate("MainWindow", "Ukon\304\215it", nullptr));
#if QT_CONFIG(shortcut)
        actionUkoncit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSecistRadek->setText(QCoreApplication::translate("MainWindow", "Se\304\215\303\255st \305\231\303\241dek", nullptr));
#if QT_CONFIG(shortcut)
        actionSecistRadek->setShortcut(QCoreApplication::translate("MainWindow", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOtevrit->setText(QCoreApplication::translate("MainWindow", "Otev\305\231\303\255t", nullptr));
#if QT_CONFIG(shortcut)
        actionOtevrit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUlozit->setText(QCoreApplication::translate("MainWindow", "Ulo\305\276it", nullptr));
#if QT_CONFIG(shortcut)
        actionUlozit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        menuMo_nosti->setTitle(QCoreApplication::translate("MainWindow", "Mo\305\276nosti", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
