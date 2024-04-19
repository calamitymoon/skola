/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUlozit;
    QAction *actionOdejit;
    QAction *actionOtevrit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pridat;
    QMenuBar *menubar;
    QMenu *menuUlo_it;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(699, 472);
        actionUlozit = new QAction(MainWindow);
        actionUlozit->setObjectName(QString::fromUtf8("actionUlozit"));
        actionOdejit = new QAction(MainWindow);
        actionOdejit->setObjectName(QString::fromUtf8("actionOdejit"));
        actionOtevrit = new QAction(MainWindow);
        actionOtevrit->setObjectName(QString::fromUtf8("actionOtevrit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pridat = new QPushButton(centralwidget);
        pridat->setObjectName(QString::fromUtf8("pridat"));

        horizontalLayout->addWidget(pridat);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 699, 21));
        menuUlo_it = new QMenu(menubar);
        menuUlo_it->setObjectName(QString::fromUtf8("menuUlo_it"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuUlo_it->menuAction());
        menuUlo_it->addAction(actionUlozit);
        menuUlo_it->addAction(actionOtevrit);
        menuUlo_it->addSeparator();
        menuUlo_it->addAction(actionOdejit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionUlozit->setText(QCoreApplication::translate("MainWindow", "Ulo\305\276it tabulku", nullptr));
#if QT_CONFIG(shortcut)
        actionUlozit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOdejit->setText(QCoreApplication::translate("MainWindow", "Ukon\304\215it", nullptr));
#if QT_CONFIG(shortcut)
        actionOdejit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOtevrit->setText(QCoreApplication::translate("MainWindow", "Otev\305\231\303\255t tabulku", nullptr));
#if QT_CONFIG(shortcut)
        actionOtevrit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        pridat->setText(QCoreApplication::translate("MainWindow", "P\305\231idat", nullptr));
        menuUlo_it->setTitle(QCoreApplication::translate("MainWindow", "Mo\305\276nosti", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
