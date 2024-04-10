#ifndef PERSONALDIALOG_H
#define PERSONALDIALOG_H

#include <QDialog>

namespace Ui {
class PersonalDialog;
}

class PersonalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalDialog(QWidget *parent = nullptr);
    ~PersonalDialog();

    QString jmeno() const;
    int vek() const;
    double vyplata() const;

    enum sloupek
    {
        JMENO, VEK, VYPLATA
    };

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PersonalDialog *ui;
};

#endif // PERSONALDIALOG_H

// Dominik Jůza
