#include "WrongList.h"
#include "ui_WrongList.h"

WrongList::WrongList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WrongList)
{
    ui->setupUi(this);
}

WrongList::~WrongList()
{
    delete ui;
}



void WrongList::setValues()
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
            QString path2 = "Files/Wrongs/" + arr[i].toString() + ".json";
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
                if(array[j+1].toString() == "خیلی زیاد"){

                    int cnt;
                    ui->wrong1->insertRow(ui->wrong1->rowCount());
                    cnt = ui->wrong1->rowCount() - 1;

                    ui->wrong1->setItem(cnt, 0, new QTableWidgetItem(arr[i].toString()));
                    ui->wrong1->setItem(cnt, 1, new QTableWidgetItem(array[j+2].toString()));
                    ui->wrong1->setItem(cnt, 2, new QTableWidgetItem(array[j].toString()));
                }

                if(array[j+1].toString() == "زیاد"){

                    int cnt;
                    ui->wrong2->insertRow(ui->wrong2->rowCount());
                    cnt = ui->wrong2->rowCount() - 1;

                    ui->wrong2->setItem(cnt, 0, new QTableWidgetItem(arr[i].toString()));
                    ui->wrong2->setItem(cnt, 1, new QTableWidgetItem(array[j+2].toString()));
                    ui->wrong2->setItem(cnt, 2, new QTableWidgetItem(array[j].toString()));
                }

                if(array[j+1].toString() == "متوسط"){

                    int cnt;
                    ui->wrong3->insertRow(ui->wrong3->rowCount());
                    cnt = ui->wrong3->rowCount() - 1;

                    ui->wrong3->setItem(cnt, 0, new QTableWidgetItem(arr[i].toString()));
                    ui->wrong3->setItem(cnt, 1, new QTableWidgetItem(array[j+2].toString()));
                    ui->wrong3->setItem(cnt, 2, new QTableWidgetItem(array[j].toString()));
                }

                if(array[j+1].toString() == "کم"){

                    int cnt;
                    ui->wrong4->insertRow(ui->wrong4->rowCount());
                    cnt = ui->wrong4->rowCount() - 1;

                    ui->wrong4->setItem(cnt, 0, new QTableWidgetItem(arr[i].toString()));
                    ui->wrong4->setItem(cnt, 1, new QTableWidgetItem(array[j+2].toString()));
                    ui->wrong4->setItem(cnt, 2, new QTableWidgetItem(array[j].toString()));
                }
            }
        }
    }
}

void WrongList::on_exit_clicked()
{
    this->close();
}
