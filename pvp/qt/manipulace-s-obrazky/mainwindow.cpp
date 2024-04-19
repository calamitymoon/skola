#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QImageReader>

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


void MainWindow::on_actionOtevrit_triggered()
{
    QString nazevSouboru = QFileDialog::getOpenFileName(this,
                                                    tr("Otevřít obrázek"),
                                                    "",
                                                    tr("Image Files (*.png *.jpg *.jpeg)"));
    if (!nazevSouboru.isEmpty()) {
        QImageReader reader(nazevSouboru);
        if (!reader.canRead()) {
            QMessageBox::warning(this, tr("Chybička"), tr("Nelze načíst soubor"));
            return;
        }

        QPixmap pixmap(nazevSouboru);
        if (pixmap.isNull()) {
            QMessageBox::warning(this, tr("Chybička"), tr("Nelze zobrazit obrázek"));
            return;
        }

        zobrazitObrazek(pixmap);
    }
}

void MainWindow::zobrazitObrazek(const QPixmap &pixmap)
{
    if (!obrazekDialog) {
        obrazekDialog = new QDialog(this);
        QVBoxLayout *layout = new QVBoxLayout(obrazekDialog);
        obrazekLabel = new QLabel;
        layout->addWidget(obrazekLabel);
        obrazekDialog->setLayout(layout);
    }

    obrazekLabel->setPixmap(pixmap);
    obrazekDialog->show();
}
