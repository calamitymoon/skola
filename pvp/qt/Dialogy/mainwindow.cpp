#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialognastaveni.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNastaveni_triggered()
{
    if(dn.exec()){
        ui->laJmeno->setText(dn.getJmeno());
        ui->laPrijmeni->setText(dn.getPrijmeni());
        ui->laTelefon->setText(dn.getTelefon());
    }else{

    }
}

