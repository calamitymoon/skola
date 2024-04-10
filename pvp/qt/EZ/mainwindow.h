#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialognastaveni.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNovy_triggered();

    void on_actionPridat_triggered();

    void on_actionUlozit_triggered();

    void on_actionNastaveni_triggered();

    void on_actionOtevrit_triggered();

private:
    Ui::MainWindow *ui;
    QStringList zahlavi;
    QString oddelovac = ",";
    bool exportovatZahlavi = false;
    DialogNastaveni dialogNastaveni;
};
#endif // MAINWINDOW_H



