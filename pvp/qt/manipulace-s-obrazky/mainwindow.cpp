#include "mainwindow.h"
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QImageReader>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    setCentralWidget(view);

    contextMenu = new QMenu(this);
    detailsAction = new QAction(tr("Detaily"), this);
    openAction = new QAction(tr("Otevřít"), this);
    contextMenu->addAction(detailsAction);
    contextMenu->addAction(openAction);

    connect(detailsAction, &QAction::triggered, this, &MainWindow::showImageDetails);
    connect(openAction, &QAction::triggered, this, &MainWindow::openImage);

    QString dir = QFileDialog::getExistingDirectory(this, tr("Vyberte složku"));
    currentDir = QDir(dir);
    QStringList filters;
    filters << "*.jpg" << "*.png" << "*.jpeg";
    QFileInfoList list = currentDir.entryInfoList(filters, QDir::Files);
    int y = 0;
    foreach(QFileInfo fileInfo, list) {
        QImageReader reader(fileInfo.absoluteFilePath());
        QImage image = reader.read();
        if (!image.isNull()) {
            QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image).scaled(250, 250));
            item->setPos(0, y);
            scene->addItem(item);
            y += 250;
        }
    }
}

MainWindow::~MainWindow()
{
}

void MainWindow::showImageDetails()
{
    QFileInfo fileInfo(currentFile);
    QImageReader reader(fileInfo.absoluteFilePath());
    QImage image = reader.read();
    QString details = QString("Název souboru: %1\nVelikost: %2x%3\nPřípona: %4\nVelikost souboru: %5 bytes")
                          .arg(fileInfo.fileName())
                          .arg(image.width())
                          .arg(image.height())
                          .arg(fileInfo.suffix())
                          .arg(fileInfo.size());
    QMessageBox::information(this, tr("Detaily obrázku"), details);
}

void MainWindow::openImage()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(currentFile));
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    if (!currentFile.isEmpty()) {
        QFileInfo fileInfo(currentFile);
        QImageReader reader(fileInfo.absoluteFilePath());
        QImage image = reader.read();

        if (!image.isNull()) {
            QString details = QString("Název souboru: %1\nVelikost: %2x%3\nPřípona: %4\nVelikost souboru: %5 bytes")
                                  .arg(fileInfo.fileName())
                                  .arg(image.width())
                                  .arg(image.height())
                                  .arg(fileInfo.suffix())
                                  .arg(fileInfo.size());

            QMessageBox::information(this, tr("Detaily obrázku"), details);
        } else {
            QMessageBox::warning(this, tr("Chyba"), tr("Nepodařilo se načíst obrázek."));
        }
    } else {
        QMessageBox::warning(this, tr("Chyba"), tr("Neplatný název souboru."));
    }
}
