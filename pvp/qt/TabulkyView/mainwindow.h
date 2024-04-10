#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRelationalTableModel>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include "dialogpridat.h"

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
    void on_actionNova_triggered();

    void on_actionPridat_triggered();

    void on_actionOtevrit_triggered();

    void on_actionKonec_triggered();

    void on_leVyhledavac_textChanged(const QString &argument);

private:
    Ui::MainWindow *ui;
    QSqlDatabase databaze;
    QSqlRelationalTableModel *model;
};
#endif // MAINWINDOW_H
