/********************************************************************************
** Form generated from reading UI file 'statisticsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSDIALOG_H
#define UI_STATISTICSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StatisticsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *maxValueLabel;
    QLabel *minValueLabel;
    QLabel *averageValueLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StatisticsDialog)
    {
        if (StatisticsDialog->objectName().isEmpty())
            StatisticsDialog->setObjectName("StatisticsDialog");
        StatisticsDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(StatisticsDialog);
        verticalLayout->setObjectName("verticalLayout");
        maxValueLabel = new QLabel(StatisticsDialog);
        maxValueLabel->setObjectName("maxValueLabel");

        verticalLayout->addWidget(maxValueLabel);

        minValueLabel = new QLabel(StatisticsDialog);
        minValueLabel->setObjectName("minValueLabel");

        verticalLayout->addWidget(minValueLabel);

        averageValueLabel = new QLabel(StatisticsDialog);
        averageValueLabel->setObjectName("averageValueLabel");

        verticalLayout->addWidget(averageValueLabel);

        buttonBox = new QDialogButtonBox(StatisticsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(StatisticsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, StatisticsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, StatisticsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(StatisticsDialog);
    } // setupUi

    void retranslateUi(QDialog *StatisticsDialog)
    {
        StatisticsDialog->setWindowTitle(QCoreApplication::translate("StatisticsDialog", "Dialog", nullptr));
        maxValueLabel->setText(QCoreApplication::translate("StatisticsDialog", "0", nullptr));
        minValueLabel->setText(QCoreApplication::translate("StatisticsDialog", "0", nullptr));
        averageValueLabel->setText(QCoreApplication::translate("StatisticsDialog", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsDialog: public Ui_StatisticsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSDIALOG_H
