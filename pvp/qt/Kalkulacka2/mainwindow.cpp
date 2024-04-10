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


void MainWindow::on_pbPocitej_clicked()
{
    ui->laVysledek->setStyleSheet("color:black;"); //nastavení výchozí barvy textu
    int vysledek = 0;
    int a = ui->leA->text().toInt();
    int b = ui->leB->text().toInt();
    bool deleni = false;
    switch (ui->cbOperace->currentIndex()) {
      case 0: vysledek = a + b; break;
      case 1: vysledek = a - b; break;
      case 2: vysledek = a * b; break;
      case 3: {
        if(b != 0)
            vysledek = a / b;
        else deleni = true;
        break;
        }
    }
    if(deleni == true){
        ui->laVysledek->setText("Nulou dělit nelze.");
    }else{
      if(vysledek < 0){
        ui->laVysledek->setStyleSheet("color:red;");
      }else
      {
          QString vysledekText;

             // Převedení výsledku na řetězec
             QString vysledekStr = QString::number(vysledek);

             // Procházení každé číslice a přidání do výsledného textu s odpovídající barvou
             for (int i = 0; i < vysledekStr.length(); i++) {
                 QString barva;
                 switch (i % 4) {
                     case 0: barva = "red"; break;
                     case 1: barva = "green"; break;
                     case 2: barva = "blue"; break;
                     case 3: barva = "orange"; break;
                 }
                 vysledekText += QString("<span style='color:%1;'>%2</span>").arg(barva).arg(vysledekStr[i]);
             }

             ui->laVysledek->setText("Výsledek je " + vysledekText + ".");
      }
    }
}

