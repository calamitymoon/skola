#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPen>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage obrazek;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint startPoint, endPoint;
    bool stisknuto;
    bool kreslim;
    enum nastroje{PERO,OBDELNIK,CARA,ELIPSA};
    int nastroj = OBDELNIK;
    QPushButton *barvaNastroje;
    QPushButton *barvaPozadi;
    void nastavitBarvu();
    void nastavitBarvuPera();
    void nastavitBarvuBrushe();
    void nastavitVelikostPera(int velikost);
    QPen pero;
    QBrush stetec;

protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_actionnovy_triggered();
    void on_actionulozit_triggered();
    void on_actionotevrit_triggered();
    void on_actionobdelnik_triggered();
    void on_actioncara_triggered();
    void on_actionelipsa_triggered();
    void on_actionkonec_triggered();

};
#endif // MAINWINDOW_H
