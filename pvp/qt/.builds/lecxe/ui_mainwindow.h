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
    QAction *actionNovyRadek;
    QAction *actionNovySloupec;
    QAction *actionSecist;
    QAction *actionKonec;
    QAction *actionSecistvradcich;
    QAction *actionNacistSoubor;
    QAction *actionStatistika;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuSubor;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNovyRadek = new QAction(MainWindow);
        actionNovyRadek->setObjectName("actionNovyRadek");
        actionNovySloupec = new QAction(MainWindow);
        actionNovySloupec->setObjectName("actionNovySloupec");
        actionSecist = new QAction(MainWindow);
        actionSecist->setObjectName("actionSecist");
        actionKonec = new QAction(MainWindow);
        actionKonec->setObjectName("actionKonec");
        actionSecistvradcich = new QAction(MainWindow);
        actionSecistvradcich->setObjectName("actionSecistvradcich");
        actionNacistSoubor = new QAction(MainWindow);
        actionNacistSoubor->setObjectName("actionNacistSoubor");
        actionNacistSoubor->setMenuRole(QAction::NoRole);
        actionStatistika = new QAction(MainWindow);
        actionStatistika->setObjectName("actionStatistika");
        actionStatistika->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuSubor = new QMenu(menubar);
        menuSubor->setObjectName("menuSubor");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuSubor->menuAction());
        menuSubor->addAction(actionNovyRadek);
        menuSubor->addAction(actionNovySloupec);
        menuSubor->addSeparator();
        menuSubor->addAction(actionSecist);
        menuSubor->addSeparator();
        menuSubor->addAction(actionKonec);
        toolBar->addAction(actionNacistSoubor);
        toolBar->addSeparator();
        toolBar->addAction(actionStatistika);
        toolBar->addSeparator();
        toolBar->addAction(actionSecist);
        toolBar->addAction(actionSecistvradcich);
        toolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(actionKonec, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "lecxE", nullptr));
        actionNovyRadek->setText(QCoreApplication::translate("MainWindow", "Nov\303\275 \305\231\303\241dek", nullptr));
#if QT_CONFIG(shortcut)
        actionNovyRadek->setShortcut(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNovySloupec->setText(QCoreApplication::translate("MainWindow", "Nov\303\275 sloupec", nullptr));
#if QT_CONFIG(shortcut)
        actionNovySloupec->setShortcut(QCoreApplication::translate("MainWindow", "\304\232", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSecist->setText(QCoreApplication::translate("MainWindow", "Se\304\215\303\255st \305\231\303\241dek", nullptr));
#if QT_CONFIG(shortcut)
        actionSecist->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        actionKonec->setText(QCoreApplication::translate("MainWindow", "Konec", nullptr));
#if QT_CONFIG(shortcut)
        actionKonec->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSecistvradcich->setText(QCoreApplication::translate("MainWindow", "Se\304\215\303\255st sloupec", nullptr));
#if QT_CONFIG(tooltip)
        actionSecistvradcich->setToolTip(QCoreApplication::translate("MainWindow", "Se\304\215\303\255st v \305\231\303\241dc\303\255ch", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSecistvradcich->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNacistSoubor->setText(QCoreApplication::translate("MainWindow", "Na\304\215\303\255st CSV soubor", nullptr));
#if QT_CONFIG(shortcut)
        actionNacistSoubor->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStatistika->setText(QCoreApplication::translate("MainWindow", "Statistika", nullptr));
#if QT_CONFIG(shortcut)
        actionStatistika->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        menuSubor->setTitle(QCoreApplication::translate("MainWindow", "Soubor", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
