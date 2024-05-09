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
    manager->get(QNetworkRequest(QUrl(ui->leUrlNacist->text())));
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
            QString answer = "";
            QJsonObject obj = arr[i].toObject();
            QString obsah = obj["obsah"].toString();

            if (obsah.startsWith("<img src=\"")) {
                answer = "<h1>" + obj["nadpis"].toString() + obsah;
            } else {
                answer = "<h1>" + obj["nadpis"].toString() + "</h1><p>" + obsah + "</p>\n";
            }
            QTextDocument dokument;
            dokument.setHtml(answer);

            ui->teJSON->append(answer);
        }
        // QJsonArray arr = dokument.array();
        // for (int i = 0; i < arr.size(); i++)
        // {
        //     answer = "";
        //     QJsonObject obj = arr[i].toObject();
        //     answer = "<h1>" + obj["nadpis"].toString() + "</h1><p>" + obj["obsah"].toString() + "</p>" + "\n";
        //     ui->teJSON->append(answer);
        //     }
        // }
    }

}


void MainWindow::on_pbOdeslat_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(ui->leUrlPoslat->text());
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QJsonObject json;
    /// json.insert("nadpis",ui->leNadpis->text());
    /// json.insert("obsah",ui->leNadpis->text());
    json["nadpis"] = ui->leNadpis->text();
    json["obsah"] = ui->leObsah->text();
    QJsonDocument dokument(json);

    // prevedeme json do bytu
    QByteArray data = dokument.toJson();
    QNetworkReply *reply = manager->post(request,data);

    QObject::connect(reply,&QNetworkReply::finished, [=](){
        if (reply->error()==QNetworkReply::NoError)
        {
            ui->teOdpoved->setText(reply->readAll());
        } else {
            ui->teOdpoved->append(reply->errorString());
        }
        reply->deleteLater();
    });
}
