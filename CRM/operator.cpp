#include "operator.h"
#include "ui_Operator.h"
#include "Profile.h"
#include "Employee.h"
#include "addclient.h"
#include "EditClient.h"
#include "ClientList.h"
#include "SureWarning.h"
#include "mainwindow.h"
#include "SendBox.h"
#include "NewMessages.h"
#include "MessageInbox.h"

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

Operator::Operator(QWidget *parent)
    : QDialog(parent),
      Employee()
    , ui(new Ui::Operator)
{

    ui->setupUi(this);
}

Operator::~Operator()
{
    delete ui;
}

void Operator::showNewMessage()
{
    QString path = "Files/Messages/" + this->username + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    QJsonArray arr;

    for(int i = 0 ; i < o[this->username].toArray().size() ; i+=4){
        if((o[this->username].toArray())[i+1].toString() == "u")
        {
            arr.append((o[this->username].toArray())[i].toString());
            arr.append((o[this->username].toArray())[i+1].toString());
            arr.append((o[this->username].toArray())[i+2].toString());
            arr.append((o[this->username].toArray())[i+3].toString());
        }
    }

    if(arr.size())
    {
        for(int i=0; i < arr.size(); i+=4)
        {
            NewMessages n;
            n.setWindowTitle("پیام جدید");
            n.setValue(arr, i);
            n.currentEmp = this->username;

            n.exec();

        }
    }


    f.close();
}


void Operator::on_see_prof_clicked()
{
    Profile dial(this);
    dial.setWindowTitle("پروفایل");
    dial.setValue(this);
    QObject::connect(&dial,&Profile::sendUpdatedValuseToOperator,this,&Operator::updateEmpValues);


    dial.exec();
}

void Operator::updateEmpValues(Employee emp)
{
    this->setFirstName(emp.getFirstName());
    this->setLastName(emp.getLastName());
    this->setId(emp.getId());
    this->setPNumber(emp.getPNumber());
    this->setLNumber(emp.getLNumber());
    this->setAddress(emp.getAddress());

    this->setUsername(emp.getUsername());
    this->setPassword(emp.getPassword());
    this->setUnit(emp.getUnit());
    this->setFixed(emp.getFixed());
    this->setPercent_s(emp.getPercent_s());
    this->setPercent_d(emp.getPercent_d());
    this->setSalary(emp.getSalary());
    this->setNOClient(emp.getNOClient());
    this->setNOVacations(emp.getNOVacations());
    this->setVariable(emp.getVariable());
    this->setImageUrl(emp.getimageUrl());
}


void Operator::on_Add_clt_clicked()
{
    AddClient AC(this);
    AC.setWindowTitle("افزودن مشتری جدید");
//    AC.cl.setemployeeUsername(this->getUsername());


    AC.exec();
}

void Operator::on_Del_clt_clicked()
{
    EditClient EC(this);
    EC.cl.setemployeeUsername(this->getUsername());
    EC.unit = "اپراتور";
    EC.setWindowTitle("ویرایش اطلاعات مشتری");


    EC.exec();
}

void Operator::on_see_clt_clicked()
{
    ClientList LC(this);
    LC.unit = "اپراتور";
    LC.setWindowTitle("لیست مشتریان");
    LC.on_show_clicked();

    LC.exec();
}

void Operator::on_logout_clicked()
{
    SureWarning sw(this);
    sw.setMessage("مطمئنید؟");
    sw.exec();
    if(sw.test == 1)
    {
        this->close();
        MainWindow* w = new MainWindow(this);
        w->show();
    }
}

void Operator::on_see_prof_2_clicked()
{
    SendBox s(this);
    s.setWindowTitle("ارسال پیام");
    s.messageText = this->ui->messageText->toPlainText();
    s.currentEmp = this->username;
    s.exec();
}

void Operator::on_Inbox_clicked()
{
    MessageInbox in(this);
    in.setWindowTitle("صندوق پیام ها");
    in.showMessage(this->username);

    in.exec();
}


void Operator::showActivedClients()
{
    //readFile()


    QJsonArray arr;

    QFile g("Files/Clients/companiesName.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();

    for(int i = 0 ; i < o["companiesName"].toArray().size() ; i++){
        arr.append((o["companiesName"].toArray())[i].toString());
    }
    g.close();

    //readFile()

    //setValue()
    for (int i=0; i < arr.size(); i++) {
        QString path = "Files/Clients/" + arr[i].toString() + ".json";
        QFile f(path);

        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();


            if(o["status"].toBool() == true)
            {
                int cnt;
                ui->activeClientTable->insertRow(ui->activeClientTable->rowCount());
                cnt = ui->activeClientTable->rowCount() - 1;

                ui->activeClientTable->setItem(cnt, 0, new QTableWidgetItem(o["companyName"].toString()));
                ui->activeClientTable->setItem(cnt, 1, new QTableWidgetItem(o["bossName"].toString()));
                ui->activeClientTable->setItem(cnt, 2, new QTableWidgetItem(o["companyPhoneNumber"].toString()));
                ui->activeClientTable->setItem(cnt, 3, new QTableWidgetItem(o["stateName"].toString()));
                ui->activeClientTable->setItem(cnt, 4, new QTableWidgetItem(o["employeeUsername"].toString()));
            }



    }

    //setValue()
}
