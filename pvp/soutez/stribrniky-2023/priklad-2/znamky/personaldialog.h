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

    QDate datum() const;
    QString jmeno() const;
    QString predmet() const;
    int znamka() const;

    enum sloupek
    {
        DATUM, JMENO, PREDMET, ZNAMKA
    };

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PersonalDialog *ui;
};

#endif // PERSONALDIALOG_H

// Dominik Jůza
