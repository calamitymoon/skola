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

    const QString &getOddelovac() const;

private slots:
    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_clicked();

private:
    Ui::DialogNastaveni *ui;
     QString oddelovac = ",";
};

#endif // DIALOGNASTAVENI_H
