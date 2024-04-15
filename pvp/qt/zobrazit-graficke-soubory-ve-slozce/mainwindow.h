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

    void onItemClicked(const QModelIndex &index);
private slots:
    void on_pbTlacitko_clicked();

    void on_lvList_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QString selectedDirectory;
    QStringListModel *model;
};

#endif // MAINWINDOW_H
