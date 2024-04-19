#include "personaldialog.h"
#include "ui_personaldialog.h"

PersonalDialog::PersonalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonalDialog)
{
    ui->setupUi(this);
}

PersonalDialog::~PersonalDialog()
{
    delete ui;
}

void PersonalDialog::on_buttonBox_accepted()
{
    accept();
}


void PersonalDialog::on_buttonBox_rejected()
{
    reject();
}

QDate PersonalDialog::datum() const
{
    return ui->datum->date();
}

QString PersonalDialog::jmeno() const
{
    return ui->jmeno->text();
}

QString PersonalDialog::predmet() const
{
    return ui->predmet->text();
}

int PersonalDialog::znamka() const
{
    return ui->znamka->value();
}
