#include <QDebug>
#include <QDateTime>
#include <QString>
#include "boss.h"
#include "ui_boss.h"
#include "QFile"
#include "QJsonDocument"
#include "QJsonObject"
#include "add_employee.h"
#include "employee_list.h"
#include "send_box.h"
#include "client_list.h"
#include "editemployee.h"
#include "bossprofile.h"
#include "SureWarning.h"
#include "mainwindow.h"
#include "SendBox.h"
#include "NewMessages.h"
#include "MessageInbox.h"




boss::boss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::boss)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this,SLOT(clocksetter()));
    timer->start(1000);
}

boss::~boss()
{
    delete ui;
}

void boss::on_Add_emp_3_clicked()
{
    add_employee * emp = new add_employee();
    emp->show();

}

void boss::sending_message(QString message)
{

    // openning message the rewrite it
    QFile f(":/files/message.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b= f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject msg = d.object();
    f.close();
    
    
    
    
    qDebug() << message;
}

void boss::clocksetter()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->time->setText(time_text);



}

void boss::on_see_emp_3_clicked()
{
    employee_list *emp_l = new employee_list(this);
    emp_l->show();
}


void boss::on_see_calls_3_clicked()
{
    client_list * cli = new client_list(this);
    cli->on_show_3_clicked();

    cli->show();
}


void boss::on_see_prof_6_clicked()
{
    SendBox *s = new SendBox(this);
    s->setWindowTitle("ارسال پیام");
    s->messageText = this->ui->messageText->toPlainText();
    s->currentEmp = "مدیریت";
    s->hideBoss();
    s->exec();
}

void boss::on_Del_emp_3_clicked()
{
    editemployee * edit = new editemployee(this);

    edit->show();
}

void boss::on_see_prof_5_clicked()
{
    bossprofile *bpp = new bossprofile(this);
    bpp->setValue();

    bpp->show();
}

void boss::on_logout_clicked()
{
    SureWarning *sw = new SureWarning(this);
    sw->setMessage("مطمئنید؟");
    sw->exec();
    if(sw->test == 1)
    {
        this->close();
        MainWindow* w = new MainWindow(this);
        w->show();
    }
}


void boss::showNewMessage()
{
    QString path = "Files/Messages/Boss.json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    QJsonArray arr;

    for(int i = 0 ; i < o["Boss"].toArray().size() ; i+=4){
        if((o["Boss"].toArray())[i+1].toString() == "u")
        {
            arr.append((o["Boss"].toArray())[i].toString());
            arr.append((o["Boss"].toArray())[i+1].toString());
            arr.append((o["Boss"].toArray())[i+2].toString());
            arr.append((o["Boss"].toArray())[i+3].toString());
        }
    }

    if(arr.size())
    {
        for(int i=0; i < arr.size(); i+=4)
        {
            NewMessages *n = new NewMessages(this);
            n->setWindowTitle("پیام جدید");
            n->setValue(arr, i);
            n->currentEmp = "Boss";

            n->exec();

        }
    }


    f.close();
}



void boss::showActivedClients()
{
    //readFile()


    QJsonArray arr;

    QFile g("Files/Clients/companiesName.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();

    for(int i = 0 ; i < o["companiesName"].toArray().size() ; i++){
        arr.append((o["companiesName"].toArray())[i].toString());
    }
    g.close();


    //setValue()
    for (int i=0; i < arr.size(); i++) {
        QString path = "Files/Clients/" + arr[i].toString() + ".json";
        QFile f(path);

        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();


            if(o["status"].toBool() == true)
            {
                int cnt;
                ui->activeClientTable->insertRow(ui->activeClientTable->rowCount());
                cnt = ui->activeClientTable->rowCount() - 1;

                ui->activeClientTable->setItem(cnt, 0, new QTableWidgetItem(o["companyName"].toString()));
                ui->activeClientTable->setItem(cnt, 1, new QTableWidgetItem(o["bossName"].toString()));
                ui->activeClientTable->setItem(cnt, 2, new QTableWidgetItem(o["companyPhoneNumber"].toString()));
                ui->activeClientTable->setItem(cnt, 3, new QTableWidgetItem(o["stateName"].toString()));
                ui->activeClientTable->setItem(cnt, 4, new QTableWidgetItem(o["employeeUsername"].toString()));
            }



    }

}

void boss::on_Inbox_clicked()
{
    MessageInbox *in = new MessageInbox(this);
    in->setWindowTitle("صندوق پیام ها");
    in->showMessage("Boss");

    in->exec();
}
