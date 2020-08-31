#include "ProjectList.h"
#include "ui_ProjectList.h"

ProjectList::ProjectList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectList)
{
    ui->setupUi(this);
}

ProjectList::~ProjectList()
{
    delete ui;
}

void ProjectList::setValues()
{
    QFile g("Files/Clients/companiesName.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();

    QJsonArray arr;

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
        QJsonObject ob = d.object();


        if(ob["contractType"].toString() == "مارکتینگ")
        {
            QString path2 = "Files/Projects/" + arr[i].toString() + ".json";
            QFile p(path2);

            p.open(QIODevice::ReadOnly);
            QByteArray m = p.readAll();
            QJsonDocument n = QJsonDocument::fromJson(m);
            QJsonObject obj = n.object();


            QJsonArray array;
            for(int k = 0; k < (obj[arr[i].toString()].toArray()).size(); k++)
            {
                array.append((obj[arr[i].toString()].toArray())[k].toString());
            }


            for (int j=0; j < array.size(); j+=4)
            {
                    int cnt;
                    ui->proTable->insertRow(ui->proTable->rowCount());
                    cnt = ui->proTable->rowCount() - 1;

                    ui->proTable->setItem(cnt, 0, new QTableWidgetItem(array[j].toString()));
                    ui->proTable->setItem(cnt, 1, new QTableWidgetItem(array[j+1].toString()));
                    ui->proTable->setItem(cnt, 2, new QTableWidgetItem(arr[i].toString()));
                    ui->proTable->setItem(cnt, 3, new QTableWidgetItem(array[j+2].toString()));
                    ui->proTable->setItem(cnt, 4, new QTableWidgetItem(array[j+3].toString()));

            }
        }
    }
}


void ProjectList::on_pushButton_clicked()
{
    this->close();
}
