#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QListView>
#include <QComboBox>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QStringListModel>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pbTlacitko_clicked();

private:
    Ui::MainWindow *ui;
    QString selectedDirectory;
    QStringListModel *model;
};

#endif // MAINWINDOW_H
