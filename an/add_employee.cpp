#include <QDebug>
#include <QMessageBox>
#include <string>
#include "add_employee.h"
#include "ui_add_employee.h"
#include "Employee.h"

add_employee::add_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_employee)
{
    ui->setupUi(this);
}

add_employee::~add_employee()
{
    delete ui;
}

void add_employee::on_pushButton_2_clicked()
{
    this->close();
}

void add_employee::on_pushButton_clicked()
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

    int i = 0;
    bool check =false;
    for (; i< arr.size(); i++)
    {
        QString path = "Files/Employees/" + arr[i].toString() + ".json";
        QFile f(path);

        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        o = d.object();
        if(ui->ID_Input->text()==(o[arr[i].toString()].toObject()["human"].toObject()["id"].toString()))
        {
            check =true;
            break;
        }
        f.close();
    }



    if(check)
    {
        for (int i=arr.size() ;i>0 ;i--) {
            arr.removeLast();
        }

        QMessageBox::warning(this,"اخطار", "کارمند در لیست قرار دارد");
    }

    bool check1 = false;
    for(int i=0; i< arr.size();i++)
    {
        if(arr[i]==ui->username->text())
        {
            check1 =true;
            break;
        }
    }



    if(check1)
    {
        for (int i=arr.size() ;i>0 ;i--) {
            arr.removeLast();
        }
        QMessageBox::warning(this,"اخطار", "نام کاربری قبلا استفاده شده است");
    }

    if(!check && !check1)
    {


        arr.append(ui->username->text());
        QFile f("Files/Employees/EmployeeUsername.json");
        f.open(QIODevice::WriteOnly);


        QJsonObject obj;
        obj["employee"] = arr;
        QJsonDocument d(obj);
        f.write(d.toJson());
        f.close();



        Employee *emp = new Employee();
        emp->setFirstName(ui->Name_Input->text());
        emp->setLastName(ui->Family_Input->text());
        emp->setUnit(ui->Category->currentText());
        emp->setId(ui->ID_Input->text());
        emp->setLNumber(ui->Thelphon->text());
        emp->setPNumber(ui->Tell->text());
        emp->setSalary(ui->salary->text());
        emp->setPercent_d(ui->percent->text().toDouble());
        emp->setPercent_s(ui->percent->text());
        emp->setAddress(ui->Addres->text());
        emp->setPassword(ui->ID_Input->text());




        QString path = "Files/Employees/" + ui->username->text() + ".json";
        QFile g(path);


        g.open(QIODevice::WriteOnly);

        QJsonObject o , p , q , r;
        p["fixed"] = emp->getSalary();
        p["imageUrl"] = "";
        p["numberofClient"] = "";
        p["numberofVacations"] = "";
        p["password"] = emp->getId();
        p["percent_d"] = emp->getPercent_d();
        p["percent_s"] = emp->getPercent_s();
        p["salary"] = emp->getSalary();
        p["unit"] = emp->getUnit();
        p["username"] = ui->username->text();
        p["variable"] = "";
        o["employee"] = p;

        q["address"] = emp->getAddress();
        q["firstName"]= emp->getFirstName();
        q["id"] = emp->getId();
        q["lNumber"] = emp->getLNumber();
        q["lastName"] = emp->getLastName();
        q["pNumber"] = emp->getPNumber();

        o["human"] = q;
        r[ui->username->text()] = o;

        QJsonDocument e(r);
        g.write(e.toJson());

        g.close();



        this->close();
}





}
