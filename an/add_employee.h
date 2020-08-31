#ifndef ADD_EMPLOYEE_H
#define ADD_EMPLOYEE_H

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"
#include <QDialog>

namespace Ui {
class add_employee;
}

class add_employee : public QDialog
{
    Q_OBJECT

public:
    explicit add_employee(QWidget *parent = nullptr);
    ~add_employee();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::add_employee *ui;
    QJsonArray arr;
    void readFile();
};

#endif // ADD_EMPLOYEE_H
