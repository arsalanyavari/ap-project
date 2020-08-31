#include "MessageInbox.h"
#include "ui_MessageInbox.h"

MessageInbox::MessageInbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageInbox)
{
    ui->setupUi(this);
}

MessageInbox::~MessageInbox()
{
    delete ui;
}

void MessageInbox::showMessage(QString currentEmp)
{
    QString path = "Files/Messages/" + currentEmp + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    QJsonArray arr;

    for(int i = 0 ; i < o[currentEmp].toArray().size() ; i+=4){
            arr.append((o[currentEmp].toArray())[i].toString());
            arr.append((o[currentEmp].toArray())[i+1].toString());
            arr.append((o[currentEmp].toArray())[i+2].toString());
            arr.append((o[currentEmp].toArray())[i+3].toString());

    }

    for(int i=arr.size()-1; i> 0 ;i-=4){
        int cnt;
        ui->MessageTable->insertRow(ui->MessageTable->rowCount());
        cnt = ui->MessageTable->rowCount() - 1;

        ui->MessageTable->setItem(cnt, 0, new QTableWidgetItem(arr[i-1].toString()));
        ui->MessageTable->setItem(cnt, 1, new QTableWidgetItem(arr[i].toString()));
        ui->MessageTable->setItem(cnt, 2, new QTableWidgetItem(arr[i-3].toString()));
    }
}

void MessageInbox::on_pushButton_clicked()
{
    this->close();
}

