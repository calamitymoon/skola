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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionobdelnik;
    QAction *actionnovy;
    QAction *actionulozit;
    QAction *actionotevrit;
    QAction *actionkonec;
    QAction *actioncara;
    QAction *actionelipsa;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menusoubor;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *tbStyl;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionobdelnik = new QAction(MainWindow);
        actionobdelnik->setObjectName("actionobdelnik");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionobdelnik->setIcon(icon);
        actionnovy = new QAction(MainWindow);
        actionnovy->setObjectName("actionnovy");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionnovy->setIcon(icon1);
        actionulozit = new QAction(MainWindow);
        actionulozit->setObjectName("actionulozit");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionulozit->setIcon(icon2);
        actionotevrit = new QAction(MainWindow);
        actionotevrit->setObjectName("actionotevrit");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionotevrit->setIcon(icon3);
        actionkonec = new QAction(MainWindow);
        actionkonec->setObjectName("actionkonec");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionkonec->setIcon(icon4);
        actioncara = new QAction(MainWindow);
        actioncara->setObjectName("actioncara");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncara->setIcon(icon5);
        actionelipsa = new QAction(MainWindow);
        actionelipsa->setObjectName("actionelipsa");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/eclipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionelipsa->setIcon(icon6);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menusoubor = new QMenu(menubar);
        menusoubor->setObjectName("menusoubor");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        tbStyl = new QToolBar(MainWindow);
        tbStyl->setObjectName("tbStyl");
        MainWindow->addToolBar(Qt::TopToolBarArea, tbStyl);

        menubar->addAction(menusoubor->menuAction());
        menusoubor->addAction(actionnovy);
        menusoubor->addAction(actionulozit);
        menusoubor->addAction(actionotevrit);
        menusoubor->addSeparator();
        menusoubor->addAction(actionkonec);
        toolBar->addAction(actionobdelnik);
        toolBar->addSeparator();
        toolBar->addAction(actioncara);
        toolBar->addSeparator();
        toolBar->addAction(actionelipsa);
        toolBar->addSeparator();
        tbStyl->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionobdelnik->setText(QCoreApplication::translate("MainWindow", "obdelnik", nullptr));
#if QT_CONFIG(tooltip)
        actionobdelnik->setToolTip(QCoreApplication::translate("MainWindow", "Obdeln\303\255k", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionobdelnik->setShortcut(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        actionnovy->setText(QCoreApplication::translate("MainWindow", "novy", nullptr));
#if QT_CONFIG(shortcut)
        actionnovy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionulozit->setText(QCoreApplication::translate("MainWindow", "ulozit", nullptr));
#if QT_CONFIG(shortcut)
        actionulozit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionotevrit->setText(QCoreApplication::translate("MainWindow", "otevrit", nullptr));
#if QT_CONFIG(shortcut)
        actionotevrit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionkonec->setText(QCoreApplication::translate("MainWindow", "konec", nullptr));
#if QT_CONFIG(shortcut)
        actionkonec->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actioncara->setText(QCoreApplication::translate("MainWindow", "cara", nullptr));
#if QT_CONFIG(shortcut)
        actioncara->setShortcut(QCoreApplication::translate("MainWindow", "\304\232", nullptr));
#endif // QT_CONFIG(shortcut)
        actionelipsa->setText(QCoreApplication::translate("MainWindow", "elipsa", nullptr));
#if QT_CONFIG(shortcut)
        actionelipsa->setShortcut(QCoreApplication::translate("MainWindow", "\305\240", nullptr));
#endif // QT_CONFIG(shortcut)
        menusoubor->setTitle(QCoreApplication::translate("MainWindow", "soubor", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        tbStyl->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
