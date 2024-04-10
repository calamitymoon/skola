#include "dialognastaveni.h"
#include "ui_dialognastaveni.h"

DialogNastaveni::DialogNastaveni(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNastaveni)
{
    ui->setupUi(this);
}

DialogNastaveni::~DialogNastaveni()
{
    delete ui;
}

QString DialogNastaveni::getJmeno()
{
    return ui->leJmeno->text();
}

QString DialogNastaveni::getPrijmeni()
{
    return ui->lePrijmeni->text();
}

QString DialogNastaveni::getTelefon()
{
    return ui->leTelefon->text();
}
