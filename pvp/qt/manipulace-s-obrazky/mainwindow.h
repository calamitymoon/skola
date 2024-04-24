#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QAction>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

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
    void on_actionOtevrit_triggered();

    void on_actionOtocit_o_90_stupnu_triggered();

    void on_actionOtocit_o_minus_90_stupnu_triggered();

    void on_actionUlozit_triggered();

private:
    Ui::MainWindow *ui;
    void zobrazitObrazek(const QPixmap &pixmap);
    QDialog *obrazekDialog = nullptr;
    QLabel *obrazekLabel = nullptr;
};
#endif // MAINWINDOW_H
