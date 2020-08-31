#ifndef ADDSUGGESTIONS_H
#define ADDSUGGESTIONS_H

#include <QDialog>

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

namespace Ui {
class AddSuggestions;
}

class AddSuggestions : public QDialog
{
    Q_OBJECT

public:
    explicit AddSuggestions(QWidget *parent = nullptr);
    ~AddSuggestions();

    void send();
    void setCombo();

    QString currentEmp;

private slots:
    void on_Exit_clicked();


    void on_submit_clicked();

    void on_send_clicked();

private:
    Ui::AddSuggestions *ui;

    QJsonArray arr;

};

#endif // ADDSUGGESTIONS_H
