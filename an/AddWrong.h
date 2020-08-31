#ifndef ADDWRONG_H
#define ADDWRONG_H

#include <QDialog>

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

namespace Ui {
class AddWrong;
}

class AddWrong : public QDialog
{
    Q_OBJECT

public:
    explicit AddWrong(QWidget *parent = nullptr);
    ~AddWrong();


    void send();
    void setCombo();

    QString currentEmp;

private slots:
    void on_Exit_clicked();


    void on_submit_clicked();

    void on_send_clicked();

private:
    Ui::AddWrong *ui;

    QJsonArray arr;


};

#endif // ADDWRONG_H
