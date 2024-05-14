/********************************************************************************
** Form generated from reading UI file 'dialognastaveni.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNASTAVENI_H
#define UI_DIALOGNASTAVENI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogNastaveni
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogNastaveni)
    {
        if (DialogNastaveni->objectName().isEmpty())
            DialogNastaveni->setObjectName("DialogNastaveni");
        DialogNastaveni->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogNastaveni);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(DialogNastaveni);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");
        radioButton->setChecked(true);

        verticalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");

        verticalLayout_2->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName("radioButton_3");

        verticalLayout_2->addWidget(radioButton_3);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(DialogNastaveni);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogNastaveni);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogNastaveni, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogNastaveni, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogNastaveni);
    } // setupUi

    void retranslateUi(QDialog *DialogNastaveni)
    {
        DialogNastaveni->setWindowTitle(QCoreApplication::translate("DialogNastaveni", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogNastaveni", "Odd\304\233lova\304\215", nullptr));
        radioButton->setText(QCoreApplication::translate("DialogNastaveni", "\304\215\303\241rka", nullptr));
        radioButton_2->setText(QCoreApplication::translate("DialogNastaveni", "st\305\231edn\303\255k", nullptr));
        radioButton_3->setText(QCoreApplication::translate("DialogNastaveni", "tabul\303\241tor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogNastaveni: public Ui_DialogNastaveni {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNASTAVENI_H
