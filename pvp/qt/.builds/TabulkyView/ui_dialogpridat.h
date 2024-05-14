/********************************************************************************
** Form generated from reading UI file 'dialogpridat.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPRIDAT_H
#define UI_DIALOGPRIDAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogPridat
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *jmeno;
    QLineEdit *leJmeno;
    QLabel *heslo;
    QLineEdit *leHeslo;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogPridat)
    {
        if (DialogPridat->objectName().isEmpty())
            DialogPridat->setObjectName("DialogPridat");
        DialogPridat->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogPridat);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        jmeno = new QLabel(DialogPridat);
        jmeno->setObjectName("jmeno");

        formLayout->setWidget(0, QFormLayout::LabelRole, jmeno);

        leJmeno = new QLineEdit(DialogPridat);
        leJmeno->setObjectName("leJmeno");
        leJmeno->setReadOnly(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, leJmeno);

        heslo = new QLabel(DialogPridat);
        heslo->setObjectName("heslo");

        formLayout->setWidget(1, QFormLayout::LabelRole, heslo);

        leHeslo = new QLineEdit(DialogPridat);
        leHeslo->setObjectName("leHeslo");

        formLayout->setWidget(1, QFormLayout::FieldRole, leHeslo);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DialogPridat);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogPridat);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogPridat, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogPridat, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogPridat);
    } // setupUi

    void retranslateUi(QDialog *DialogPridat)
    {
        DialogPridat->setWindowTitle(QCoreApplication::translate("DialogPridat", "Dialog", nullptr));
        jmeno->setText(QCoreApplication::translate("DialogPridat", "Jm\303\251no", nullptr));
        heslo->setText(QCoreApplication::translate("DialogPridat", "Heslo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPridat: public Ui_DialogPridat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPRIDAT_H
