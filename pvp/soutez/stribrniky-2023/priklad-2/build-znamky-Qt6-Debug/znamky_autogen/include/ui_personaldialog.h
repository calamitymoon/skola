/********************************************************************************
** Form generated from reading UI file 'personaldialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALDIALOG_H
#define UI_PERSONALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_PersonalDialog
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *jmeno;
    QGridLayout *gridLayout;
    QDateEdit *datum;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *predmet;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *znamka;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PersonalDialog)
    {
        if (PersonalDialog->objectName().isEmpty())
            PersonalDialog->setObjectName(QString::fromUtf8("PersonalDialog"));
        PersonalDialog->resize(390, 223);
        gridLayout_3 = new QGridLayout(PersonalDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(PersonalDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        jmeno = new QLineEdit(PersonalDialog);
        jmeno->setObjectName(QString::fromUtf8("jmeno"));

        horizontalLayout->addWidget(jmeno);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        datum = new QDateEdit(PersonalDialog);
        datum->setObjectName(QString::fromUtf8("datum"));

        gridLayout->addWidget(datum, 0, 1, 1, 1);

        label_2 = new QLabel(PersonalDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(PersonalDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        predmet = new QLineEdit(PersonalDialog);
        predmet->setObjectName(QString::fromUtf8("predmet"));

        horizontalLayout_2->addWidget(predmet);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(PersonalDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        znamka = new QDoubleSpinBox(PersonalDialog);
        znamka->setObjectName(QString::fromUtf8("znamka"));
        znamka->setDecimals(0);
        znamka->setMaximum(100000000000000000000.000000000000000);

        gridLayout_2->addWidget(znamka, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 3, 0, 1, 1);

        buttonBox = new QDialogButtonBox(PersonalDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 4, 0, 1, 1);


        retranslateUi(PersonalDialog);

        QMetaObject::connectSlotsByName(PersonalDialog);
    } // setupUi

    void retranslateUi(QDialog *PersonalDialog)
    {
        PersonalDialog->setWindowTitle(QCoreApplication::translate("PersonalDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PersonalDialog", "Jmeno", nullptr));
        label_2->setText(QCoreApplication::translate("PersonalDialog", "Datum", nullptr));
        label_4->setText(QCoreApplication::translate("PersonalDialog", "Predmet", nullptr));
        label_3->setText(QCoreApplication::translate("PersonalDialog", "Znamka", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonalDialog: public Ui_PersonalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALDIALOG_H
