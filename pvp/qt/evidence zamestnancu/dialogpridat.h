#ifndef DIALOGPRIDAT_H
#define DIALOGPRIDAT_H

#include <QDialog>

namespace Ui {
class DialogPridat;
}

class DialogPridat : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPridat(QWidget *parent = nullptr);
    ~DialogPridat();
    QString jmeno();
    QString vek();
    QString plat();
    QString telefon();


private:
    Ui::DialogPridat *ui;
};

#endif // DIALOGPRIDAT_H
