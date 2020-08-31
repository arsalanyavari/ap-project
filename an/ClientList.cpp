#include "ClientList.h"
#include "ui_ClientList.h"

ClientList::ClientList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientList)
{
    readFile();

    ui->setupUi(this);
}

ClientList::~ClientList()
{
    delete ui;
}

void ClientList::readFile()
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

}

void ClientList::on_show_clicked()
{
    for (int i=0; i < arr.size(); i++) {
        QString path = "Files/Clients/" + arr[i].toString() + ".json";
        QFile f(path);

        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();



        if(o["contractType"].toString() == this->unit || this->unit == "اپراتور")
        {
            int cnt;
            ui->Clint_table->insertRow(ui->Clint_table->rowCount());
            cnt = ui->Clint_table->rowCount() - 1;

            ui->Clint_table->setItem(cnt, 0, new QTableWidgetItem(o["companyName"].toString()));
            ui->Clint_table->setItem(cnt, 1, new QTableWidgetItem(o["bossName"].toString()));
            ui->Clint_table->setItem(cnt, 2, new QTableWidgetItem(o["contractType"].toString()));
            if(o["status"].toBool()){
                ui->Clint_table->setItem(cnt, 3, new QTableWidgetItem("درحال پیگیری"));
            }
            else{
                ui->Clint_table->setItem(cnt, 3, new QTableWidgetItem("به اتمام رسیده"));
            }


            ui->Clint_table->setItem(cnt, 4, new QTableWidgetItem(o["employeeUsername"].toString()));
        }




    }
    ui->show->hide();
}


void ClientList::on_exit_clicked()
{
    this->close();

}


