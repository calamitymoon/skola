#ifndef DIALOGNASTAVENI_H
#define DIALOGNASTAVENI_H

#include <QDialog>

namespace Ui {
class DialogNastaveni;
}

class DialogNastaveni : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNastaveni(QWidget *parent = nullptr);
    ~DialogNastaveni();
    QString getJmeno();
    QString getPrijmeni();
    QString getTelefon();


private:
    Ui::DialogNastaveni *ui;
};

#endif // DIALOGNASTAVENI_H
