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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionvybratSlozku;
    QAction *actionShowFullImage;
    QAction *actionShowDetails;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *imageLayout;
    QLabel *previewLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionvybratSlozku = new QAction(MainWindow);
        actionvybratSlozku->setObjectName("actionvybratSlozku");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("folder-open")));
        actionvybratSlozku->setIcon(icon);
        actionvybratSlozku->setMenuRole(QAction::NoRole);
        actionShowFullImage = new QAction(MainWindow);
        actionShowFullImage->setObjectName("actionShowFullImage");
        actionShowFullImage->setMenuRole(QAction::NoRole);
        actionShowDetails = new QAction(MainWindow);
        actionShowDetails->setObjectName("actionShowDetails");
        actionShowDetails->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        imageLayout = new QGridLayout();
        imageLayout->setObjectName("imageLayout");
        previewLabel = new QLabel(centralwidget);
        previewLabel->setObjectName("previewLabel");

        imageLayout->addWidget(previewLabel, 0, 0, 1, 1);


        verticalLayout_2->addLayout(imageLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionvybratSlozku);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionvybratSlozku->setText(QCoreApplication::translate("MainWindow", "Vybrat Slozku", nullptr));
#if QT_CONFIG(tooltip)
        actionvybratSlozku->setToolTip(QCoreApplication::translate("MainWindow", "Vybrat Slozku", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionvybratSlozku->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionShowFullImage->setText(QCoreApplication::translate("MainWindow", "ShowFullImage", nullptr));
#if QT_CONFIG(tooltip)
        actionShowFullImage->setToolTip(QCoreApplication::translate("MainWindow", "Show Full Image", nullptr));
#endif // QT_CONFIG(tooltip)
        actionShowDetails->setText(QCoreApplication::translate("MainWindow", "ShowDetails", nullptr));
#if QT_CONFIG(tooltip)
        actionShowDetails->setToolTip(QCoreApplication::translate("MainWindow", "Show Details", nullptr));
#endif // QT_CONFIG(tooltip)
        previewLabel->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
