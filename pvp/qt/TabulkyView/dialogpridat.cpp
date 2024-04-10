#include "dialogpridat.h"
#include "ui_dialogpridat.h"

DialogPridat::DialogPridat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPridat)
{
    ui->setupUi(this);
}

DialogPridat::~DialogPridat()
{
    delete ui;
}

QString DialogPridat::getJmeno()
{
    return ui->leJmeno->text();
}

QString DialogPridat::getHeslo()
{
    return ui->leHeslo->text();
}
