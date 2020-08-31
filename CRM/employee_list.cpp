#include "employee_list.h"
#include "ui_employee_list.h"

employee_list::employee_list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employee_list)
{
    ui->setupUi(this);

    readFile();
    readFile_f();
    for (int i=0; i < arr.size(); i++) {
        QString path = "Files/Employees/" + arr[i].toString() + ".json";
        QFile f(path);

        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        f.close();

        int cnt;
        ui->employees->insertRow(ui->employees->rowCount());
        cnt = ui->employees->rowCount() - 1;

        ui->employees->setItem(cnt, 0, new QTableWidgetItem(o[arr[i].toString()].toObject()["human"].toObject()["firstName"].toString()));
        ui->employees->setItem(cnt, 1, new QTableWidgetItem(o[arr[i].toString()].toObject()["human"].toObject()["lastName"].toString()));
        ui->employees->setItem(cnt, 2, new QTableWidgetItem(o[arr[i].toString()].toObject()["human"].toObject()["id"].toString()));
        ui->employees->setItem(cnt, 3, new QTableWidgetItem(o[arr[i].toString()].toObject()["employee"].toObject()["unit"].toString()));

    }

    for (int i=0; i < arr_f.size(); i++) {
        QString Path = "Files/Employees/" + arr_f[i].toString() + ".json";
        QFile j(Path);

        j.open(QIODevice::ReadOnly);
        QByteArray b = j.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();


        int cnt;
        ui->fired_employees->insertRow(ui->fired_employees->rowCount());
        cnt = ui->fired_employees->rowCount() - 1;

        ui->fired_employees->setItem(cnt, 0, new QTableWidgetItem(o[arr_f[i].toString()].toObject()["human"].toObject()["firstName"].toString()));
        ui->fired_employees->setItem(cnt, 1, new QTableWidgetItem(o[arr_f[i].toString()].toObject()["human"].toObject()["lastName"].toString()));
        ui->fired_employees->setItem(cnt, 2, new QTableWidgetItem(o[arr_f[i].toString()].toObject()["human"].toObject()["id"].toString()));
        ui->fired_employees->setItem(cnt, 3, new QTableWidgetItem(o[arr_f[i].toString()].toObject()["employee"].toObject()["unit"].toString()));

    }


}

employee_list::~employee_list()
{
    delete ui;
}


void employee_list::readFile()
{
    QFile g("Files/Employees/EmployeeUsername.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();

    for(int i = 0 ; i < o["employee"].toArray().size() ; i++){
        arr.append((o["employee"].toArray())[i].toString());
    }
    g.close();

}


void employee_list::readFile_f()
{
    QFile g("Files/Employees/FiredEmployeeUsername.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();

    for(int i = 0 ; i < o["employee"].toArray().size() ; i++){
        arr_f.append((o["employee"].toArray())[i].toString());
    }
    g.close();

}




void employee_list::on_pushButton_clicked()
{
    this->close();
}
