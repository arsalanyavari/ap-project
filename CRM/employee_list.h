#ifndef EMPLOYEE_LIST_H
#define EMPLOYEE_LIST_H

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"
#include <QDialog>

namespace Ui {
class employee_list;
}

class employee_list : public QDialog
{
    Q_OBJECT

public:
    explicit employee_list(QWidget *parent = nullptr);
    ~employee_list();

private slots:
    void on_pushButton_clicked();

private:
    Ui::employee_list *ui;
    QJsonArray arr;
    void readFile();

    QJsonArray arr_f;
    void readFile_f();

};

#endif // EMPLOYEE_LIST_H
