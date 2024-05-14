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
    void on_actionPridatradek_triggered();

    void on_actionPridatSloupec_triggered();

    void on_actionUlozit_triggered();

    void on_actionNastaveniExportu_triggered();

private:
    Ui::MainWindow *ui;
    QString oddelovac = ",";
    DialogNastaveni dn;
};
#endif // MAINWINDOW_H
