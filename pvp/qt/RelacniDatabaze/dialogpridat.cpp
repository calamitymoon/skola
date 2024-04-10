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
