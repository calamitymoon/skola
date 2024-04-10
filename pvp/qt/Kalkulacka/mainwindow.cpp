#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pbSecti_clicked()
{
    int vysledek = ui->leA->text().toInt();
    vysledek += ui->leB->text().toInt();
    ui->laVysledek->setText(QString("Součet čísla %1 a %2 je %3.")
                            .arg(ui->leA->text())
                            .arg(ui->leB->text())
                            .arg(vysledek)
                            );
}

