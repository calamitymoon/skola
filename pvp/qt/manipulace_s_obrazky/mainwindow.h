#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include <QMenu>
#include <QVBoxLayout>
#include <QDir>
#include <QFileInfo>
#include <QPixmap>
#include <QImageReader>
#include <QMessageBox>
#include <QAction>
#include <QContextMenuEvent>
#include <QScrollArea>
#include <QDebug>
#include <QGraphicsView>
#include <QScrollBar>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void zobrazitContextMenu(QLabel *label, const QPoint &pozice);

    void on_openFolder_triggered();

private:
    Ui::MainWindow *ui;

    QVBoxLayout *layoutProScrollovani;
    QList<QString> listUmisteniObrazku;
    int currentIndex;

    QLabel *nahledObrazku;
    QLabel *nahledovyLabel = nullptr;
    QString aktualniUmisteniObrazku;

    void vycistitLayout(QLayout *layout);
    void zobrazitObrazek(int index);
    void nacistNahled(const QString &umisteniSouboru);

    void updatovaniScrollBaru();
};
#endif // MAINWINDOW_H
