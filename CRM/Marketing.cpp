#include "Marketing.h"
#include "ui_Marketing.h"

#include "Profile.h"
#include "EditClient.h"
#include "ClientList.h"
#include "SureWarning.h"
#include "mainwindow.h"
#include "SendBox.h"
#include "NewMessages.h"
#include "MessageInbox.h"
#include "AddProject.h"
#include "ProjectList.h"

#include <QMessageBox>
#include <QDateTime>

Marketing::Marketing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Marketing)
{
    ui->setupUi(this);
}

Marketing::~Marketing()
{
    delete ui;
}

void Marketing::showNewMessage()
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

void Marketing::updateEmpValues(Employee emp)
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

void Marketing::on_see_prof_clicked()
{
    Profile dial(this);
    dial.setWindowTitle("پروفایل");
    dial.setValue(this);
    QObject::connect(&dial,&Profile::sendUpdatedValuseToOperator,this,&Marketing::updateEmpValues);


    dial.exec();
}

void Marketing::on_Del_clt_clicked()
{
    EditClient EC(this);
    EC.cl.setemployeeUsername(this->getUsername());
    EC.unit = "مارکتینگ";
    EC.setWindowTitle("ویرایش اطلاعات مشتری");


    EC.exec();
}

void Marketing::on_see_clt_clicked()
{
    ClientList LC(this);
    LC.unit = "مارکتینگ";
    LC.setWindowTitle("لیست مشتریان");
    LC.on_show_clicked();

    LC.exec();
}

void Marketing::on_logout_clicked()
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

void Marketing::on_see_prof_2_clicked()
{
    SendBox s(this);
    s.setWindowTitle("ارسال پیام");
    s.messageText = this->ui->messageText->toPlainText();
    s.currentEmp = this->username;
    s.exec();
}



void Marketing::on_Inbox_clicked()
{
    MessageInbox in(this);
    in.setWindowTitle("صندوق پیام ها");
    in.showMessage(this->username);

    in.exec();
}




void Marketing::on_AddProject_clicked()
{
    AddProject AP(this);
    AP.setWindowTitle("افزودن پرونده جدید");
    AP.setCombo();

    AP.exec();
}

void Marketing::on_ProjectList_clicked()
{
    ProjectList PL(this);
    PL.setWindowTitle("لیست پرونده ها");
    PL.setValues();

    PL.exec();
}


void Marketing::showActivedClients()
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



        if(o["contractType"].toString() == "مارکتینگ")
        {
            if(o["status"].toBool() == true)
            {
                int cnt;
                ui->activeClientTable->insertRow(ui->activeClientTable->rowCount());
                cnt = ui->activeClientTable->rowCount() - 1;

                ui->activeClientTable->setItem(cnt, 0, new QTableWidgetItem(o["companyName"].toString()));
                ui->activeClientTable->setItem(cnt, 1, new QTableWidgetItem(o["bossName"].toString()));
                ui->activeClientTable->setItem(cnt, 2, new QTableWidgetItem(o["companyPhoneNumber"].toString()));
                ui->activeClientTable->setItem(cnt, 3, new QTableWidgetItem(o["stateName"].toString()));
                ui->activeClientTable->setItem(cnt, 4, new QTableWidgetItem("درحال پیگیری"));
            }

        }




    }

    //setValue()
}
