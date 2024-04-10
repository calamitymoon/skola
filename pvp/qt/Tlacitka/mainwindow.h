#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QPushButton>


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
    void on_actionRozdej_2_triggered();
    void stisknuto();

private:
    Ui::MainWindow *ui;
    std::vector<QPushButton*> tlacitka;
    void smazTlacitka();

};
#endif // MAINWINDOW_H
