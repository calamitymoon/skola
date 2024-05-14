#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
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


void MainWindow::on_actionPridatradek_triggered()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i,  new QTableWidgetItem(""));
    }
}


void MainWindow::on_actionPridatSloupec_triggered()
{
    ui->tableWidget->setColumnCount(ui->tableWidget->columnCount()+1);
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        ui->tableWidget->setItem(i, ui->tableWidget->columnCount()-1, new QTableWidgetItem(""));
    }
}


void MainWindow::on_actionUlozit_triggered()
{
    QString jmeno = QFileDialog::getSaveFileName(this);
    QFile file(jmeno);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,
                             "Chyba",
                             QString("Nelze uložit soubor %1\n%2")
                             .arg(jmeno)
                             .arg(file.errorString())
                             );
        return;
    }
    QTextStream vystup(&file);
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            vystup << "\"" << ui->tableWidget->item(i,j)->text() << "\"";
            if(j != ui->tableWidget->columnCount()-1)
                vystup << oddelovac;
        }
        vystup << Qt::endl;
    }
    file.close();
}


void MainWindow::on_actionNastaveniExportu_triggered()
{    
    if(dn.exec()){
        oddelovac = dn.getOddelovac();
    }
}

