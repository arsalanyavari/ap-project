#include <QDateTime>
#include "AddWrong.h"
#include "ui_AddWrong.h"
#include "SendBox.h"

AddWrong::AddWrong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWrong)
{
    ui->setupUi(this);
}

AddWrong::~AddWrong()
{
    delete ui;
}


void AddWrong::send()
{
    QString path = "Files/Wrongs/" + ui->List_of_Clt->currentText() + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    QJsonArray a;

    for(int i = 0 ; i < o[ui->List_of_Clt->currentText()].toArray().size() ; i++){
        a.append((o[ui->List_of_Clt->currentText()].toArray())[i].toString());
    }

    QDateTime local(QDateTime::currentDateTime());

    a.append(ui->wrongText->toPlainText());
    a.append(ui->category->currentText());
    a.append(local.toString());

    f.close();



    QString path1 = "Files/Wrongs/" + ui->List_of_Clt->currentText() + ".json";
    QFile g(path1);
    g.open(QIODevice::WriteOnly);

    QJsonObject obj;
    obj[ui->List_of_Clt->currentText()] = a;
    QJsonDocument h(obj);
    g.write(h.toJson());
    g.close();

    this->close();
}

void AddWrong::setCombo()
{
    QFile g("Files/Clients/companiesName.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();

    for(int i = 0 ; i < o["companiesName"].toArray().size() ; i++){
        arr.append((o["companiesName"].toArray())[i].toString());
    }
    g.close();





    for (int i=0; i < arr.size(); i++) {
        QString path = "Files/Clients/" + arr[i].toString() + ".json";
        QFile f(path);

        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();



        if(o["contractType"].toString() == "ساپورت")
        {
            ui->List_of_Clt->addItem(arr[i].toString());
        }

    }

}

void AddWrong::on_Exit_clicked()
{
    this->close();
}

void AddWrong::on_submit_clicked()
{
    send();
    this->close();
}

void AddWrong::on_send_clicked()
{
    QString toMessage;
    toMessage = "مشکل جدید گزارش شده\nاهمیت: " + ui->category->currentText() + "\nنام مشتری: " +ui->List_of_Clt->currentText() + "\n" + ui->wrongText->toPlainText();

    SendBox *s = new SendBox(this);
    s->setWindowTitle("ارسال");
    s->messageText = toMessage;
    s->currentEmp = this->currentEmp;
    s->exec();
}
