#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    databaze = QSqlDatabase::addDatabase("QSQLITE");
    databaze.setDatabaseName("databaze.db");
    model = new QSqlRelationalTableModel(this,databaze);
    model->setTable("Faktury");
    model->setRelation(model->fieldIndex("Dodavatel"),
                       QSqlRelation("Dodavatele","ICO","Nazev"));
    model->select();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionVytvorit_triggered()
{
    if (!databaze.open()) {
        QMessageBox::critical(this, "Chyba", "Databazi se nepodarilo otevrit");
//        QDebug() << "Chyba pri otevirani databaze: "
//                 << "db.lastError().text()";
        return;
    }
    QSqlQuery dotaz;
    dotaz.exec("CREATE TABLE dodavatele ("
               "ICO INTEGER PRIMARY KEY,"
               "Nazev TEXT,"
               "Obec TEXT,"
               "Ulice TEXT,"
               "PSC TEXT)");
    if (dotaz.lastError().isValid()){
        QMessageBox::critical(this, "Chyba", "Tabulka dodavatele se nepodarila vytvorit");
//        QDebug() << "Chyba pri vytvareni tabulky dodavatele: "
//                 << "db.lastError().text()";
    }
    dotaz.exec("CREATE TABLE faktury ("
               "Cislo INTEGER PRIMARY KEY,"
               "Cena REAL,"
               "Splatnost DATE,"
               "Dodavatel INTEGER,"
               "FOREIGN KEY(Dodavatel) REFERENCES dodavatele(ICO))");
    if (dotaz.lastError().isValid()) {
        QMessageBox::critical(this, "Chyba", "Tabulka faktury se nepodarila vytvorit");
//        QDebug() << "Chyba pri vytvareni tabulky faktury: "
//                 << "db.lastError().text()";
    }
}


void MainWindow::on_actionKonec_triggered()
{
    close();
}
