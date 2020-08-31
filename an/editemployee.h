#ifndef EDITEMPLOYEE_H
#define EDITEMPLOYEE_H

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"
#include <QDialog>

namespace Ui {
class editemployee;
}

class editemployee : public QDialog
{
    Q_OBJECT

public:
    explicit editemployee(QWidget *parent = nullptr);
    ~editemployee();

private slots:
    void on_pushButton_2_clicked();

    void on_save_2_clicked();

    void on_delete_3_clicked();

private:
    Ui::editemployee *ui;
    QJsonArray arr;
    QJsonArray arr_2;
    QJsonArray arr_3;
    QString u_name;
    bool ch;
};

#endif // EDITEMPLOYEE_H
