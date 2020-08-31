#include "Answer.h"
#include "ui_Answer.h"

Answer::Answer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Answer)
{
    ui->setupUi(this);
}

Answer::~Answer()
{
    delete ui;
}

void Answer::on_sendButton_clicked()
{
    if(geterEmp == "مدیریت"){
        geterEmp = "Boss";
    }

    QString path = "Files/Messages/" + geterEmp + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    QJsonArray arr;

    for(int i = 0 ; i < o[geterEmp].toArray().size() ; i++){
        arr.append((o[geterEmp].toArray())[i].toString());
    }

    QDateTime local(QDateTime::currentDateTime());

    arr.append(ui->answerMessage->toPlainText());
    if(ui->notif->isChecked()){
        arr.append("u");
    }
    else{
        arr.append("r");
    }
    arr.append(this->currentEmp);
    arr.append(local.toString());

    f.close();



    QString path1 = "Files/Messages/" + geterEmp + ".json";
    QFile g(path1);
    g.open(QIODevice::WriteOnly);

    QJsonObject obj;
    obj[geterEmp] = arr;
    QJsonDocument h(obj);
    g.write(h.toJson());
    g.close();

    this->close();
}
