#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

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

int poradi;

void MainWindow::on_actionRozdej_2_triggered()
{
    smazTlacitka();
    for(int i = 1; i <=8; i++){
        for(int j = 1; j <= 8; j++){
            QPushButton *pb = new QPushButton(this);
            QIcon icon = QIcon(QIcon(":/:images/1.jpg"));
            pb->setIconSize(QSize(50,50));
            pb->setIcon(icon);
            pb->setGeometry(j*60,i*60,50,50);
            connect(pb,&QPushButton::clicked,this,&MainWindow::stisknuto);
            pb->setProperty("<> souradnice",QString("%1_x_%2").arg(i).arg(j));
            pb->setProperty("<> poradi",poradi);
            tlacitka.push_back(pb);
            pb->setVisible(true);
            poradi++;
        }
    }
    ui->statusbar->showMessage(QString("V seznamu je: %1 prvků.").arg(tlacitka.size()));

}

void MainWindow::stisknuto()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if(button){
        QString souradnice = button->property("souradnice").toString();
        int poradi = button->property("poradi").toInt();
            button->setIcon(QIcon(QString(":/:images/1.jpg")));
                ui->statusbar->showMessage(QString("Ahoj, tlačítko na %1 mizí...").arg(poradi),2000);
                button->deleteLater();
    }
}

void MainWindow::smazTlacitka()
{
    for(QPushButton* &button : tlacitka){
        if(button != nullptr){
            button->deleteLater();
        }
    }
    tlacitka.clear();
}
