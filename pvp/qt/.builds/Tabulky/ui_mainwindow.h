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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPridatradek;
    QAction *actionPridatSloupec;
    QAction *actionUlozit;
    QAction *actionOtev_t;
    QAction *actionKonec;
    QAction *actionNastaveniExportu;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuSoubor;
    QMenu *menuNastaven;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionPridatradek = new QAction(MainWindow);
        actionPridatradek->setObjectName("actionPridatradek");
        actionPridatSloupec = new QAction(MainWindow);
        actionPridatSloupec->setObjectName("actionPridatSloupec");
        actionUlozit = new QAction(MainWindow);
        actionUlozit->setObjectName("actionUlozit");
        actionOtev_t = new QAction(MainWindow);
        actionOtev_t->setObjectName("actionOtev_t");
        actionKonec = new QAction(MainWindow);
        actionKonec->setObjectName("actionKonec");
        actionNastaveniExportu = new QAction(MainWindow);
        actionNastaveniExportu->setObjectName("actionNastaveniExportu");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout->addWidget(tableWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuSoubor = new QMenu(menubar);
        menuSoubor->setObjectName("menuSoubor");
        menuNastaven = new QMenu(menubar);
        menuNastaven->setObjectName("menuNastaven");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuSoubor->menuAction());
        menubar->addAction(menuNastaven->menuAction());
        menuSoubor->addAction(actionUlozit);
        menuSoubor->addAction(actionOtev_t);
        menuSoubor->addSeparator();
        menuSoubor->addAction(actionKonec);
        menuNastaven->addAction(actionNastaveniExportu);
        toolBar->addAction(actionPridatradek);
        toolBar->addAction(actionPridatSloupec);

        retranslateUi(MainWindow);
        QObject::connect(actionKonec, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionPridatradek->setText(QCoreApplication::translate("MainWindow", "P\305\231idat \305\231\303\241dek", nullptr));
#if QT_CONFIG(shortcut)
        actionPridatradek->setShortcut(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPridatSloupec->setText(QCoreApplication::translate("MainWindow", "P\305\231idat sloupec", nullptr));
#if QT_CONFIG(shortcut)
        actionPridatSloupec->setShortcut(QCoreApplication::translate("MainWindow", "\304\232", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUlozit->setText(QCoreApplication::translate("MainWindow", "Ulo\305\276it", nullptr));
#if QT_CONFIG(shortcut)
        actionUlozit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOtev_t->setText(QCoreApplication::translate("MainWindow", "Otev\305\231\303\255t", nullptr));
#if QT_CONFIG(shortcut)
        actionOtev_t->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionKonec->setText(QCoreApplication::translate("MainWindow", "Konec", nullptr));
#if QT_CONFIG(shortcut)
        actionKonec->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNastaveniExportu->setText(QCoreApplication::translate("MainWindow", "Nastaven\303\255 exportu", nullptr));
#if QT_CONFIG(shortcut)
        actionNastaveniExportu->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        menuSoubor->setTitle(QCoreApplication::translate("MainWindow", "Soubor", nullptr));
        menuNastaven->setTitle(QCoreApplication::translate("MainWindow", "Nastaven\303\255", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
