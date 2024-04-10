#include "dialogpridat.h"
#include "ui_dialogpridat.h"
#include "QRegularExpression"
#include "QRegularExpressionValidator"

DialogPridat::DialogPridat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPridat)
{
    ui->setupUi(this);
    QRegularExpression tel("\\d{3}-\\d{3}-\\d{3}");
    QValidator *pv = new QRegularExpressionValidator(tel,this);
    ui->lerTelefon->setValidator(pv);
}

DialogPridat::~DialogPridat()
{
    delete ui;
}

QString DialogPridat::jmeno()
{
    return ui->leJmeno->text();
}

QString DialogPridat::vek()
{
    return QString::number(ui->sbVek->value());
}

QString DialogPridat::plat()
{
    return ui->lePlat->text();
}

QString DialogPridat::telefon()
{
    return ui->lerTelefon->text();
}
