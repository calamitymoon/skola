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
    bool getZahlavi();
    bool getImportZahlavi();

    const QString &getImportOddelovac() const;

private slots:
    void on_rbCarka_pressed();

    void on_rbStrednik_pressed();

    void on_rbTabulator_clicked();

    void on_rbVlastni_clicked();

    void on_leVlastni_editingFinished();

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

    void on_leImportVlastni_editingFinished();

private:
    Ui::DialogNastaveni *ui;
    QString oddelovac = ",";
    QString importOddelovac = ",";
};

#endif // DIALOGNASTAVENI_H
