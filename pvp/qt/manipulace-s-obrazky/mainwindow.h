#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMenu>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

private slots:
    void showImageDetails();
    void openImage();

private:
    QImage image;
    QDir currentDir;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QMenu *contextMenu;
    QAction *detailsAction;
    QAction *openAction;
    QString currentFile;
};

#endif // MAINWINDOW_H

