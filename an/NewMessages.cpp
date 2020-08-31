#include "NewMessages.h"
#include "ui_NewMessages.h"
#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"
#include "Answer.h"

NewMessages::NewMessages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMessages)
{
    ui->setupUi(this);
}

NewMessages::~NewMessages()
{
    delete ui;
}

void NewMessages::setValue(QJsonArray arr, int i)
{
    ui->newMessage->setText(arr[i].toString());
    ui->sender->setText(arr[i+2].toString());
    ui->date->setText(arr[i+3].toString());
}

void NewMessages::on_pushButton_2_clicked()
{
    seen();
    this->close();
}

void NewMessages::on_answer_clicked()
{
    Answer *a = new Answer(this);
    a->setWindowTitle("پاسخ");
    a->currentEmp = this->currentEmp;
    if(this->currentEmp == "Boss"){
        a->currentEmp = "مدیریت";
    }
    a->geterEmp = this->ui->sender->text();

    a->exec();
}

void NewMessages::seen()
{


    QString path = "Files/Messages/" + this->currentEmp + ".json";
    QFile f(path);


    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    QJsonArray arr;

    for(int i = 0 ; i < o[this->currentEmp].toArray().size() ; i+=4){
            arr.append((o[this->currentEmp].toArray())[i].toString());
            arr.append((o[this->currentEmp].toArray())[i+1].toString());
            arr.append((o[this->currentEmp].toArray())[i+2].toString());
            arr.append((o[this->currentEmp].toArray())[i+3].toString());
    }

    for(int i = 0 ; i < arr.size() ; i+=4){
        if((o[this->currentEmp].toArray())[i].toString() == ui->newMessage->toPlainText())
        {
            arr[i+1] = "r";
            break;
        }
    }
    f.close();



    QString path1 = "Files/Messages/" + this->currentEmp + ".json";
    QFile g(path1);
    g.open(QIODevice::WriteOnly);

    QJsonObject obj;
    obj[this->currentEmp] = arr;
    QJsonDocument h(obj);
    g.write(h.toJson());
    g.close();
}
