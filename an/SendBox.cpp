#include <QMessageBox>
#include <QDateTime>
#include "SendBox.h"
#include "ui_SendBox.h"


void SendBox::readFile()
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

void SendBox::showCombo(QString unit)
{
    for (int i=0; i < arr.size(); i++) {
        QString path = "Files/Employees/" + arr[i].toString() + ".json";
        QFile f(path);

        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();



        if(((o[arr[i].toString()].toObject())["employee"].toObject())["unit"].toString() == unit && arr[i].toString() != this->currentEmp)
        {
           if(unit == "کارمند پشتیبانی"){
               ui->empUsername_support->addItem(arr[i].toString());
           }
           else if(unit == "کارمند فروش"){
               ui->empUsername_marketing->addItem(arr[i].toString());
           }
           else if(unit ==  "کارمند اپراتور"){
               ui->empUsername_operator->addItem(arr[i].toString());
           }

        }

    }
}

void SendBox::sendNewMessage(QString empUsername)
{
    QString path = "Files/Messages/" + empUsername + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    QJsonArray arr;

    for(int i = 0 ; i < o[empUsername].toArray().size() ; i++){
        arr.append((o[empUsername].toArray())[i].toString());
    }

    QDateTime local(QDateTime::currentDateTime());

    arr.append(this->messageText);
    if(ui->notif->isChecked()){
        arr.append("u");
    }
    else{
        arr.append("r");
    }
    arr.append(this->currentEmp);
    arr.append(local.toString());

    f.close();



    QString path1 = "Files/Messages/" + empUsername + ".json";
    QFile g(path1);
    g.open(QIODevice::WriteOnly);

    QJsonObject obj;
    obj[empUsername] = arr;
    QJsonDocument h(obj);
    g.write(h.toJson());
    g.close();
}

SendBox::SendBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendBox)
{
    supportCheck = true;
    marketingCheck = true;
    operatorCheck = true;

    readFile();
    ui->setupUi(this);
}

SendBox::~SendBox()
{
    delete ui;
}

void SendBox::hideBoss()
{
    ui->boss->hide();
    ui->markting_3->hide();
}

void SendBox::on_exit_clicked()
{
    this->close();
}

void SendBox::on_support_clicked()
{
    if(supportCheck)
    {
        showCombo("کارمند پشتیبانی");
        supportCheck = false;
    }
    else if(!supportCheck){
        ui->empUsername_support->clear();
        supportCheck = true;
    }


}

void SendBox::on_marketing_clicked()
{
    if(marketingCheck)
    {
        showCombo("کارمند فروش");
        marketingCheck = false;
    }
    else if(!marketingCheck){
        ui->empUsername_marketing->clear();
        marketingCheck = true;
    }
}

void SendBox::on_operator_2_clicked()
{
    if(operatorCheck)
    {
        showCombo("کارمند اپراتور");
        operatorCheck = false;
    }
    else if(!operatorCheck){
        ui->empUsername_operator->clear();
        operatorCheck = true;
    }
}

void SendBox::on_boss_clicked(){}

void SendBox::on_select_clicked()
{
    if(!ui->operator_2->isChecked() && !ui->support->isChecked() && !ui->marketing->isChecked() && !ui->boss->isChecked())
    {
     QMessageBox::warning(this, "اخطار", "هیچ آیتمی انتخاب نشده است!");
    }
    else
    {
        if(ui->operator_2->isChecked())
        {
            sendNewMessage(this->ui->empUsername_operator->currentText());

        }
        if(ui->support->isChecked())
        {
            sendNewMessage(this->ui->empUsername_support->currentText());

        }
        if(ui->marketing->isChecked())
        {
            sendNewMessage(this->ui->empUsername_marketing->currentText());

        }
        if(ui->boss->isChecked())
        {
            sendNewMessage("Boss");
        }
        this->close();
    }

}
