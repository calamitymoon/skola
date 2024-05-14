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

const QString &DialogNastaveni::getOddelovac() const
{
    return oddelovac;
}

void DialogNastaveni::on_radioButton_2_clicked()
{
    oddelovac = ";";
}


void DialogNastaveni::on_radioButton_3_clicked()
{
    oddelovac = "\t";
}


void DialogNastaveni::on_radioButton_clicked()
{
    oddelovac = ",";
}

