#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractListModel>
#include <QLabel> // Added header for QLabel
#include <QPixmap> // Added header for QPixmap
#include <QListWidget>
#include <QFileDialog> // Added header for QFileDialog

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), model(nullptr)
{
    ui->setupUi(this);

    // Connect list view clicked signal to a slot
    connect(ui->lvList, &QListWidget::clicked, this, &MainWindow::on_lvList_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (model) delete model;
}

void MainWindow::on_pbTlacitko_clicked()
{
    QString selectedDirectory = QFileDialog::getExistingDirectory(this, "Select Directory");
    if (selectedDirectory.isEmpty()) {
        return;
    }

    // Clear the existing list
    if (model) delete model;
    model = new QStringListModel(this);

    QDir directory(selectedDirectory);
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.jpeg";
    QStringList entries = directory.entryList(filters, QDir::Files);

    for (const QString &entry : entries) {
        int row = model->rowCount();
        model->insertRow(row); // Insert at the end
        QString filePath = QDir::toNativeSeparators(directory.filePath(entry));
        model->setData(model->index(row, 0), filePath, Qt::EditRole);

        // Add QLabel for preview
        QLabel *previewLabel = new QLabel;
        QPixmap pixmap(filePath);
        // Scale pixmap to fit within 100x100 while maintaining aspect ratio
        pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio);
        previewLabel->setPixmap(pixmap);
        ui->lvList->setIndexWidget(model->index(row, 0), previewLabel);
    }

    ui->lvList->setModel(model);
}

void MainWindow::onItemClicked(const QModelIndex &index)
{
    // Get the file path from the model data
    QString filePath = model->data(index, Qt::EditRole).toString();

    // If valid file path, show preview in a separate widget
    if (!filePath.isEmpty()) {
        // Create a QLabel for the preview (optional, reuse existing one if needed)
        QLabel *previewLabel = new QLabel;

        // Load the image
        QPixmap pixmap(filePath);

        // Check if image loading was successful
        if (pixmap.isNull()) {
            // Handle loading error (optional, display message or placeholder image)
            previewLabel->setText("Error: Failed to load image");
        } else {
            // Scale the image (adjust size as needed)
            pixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatio);
            previewLabel->setPixmap(pixmap);
        }

        // Show the preview in a separate widget (replace with your desired method)
        // Here, we create a temporary dialog to display the preview
        QDialog previewDialog(this);
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(previewLabel);
        previewDialog.setLayout(layout);
        previewDialog.setWindowTitle("Image Preview");
        previewDialog.exec(); // Show the dialog modally
    }
}

void MainWindow::on_lvList_clicked(const QModelIndex &index)
{
    return;
}

