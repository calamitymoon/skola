#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QFileDialog>
#include <QColorDialog>
#include <QPushButton>
#include <QPen>
#include <QSpinBox>


//  //  //  //  //  //  //  //  //  //  //        MAIN       //  //  //  //  //  //  //  //  //  //  //


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(40,40);
    pix.fill(Qt::black);
    QIcon icon(pix);
    barvaNastroje = new QPushButton(icon, "");
    ui->tbStyl->addWidget(barvaNastroje);
    connect(barvaNastroje,&QPushButton::clicked,this,&MainWindow::nastavitBarvuPera);

    barvaPozadi = new QPushButton(icon, "");
    ui->tbStyl->addWidget(barvaPozadi);
    connect(barvaPozadi,&QPushButton::clicked,this,&MainWindow::nastavitBarvuBrushe);

    QSpinBox *spin = new QSpinBox(ui->tbStyl);
    ui->tbStyl->addWidget(spin);
    spin->setToolTip("Nastaveni tlousty pera");
    spin->setRange(1,25);
    spin->setSingleStep(1);
    spin->setSuffix("px");
    connect(spin, &QSpinBox::valueChanged, this, &MainWindow::nastavitVelikostPera);

    ui->actionnovy->setIcon(QIcon::fromTheme("document-new", QIcon(":/icons/icons/new.png")));        // novy
    ui->actionulozit->setIcon(QIcon::fromTheme("document-save", QIcon(":/icons/icons/save.png")));    // ulozit
    ui->actionotevrit->setIcon(QIcon::fromTheme("document-open", QIcon(":/icons/icons/open.png")));   // otevrit
    ui->actionkonec->setIcon(QIcon::fromTheme("document-close", QIcon(":/icons/icons/close.png")));   // konec

    ui->actioncara->setIcon(QIcon(":/icons/icons/line.png"));           // cara
    ui->actionelipsa->setIcon(QIcon(":/icons/icons/eclipse.png"));      // elipsa
    ui->actionobdelnik->setIcon(QIcon(":/icons/icons/rectangle.png"));  // obdelnik

    stetec.setStyle(Qt::SolidPattern);

    on_actionnovy_triggered(); // automaticky vytvorit prazdnou stranku
}


MainWindow::~MainWindow()
{
    delete ui;
}


//  //  //  //  //  //  //  //  //  //  //    EVENTY MYSI   //  //  //  //  //  //  //  //  //  //  //


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    startPoint = event->pos();
    stisknuto = true;
    kreslim = false;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QPainter platno(&obrazek);
    endPoint = event->pos();
    stisknuto = false;
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    endPoint = event->pos();
        ui->statusbar->showMessage(QString("x: %1, y: %2.").arg(event->x()).arg(event->y()));
        update();
}


//  //  //  //  //  //  //  //  //  //     VELIKOST A BARVA     //  //  //  //  //  //  //  //  //  //


void MainWindow::nastavitBarvuPera()
{
    pero.setColor(QColorDialog::getColor());
    QPixmap pix(40,40);
    pix.fill(pero.color());
    QIcon icon(pix);
    barvaNastroje->setIcon(icon);
}

void MainWindow::nastavitBarvuBrushe()
{
    stetec.setColor(QColorDialog::getColor());
    QPixmap pix(40,40);
    pix.fill(stetec.color());
    QIcon icon(pix);
    barvaPozadi->setIcon(icon);
}

void MainWindow::nastavitVelikostPera(int velikost)
{
    pero.setWidth(velikost);
}

void MainWindow::nastavitBarvu()
{
    pero.setColor(QColorDialog::getColor());
}


//  //  //  //  //  //  //  //  //  //  //     MALOVANI     //  //  //  //  //  //  //  //  //  //  //


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter platno(this);
    if (stisknuto == true) {
        platno.setPen(pero);
        platno.setBrush(stetec);
        platno.drawImage(0,0,obrazek);
        if (nastroj == OBDELNIK)
            platno.drawRect(QRect(startPoint,endPoint));
        if (nastroj == CARA)
            platno.drawLine(startPoint,endPoint);
        if (nastroj == ELIPSA)
            platno.drawEllipse(QRect(startPoint,endPoint));
        kreslim = true;
    } else if (kreslim == true) {
        QPainter docasnePlatno(&obrazek);
        docasnePlatno.setPen(pero);
        docasnePlatno.setBrush(stetec);
        if (nastroj == OBDELNIK)
            docasnePlatno.drawRect(QRect(startPoint,endPoint));
        if (nastroj == CARA)
            docasnePlatno.drawLine(startPoint,endPoint);
        if (nastroj == ELIPSA)
            docasnePlatno.drawEllipse(QRect(startPoint,endPoint));
        platno.drawImage(0,0,obrazek);
        kreslim = false;
    } else {
        platno.drawImage(0,0,obrazek);
    }
}



//  //  //  //  //  //  //  //  //  //  //         AKCE         //  //  //  //  //  //  //  //  //  //  //


void MainWindow::on_actionnovy_triggered()
{
    obrazek = QImage(this->width(), this->height(), QImage::Format_RGB32);
    obrazek.fill(Qt::white);
    update();
}

void MainWindow::on_actionulozit_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Ulozit obrazek", "", "Obrazek (*.png, *.jpg, *.bmp)");
    obrazek.save(fileName, "PNG");
    ui->statusbar->showMessage(QString("Ulozeno do souboru %1 ").arg(fileName));
}


void MainWindow::on_actionotevrit_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Otevrit obrazek", "", "Obrazek (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath.isEmpty()) {
        obrazek.load(filePath);
        update();
    }
}

void MainWindow::on_actionkonec_triggered()
{
    close();
}


//  //  //  //  //  //  //  //  //  //  //      NASTROJE     //  //  //  //  //  //  //  //  //  //  //


void MainWindow::on_actionobdelnik_triggered()
{
    nastroj = OBDELNIK;
}

void MainWindow::on_actioncara_triggered()
{
    nastroj = CARA;
}

void MainWindow::on_actionelipsa_triggered()
{
    nastroj = ELIPSA;
}


