#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogpridat.h"
#include <QFileDialog>
#include <QTextStream>
#include "dialognastaveni.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0, 150);
    zahlavi << "Jméno" << "Věk" << "Plat" << "Telefon";
    ui->actionNovy->triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNovy_triggered()
{
    ui->tableWidget->setColumnCount(zahlavi.count());
    ui->tableWidget->setHorizontalHeaderLabels(zahlavi);
    ui->tableWidget->setRowCount(0);
}


void MainWindow::on_actionPridat_triggered()
{
    DialogPridat dialog;
    if(dialog.exec() != QDialog::Accepted){
        return;
    }

    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    int r = ui->tableWidget->rowCount()-1;

    QString jmeno = dialog.jmeno();
    QString vek = dialog.vek();
    QString plat = dialog.plat();
    QString telefon = dialog.telefon();

    ui->tableWidget->setItem(r,0,new QTableWidgetItem(jmeno));
    ui->tableWidget->setItem(r,1,new QTableWidgetItem(vek));
    ui->tableWidget->setItem(r,2,new QTableWidgetItem(plat));
    ui->tableWidget->setItem(r,3,new QTableWidgetItem(telefon));

    ui->tableWidget->resizeColumnToContents(0);
}


void MainWindow::on_actionUlozit_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                        "Uložit tabulku","","CSV (*.csv);;All files (*)");
    QFile soubor(fileName);
    if(!soubor.open(QIODevice::WriteOnly | QIODevice::Text)){
        ui->statusbar->showMessage("Soubor se nepodařilo uložit.",2500);
        return;
    }
    QTextStream vystup(&soubor);
    if(exportovatZahlavi == true){
        for(int i = 0; i < zahlavi.count(); i++){
            vystup << zahlavi[i];
            if(i != zahlavi.count()-1) vystup << oddelovac;
        }
        vystup << Qt::endl;
    }
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            vystup << ui->tableWidget->item(i,j)->text();
              if(j != ui->tableWidget->columnCount()-1) vystup << oddelovac;
        }
        vystup << Qt::endl;
    }
    soubor.close();
    ui->statusbar->showMessage("Soubor byl úspěšně uložen.",2500);
}


void MainWindow::on_actionNastaveni_triggered()
{    
    if(dialogNastaveni.exec() != QDialog::Accepted){
        return;
    }
    oddelovac = dialogNastaveni.getOddelovac();
    exportovatZahlavi = dialogNastaveni.getZahlavi();
    ui->statusbar->showMessage(QString("Nový oddělovač je: %1").arg(oddelovac),5000);
}


void MainWindow::on_actionOtevrit_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                        "Uložit tabulku","","CSV (*.csv);;Všechny soubory (*)");
    QFile soubor(fileName);
    if(!soubor.open(QIODevice::ReadOnly | QIODevice::Text)){
        ui->statusbar->showMessage("Soubor se nepodařilo uložit.",5000);
        return;
    }
    QTextStream vstup(&soubor);
    QString oddelovac = dialogNastaveni.getImportOddelovac();//přepíšu globální oddělovač
    bool nastaveno = false;
    ui->tableWidget->setRowCount(0);
    while(!vstup.atEnd()){
        QString r = vstup.readLine();
        QStringList radek = r.split(oddelovac);
        if(nastaveno == false){
            ui->tableWidget->setColumnCount(radek.count());            
            nastaveno = true;
            if(dialogNastaveni.getImportZahlavi()==true){
                ui->tableWidget->setHorizontalHeaderLabels(radek);
                continue;
            }
        }
        int kam = ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        for(int i = 0; i < radek.count();i++){
            ui->tableWidget->setItem(kam,i,new QTableWidgetItem(radek[i]));
        }
        ui->tableWidget->resizeColumnToContents(0);
    }
}

