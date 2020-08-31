#include <QDateTime>
#include "AddProject.h"
#include "ui_AddProject.h"


AddProject::AddProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProject)
{
    ui->setupUi(this);
}

AddProject::~AddProject()
{
    delete ui;
}

void AddProject::setCombo()
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



        if(o["contractType"].toString() == "مارکتینگ")
        {
            ui->proClient->addItem(arr[i].toString());
        }




    }
}

void AddProject::save()
{
    QString path = "Files/Projects/" + ui->proClient->currentText() + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    QJsonArray a;

    for(int i = 0 ; i < o[ui->proClient->currentText()].toArray().size() ; i++){
        a.append((o[ui->proClient->currentText()].toArray())[i].toString());
    }

    QDateTime local(QDateTime::currentDateTime());

    a.append(ui->proTitle->text());
    a.append(ui->proType->currentText());
    a.append(local.toString());
    a.append(ui->proComment->toPlainText());

    f.close();



    QString path1 = "Files/Projects/" + ui->proClient->currentText() + ".json";
    QFile g(path1);
    g.open(QIODevice::WriteOnly);

    QJsonObject obj;
    obj[ui->proClient->currentText()] = a;
    QJsonDocument h(obj);
    g.write(h.toJson());
    g.close();

    this->close();
}

void AddProject::on_pushButton_clicked()
{
    save();
    this->close();
}

void AddProject::on_pushButton_2_clicked()
{
    this->close();
}
