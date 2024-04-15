#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractListModel> // Added header

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the model for the list view
    model = new QStringListModel(this);

    // Optional: Populate the combo box with additional options if needed
    // ui->cbBox->addItem("Option 1");
    // ui->cbBox->addItem("Option 2");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::on_pbTlacitko_clicked()
{
    selectedDirectory = QFileDialog::getExistingDirectory(this, "Select Directory");
    if (selectedDirectory.isEmpty()) {
        return;
    }

    // Clear the existing list
    model->setStringList(QStringList());

    QDir directory(selectedDirectory);
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.jpeg";
    QStringList entries = directory.entryList(filters, QDir::Files);

    foreach (const QString &entry, entries) {
            int row = model->rowCount();
            model->insertRow(row); // Insert at the end
            model->setData(model->index(row, 0), QDir::toNativeSeparators(directory.filePath(entry)), Qt::EditRole);
        }

    ui->lvList->setModel(model);
}
