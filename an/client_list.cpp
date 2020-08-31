#include "client_list.h"
#include "ui_client_list.h"

client_list::client_list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_list)
{
    readFile();

    ui->setupUi(this);
}

client_list::~client_list()
{
    delete ui;
}

void client_list::readFile()
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

void client_list::on_show_3_clicked()
{
    for (int i=0; i < arr.size(); i++) {
        QString path = "Files/Clients/" + arr[i].toString() + ".json";
        QFile f(path);

        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();


        int cnt;
        ui->Clint_table_3->insertRow(ui->Clint_table_3->rowCount());
        cnt = ui->Clint_table_3->rowCount() - 1;

        ui->Clint_table_3->setItem(cnt, 0, new QTableWidgetItem(o["companyName"].toString()));
        ui->Clint_table_3->setItem(cnt, 1, new QTableWidgetItem(o["bossName"].toString()));
        ui->Clint_table_3->setItem(cnt, 2, new QTableWidgetItem(o["contractType"].toString()));
        if(o["status"].toBool()){
            ui->Clint_table_3->setItem(cnt, 3, new QTableWidgetItem("درحال پیگیری"));
        }
        else{
            ui->Clint_table_3->setItem(cnt, 3, new QTableWidgetItem("به اتمام رسیده"));
        }


        ui->Clint_table_3->setItem(cnt, 4, new QTableWidgetItem(o["employeeUsername"].toString()));

    }
    ui->show_3->hide();
}

void client_list::on_exit_3_clicked()
{
    this->close();
}
