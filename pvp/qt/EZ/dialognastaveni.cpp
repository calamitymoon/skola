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

bool DialogNastaveni::getZahlavi()
{
    return ui->cbZahlavi->isChecked();
}

bool DialogNastaveni::getImportZahlavi()
{
    return ui->cbImportZahlavi->isChecked();
}

void DialogNastaveni::on_rbCarka_pressed()
{
    oddelovac = ",";
    ui->leVlastni->setEnabled(false);
}


void DialogNastaveni::on_rbStrednik_pressed()
{
    oddelovac = ";";
    ui->leVlastni->setEnabled(false);
}


void DialogNastaveni::on_rbTabulator_clicked()
{
    oddelovac = "\t";
    ui->leVlastni->setEnabled(false);
}


void DialogNastaveni::on_rbVlastni_clicked()
{
    ui->leVlastni->setEnabled(true);
}


void DialogNastaveni::on_leVlastni_editingFinished()
{
    oddelovac = ui->leVlastni->text();
}

const QString &DialogNastaveni::getImportOddelovac() const
{
    return importOddelovac;
}


void DialogNastaveni::on_radioButton_toggled(bool checked)
{
    importOddelovac = ",";
    ui->leImportVlastni->setEnabled(false);
}


void DialogNastaveni::on_radioButton_2_toggled(bool checked)
{
    importOddelovac = ";";
    ui->leImportVlastni->setEnabled(false);
}


void DialogNastaveni::on_radioButton_4_toggled(bool checked)
{
    importOddelovac = "\t";
    ui->leImportVlastni->setEnabled(false);
}


void DialogNastaveni::on_radioButton_3_toggled(bool checked)
{
     ui->leImportVlastni->setEnabled(true);
}


void DialogNastaveni::on_leImportVlastni_editingFinished()
{
    importOddelovac = ui->leImportVlastni->text();
}

