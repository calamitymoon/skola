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

QString PersonalDialog::jmeno() const
{
    return ui->jmeno->text();
}

int PersonalDialog::vek() const
{
    return ui->vek->value();
}

double PersonalDialog::vyplata() const
{
    return ui->vyplata->value();
}
