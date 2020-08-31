#include "addclient.h"
#include "ui_addclient.h"

AddClient::AddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);
}

AddClient::~AddClient()
{
    delete ui;
}

void AddClient::applyChanges()
{
    cl.setCompanyName(ui->companyName->text());
    cl.setCompanyType(ui->companyType->currentText());
    cl.setCompanyPhoneNumber(ui->companyPN->text());
    cl.setCompanyAddress(ui->companyAddress->text());
    cl.setBossName(ui->bossName->text());
    cl.setBossEmail(ui->bossEmail->text());
    cl.setBossPhoneNumber(ui->bossPN->text());
    cl.setStateName(ui->stateName->currentText());
    cl.setCityName(ui->cityName->text());
    cl.setContractType(ui->contractType->currentText());
    cl.setemployeeUsername(ui->empUsername->currentText());
}



void AddClient::on_save_clicked()
{
    this->applyChanges();
    this->cl.updateJsonValues();

    this->close();
}


void AddClient::on_contractType_activated(int index)
{
    ui->empUsername->clear();


    QFile g("Files/Employees/EmployeeUsername.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();

    QJsonArray arr;
    for(int i = 0 ; i < o["employee"].toArray().size() ; i++)
    {
        arr.append((o["employee"].toArray())[i].toString());
    }
    g.close();


    if(index == 0)
    {
        for(int i=0; i<arr.size() ;i++)
        {
            QString path = "Files/Employees/" + arr[i].toString() +".json";
            QFile g(path);
            g.open(QIODevice::ReadOnly);
            QByteArray r = g.readAll();
            QJsonDocument t = QJsonDocument::fromJson(r);
            QJsonObject o = t.object();

            if(((o[arr[i].toString()].toObject())["employee"].toObject())["unit"].toString() == "کارمند فروش"){
                ui->empUsername->addItem(arr[i].toString());
            }
        }



    }
    else if(index == 1)
    {
        for(int i=0; i<arr.size() ;i++)
        {
            QString path = "Files/Employees/" + arr[i].toString() +".json";
            QFile g(path);
            g.open(QIODevice::ReadOnly);
            QByteArray r = g.readAll();
            QJsonDocument t = QJsonDocument::fromJson(r);
            QJsonObject o = t.object();

            if(((o[arr[i].toString()].toObject())["employee"].toObject())["unit"].toString() == "کارمند پشتیبانی"){
                ui->empUsername->addItem(arr[i].toString());
            }
         }
    }
}

void AddClient::on_empUsername_activated(const QString &arg1)
{
    if(arg1 != nullptr)
    {
        ui->save->setEnabled(1);
    }
}
