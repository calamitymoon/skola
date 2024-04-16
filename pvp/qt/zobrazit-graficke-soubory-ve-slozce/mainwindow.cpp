#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractListModel>
#include <QLabel>
#include <QPixmap>
#include <QListWidget>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), model(nullptr)
{
    ui->setupUi(this);

    connect(ui->lvList, &QListWidget::clicked, this, &MainWindow::on_lvList_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (model) delete model;
}

void MainWindow::on_pbTlacitko_clicked()
{
    QString selectedDirectory = QFileDialog::getExistingDirectory(this, "vyber slozku ve ktere chces zobrazit vsechny graficke soubory");
        if (selectedDirectory.isEmpty()) {
            return;
        }

        if (model) {
            delete model;
            model = nullptr;
        }

    model = new QStringListModel(this);

    QDir directory(selectedDirectory);
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.jpeg";
    QStringList entries = directory.entryList(filters, QDir::Files);

    for (const QString &entry : entries) {
        int row = model->rowCount();
        model->insertRow(row);
        QString filePath = QDir::toNativeSeparators(directory.filePath(entry));
        model->setData(model->index(row, 0), filePath, Qt::EditRole);
    }

    ui->lvList->setModel(model);
}

void MainWindow::on_lvList_clicked(const QModelIndex &index)
{
    QString filePath = model->data(index, Qt::EditRole).toString();

    if (!filePath.isEmpty()) {
        QLabel *previewLabel = new QLabel;

        QPixmap pixmap(filePath);

        if (pixmap.isNull()) {
            previewLabel->setText("obrazek nelze nacist");
        } else {
            pixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatioByExpanding);
            previewLabel->setPixmap(pixmap);
        }
        QDialog previewDialog(this);
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(previewLabel);
        previewDialog.setLayout(layout);
        previewDialog.setWindowTitle("vybrany obrazek");
        previewDialog.exec();
    }
}

