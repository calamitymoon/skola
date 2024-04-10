#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    databaze = QSqlDatabase::addDatabase("QSQLITE");
    model = new QSqlRelationalTableModel(this,databaze);
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNova_triggered()
{
    databaze.setDatabaseName("databaze.db");
    if (!databaze.open()) {
        QMessageBox::critical(this,"Chyba","Databazi nelze otevrit.");
        return;
    }
    QSqlQuery dotaz;
    dotaz.exec("DROP TABLE lidi");
    dotaz.exec("CREATE TABLE lidi(id int primary key, jmeno varchar(20)"
               ",heslo varchar(20))");
    dotaz.exec("INSERT INTO lidi VALUES (1,'admin','AdMiN$1')");
    model->setTable("lidi");
    model->select();
    ui->tableView->resizeColumnToContents(0);
}


void MainWindow::on_actionPridat_triggered()
{
    DialogPridat dialog;
    if (dialog.exec() != QDialog::Accepted) {
        return;
    }
    model->database().transaction();
    int pocetRadku = model->rowCount();
    if (!model->insertRows(pocetRadku,1)) {
        QMessageBox::critical(this,"Chyba","Radek se nepodarilo pridat");
        return;
    }
    model->setData(model->index(pocetRadku,0),pocetRadku+1);
    model->setData(model->index(pocetRadku,1),dialog.getJmeno());
    model->setData(model->index(pocetRadku,2),dialog.getHeslo());
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::critical(this,"Chyba","Transakci se nepodarilo provest");
    }
}


void MainWindow::on_actionOtevrit_triggered()
{
    databaze.setDatabaseName("databaze.db");
    if (!databaze.open()) {
        QMessageBox::critical(this,"Chyba","Databaze se nepodarilo otevrit");
        return;
    }
    model->setTable("lidi");
    model->select();
}

//void MainWindow::on_leVyhledavac_textChanged(const QString &argument)
//{
//    if (!databaze.isOpen()) {
//        QMessageBox::critical(this, "Chyba", "Databazi se nepodarilo otevrit.");
//        return;
//    }

//    QString queryString = "SELECT * FROM lidi WHERE jmeno LIKE '%" + argument + "%' OR heslo LIKE '%" + argument + "%'";
//    QSqlQueryModel *model = new QSqlQueryModel(this);
//    model->setQuery(queryString);

//    if (model->lastError().isValid()) {
//        QMessageBox::critical(this, "Chyba", model->lastError().text());
//        delete model;
//        return;
//    }

//    ui->tableView->setModel(model);
//}

//void MainWindow::on_leVyhledavac_textChanged(const QString &argument)
//{
//    return argument;
//}
