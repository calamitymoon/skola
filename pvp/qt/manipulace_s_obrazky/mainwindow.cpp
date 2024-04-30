#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentIndex = 0;
    layoutProScrollovani = new QVBoxLayout();

    QWidget *scrollWidget = new QWidget();
    scrollWidget->setLayout(layoutProScrollovani);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    setCentralWidget(scrollArea);

    QAction *openFolderAction = new QAction("Otevrit slozku", this);
    connect(openFolderAction, &QAction::triggered, this, &MainWindow::on_openFolder_triggered);
    ui->menubar->addAction(openFolderAction);

    nahledObrazku = new QLabel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFolder_triggered()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Vyberte slozku", QDir::homePath());
    if (!folderPath.isEmpty()) {
        QDir dir(folderPath);
        QStringList filters;
        filters << "*.jpg" << "*.png" << "*.jpeg";
        QStringList listSouboru = dir.entryList(filters, QDir::Files);

        vycistitLayout(layoutProScrollovani);
        listUmisteniObrazku.clear();
        currentIndex = 0;

        for (const QString &soubor : listSouboru) {
            qDebug() << "Nazev souboru:" << soubor;
            listUmisteniObrazku.append(dir.filePath(soubor));
            nacistNahled(listUmisteniObrazku.last());
        }
        updatovaniScrollBaru();
    }
}

void MainWindow::nacistNahled(const QString &umisteniSouboru)
{
    QImageReader reader(umisteniSouboru);
    reader.setAutoTransform(true);
    const QImage obrazek = reader.read();
    if (obrazek.isNull()) {
        QMessageBox::warning(this, "Chyba", "Nepodarilo se nacist obrazek: " + reader.errorString());
        return;
    }

    QLabel *nahledovyLabel = new QLabel();
    QPixmap pixmap = QPixmap::fromImage(obrazek);
    nahledovyLabel->setPixmap(pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    nahledovyLabel->setAlignment(Qt::AlignCenter);
    layoutProScrollovani->addWidget(nahledovyLabel);

    nahledovyLabel->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(nahledovyLabel, &QLabel::customContextMenuRequested, this, [this, nahledovyLabel, umisteniSouboru](const QPoint &pozice){
        aktualniUmisteniObrazku = umisteniSouboru;
        currentIndex = layoutProScrollovani->indexOf(nahledovyLabel);
        zobrazitContextMenu(nahledovyLabel, pozice);
    });
}

void MainWindow::zobrazitContextMenu(QLabel *label, const QPoint &pozice)
{
    QPoint globaniPozice = label->mapToGlobal(pozice);
    QMenu contextMenu;
    QAction *zobrazitCelejObrazek = contextMenu.addAction("Zobrazit uplny obrazek");
    QAction *zobrazitDetaily = contextMenu.addAction("Detaily");

    QAction *vyber = contextMenu.exec(globaniPozice);
    if (vyber == zobrazitCelejObrazek) {
        zobrazitObrazek(currentIndex);
    } else if (vyber == zobrazitDetaily) {
        if (!aktualniUmisteniObrazku.isEmpty()) {
            QFileInfo fileInfo(aktualniUmisteniObrazku);
            QString detaily = "Nazev: " + fileInfo.fileName() + "\n";
            detaily += "Velikost: " + QString::number(fileInfo.size()) + " bitu\n";
            detaily += "Typ: " + fileInfo.suffix();

            QMessageBox::information(this, "Detaily", detaily);
        }
    }
}

void MainWindow::vycistitLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->layout()) {
            vycistitLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void MainWindow::zobrazitObrazek(int index)
{
    if (index >= 0 && index < listUmisteniObrazku.size()) {
        const QString &aktualniUmisteniObrazku = listUmisteniObrazku[index];
        QImageReader reader(aktualniUmisteniObrazku);
        reader.setAutoTransform(true);
        const QImage obrazek = reader.read();
        if (!obrazek.isNull()) {
            QDialog *obrazekDialog = new QDialog(this);
            obrazekDialog->setWindowTitle("Úplný obrázek");

            QLabel *obrazekLabel = new QLabel(obrazekDialog);
            QPixmap pixmap = QPixmap::fromImage(obrazek);
            obrazekLabel->setPixmap(pixmap);
            obrazekLabel->setAlignment(Qt::AlignCenter);

            QVBoxLayout *layout = new QVBoxLayout(obrazekDialog);
            layout->addWidget(obrazekLabel);
            obrazekDialog->setLayout(layout);

            obrazekDialog->setMinimumSize(pixmap.size());
            obrazekDialog->setSizeGripEnabled(true);

            obrazekDialog->exec();
        }
    }
}



void MainWindow::updatovaniScrollBaru()
{
    QScrollBar *vScrollBar = centralWidget()->findChild<QScrollBar*>("qt_scrollarea_vcontainer");
    if (vScrollBar) {
        vScrollBar->setValue(0);
    }
}
