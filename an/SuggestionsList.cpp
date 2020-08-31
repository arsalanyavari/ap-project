#include "SuggestionsList.h"
#include "ui_SuggestionsList.h"

SuggestionsList::SuggestionsList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SuggestionsList)
{
    ui->setupUi(this);
}

SuggestionsList::~SuggestionsList()
{
    delete ui;
}

void SuggestionsList::setValues()
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


        if(ob["contractType"].toString() == "ساپورت")
        {
            QString path2 = "Files/Suggestions/" + arr[i].toString() + ".json";
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


            for (int j=0; j < array.size(); j+=3)
            {
                if(array[j+1].toString() == "انتقاد"){

                    int cnt;
                    ui->entTable->insertRow(ui->entTable->rowCount());
                    cnt = ui->entTable->rowCount() - 1;

                    ui->entTable->setItem(cnt, 0, new QTableWidgetItem(arr[i].toString()));
                    ui->entTable->setItem(cnt, 1, new QTableWidgetItem(array[j+2].toString()));
                    ui->entTable->setItem(cnt, 2, new QTableWidgetItem(array[j].toString()));
                }

                if(array[j+1].toString() == "پیشنهاد"){

                    int cnt;
                    ui->pishTable->insertRow(ui->pishTable->rowCount());
                    cnt = ui->pishTable->rowCount() - 1;

                    ui->pishTable->setItem(cnt, 0, new QTableWidgetItem(arr[i].toString()));
                    ui->pishTable->setItem(cnt, 1, new QTableWidgetItem(array[j+2].toString()));
                    ui->pishTable->setItem(cnt, 2, new QTableWidgetItem(array[j].toString()));
                }
            }
        }
    }
}

void SuggestionsList::on_exit_clicked()
{
    this->close();
}
