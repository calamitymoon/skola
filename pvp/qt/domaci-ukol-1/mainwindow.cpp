#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personaldialog.h"
#include "QFileDialog"
#include "QIODevice"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "QTextBlock"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList tituly;
    setWindowTitle("Zaměstnanci");
    ui->tableWidget->setColumnCount(3);
    tituly << "Jméno" << "Věk" << "Výplata";
    ui->tableWidget->setHorizontalHeaderLabels(tituly);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pridat_clicked()
{
    double vyplata;
    int res, vek, radek;
    QString jmeno;
    PersonalDialog pd(this);
    pd.setWindowTitle("Úprava zaměstnance");
    res = pd.exec();
    if (res == QDialog::Rejected)
        return;
    jmeno = pd.jmeno();
    vek = pd.vek();
    vyplata = pd.vyplata();
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    radek = ui->tableWidget->rowCount() - 1;
    ui->tableWidget->setItem(radek, PersonalDialog::JMENO,
                             new QTableWidgetItem(jmeno));
    ui->tableWidget->setItem(radek, PersonalDialog::VEK,
                             new QTableWidgetItem(QString::number(vek)));
    ui->tableWidget->setItem(radek, PersonalDialog::VYPLATA,
                             new QTableWidgetItem(QString::number(vyplata)));

}


void MainWindow::on_actionUlozit_triggered()
{
    QString pathSouboru = QFileDialog::getSaveFileName(this, tr("Uložit jako .csv soubor"), "", tr(".csv soubory (*.csv)"));
        if (pathSouboru.isEmpty())
            return;

        if (!pathSouboru.endsWith(".csv", Qt::CaseInsensitive))
            pathSouboru += ".csv";

        QFile file(pathSouboru);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Chyba"), tr("Soubor nelze zapsat"));
            return;
        }

        QTextStream out(&file);
        out << "Jméno,Věk,Výplata\n";
        for(int row = 0; row < ui->tableWidget->rowCount(); ++row) {
            for(int col = 0; col < ui->tableWidget->columnCount(); ++col) {
                if(col > 0)
                    out << ",";
                QTableWidgetItem *item = ui->tableWidget->item(row, col);
                if(item)
                    out << item->text();
            }
            out << "\n";
        }
        file.close();
}


void MainWindow::on_actionOdejit_triggered()
{
    close();
}

