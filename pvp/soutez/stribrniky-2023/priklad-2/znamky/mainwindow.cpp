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
    QStringList znamky;
    setWindowTitle("Znamky");
    ui->tableWidget->setColumnCount(4);
    znamky << "Datum" << "Jmeno" << "Predmet" << "Znamka";
    ui->tableWidget->setHorizontalHeaderLabels(znamky);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pridat_clicked()
{
    int znamka;
    QDate datum;
    QString jmeno, predmet;
    int radek, res;
    PersonalDialog pd(this);
    pd.setWindowTitle("Pridat znamku");
    res = pd.exec();
    if (res == QDialog::Rejected)
        return;
    datum = pd.datum();
    jmeno = pd.jmeno();
    predmet = pd.predmet();
    znamka = pd.znamka();
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    radek = ui->tableWidget->rowCount() - 1;
    ui->tableWidget->setItem(radek, PersonalDialog::DATUM,
                             new QTableWidgetItem(QDate(datum).toString("dd.MM.yyyy")));
    ui->tableWidget->setItem(radek, PersonalDialog::JMENO,
                             new QTableWidgetItem(QString(jmeno)));
    ui->tableWidget->setItem(radek, PersonalDialog::PREDMET,
                             new QTableWidgetItem(QString(predmet)));
    ui->tableWidget->setItem(radek, PersonalDialog::ZNAMKA,
                             new QTableWidgetItem(QString::number(znamka)));

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
        out << "Datum,Jmeno,Predmet,Znamka\n";
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

void MainWindow::on_actionOtevrit_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Otevřít soubor"), "", tr("CSV soubory (*.csv)"));

    if (filePath.isEmpty()) {
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Chyba"), tr("Soubor nelze otevřít"));
        return;
    }

    QTextStream in(&file);
    QStringList lines = in.readAll().split("\n");

    ui->tableWidget->setRowCount(4);

    for (int row = 0; row < lines.size(); ++row) {
        if (row > 0) {
            QStringList values = lines[row].split(",");
            ui->tableWidget->insertRow(row);
            for (int col = 0; col < values.size(); ++col) {
                QTableWidgetItem* item = new QTableWidgetItem(values[col]);
                ui->tableWidget->setItem(row, col, item);
            }
        }
    }
    ui->tableWidget->sortByColumn(1, Qt::AscendingOrder);
    ui->tableWidget->resizeColumnsToContents();

  file.close();
}


void MainWindow::on_actionOdejit_triggered()
{
    close();
}
