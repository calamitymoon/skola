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

void MainWindow::on_pbNacti_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::spracovaniPoPozadavku);
    manager->get(QNetworkRequest(QUrl(ui->leUrl->text())));
}

void MainWindow::spracovaniPoPozadavku(QNetworkReply *reply)
{
    if (reply->error())
    {
        ui->teJSON->setText(reply->errorString());
        return;
    }
    QString answer = reply->readAll();
    QJsonDocument dokument = QJsonDocument::fromJson(answer.toUtf8());
    if (dokument.isArray())
    {
        QJsonArray arr = dokument.array();
        for (int i = 0; i < arr.size(); i++)
        {
            answer = "";
            QJsonObject obj = arr[i].toObject();
            answer = "<h3>" + obj["nadpis"].toString() + " >> " + obj["obsah"].toString() + "</h3>" + "\n";
            ui->teJSON->append(answer);
        }
    }

}

