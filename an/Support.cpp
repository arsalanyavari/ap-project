#include <QMessageBox>
#include <QDateTime>
#include "Support.h"
#include "ui_Support.h"
#include "Profile.h"
#include "EditClient.h"
#include "ClientList.h"
#include "SureWarning.h"
#include "mainwindow.h"
#include "SendBox.h"
#include "NewMessages.h"
#include "MessageInbox.h"
#include "AddSuggestions.h"
#include "SuggestionsList.h"
#include "AddWrong.h"
#include "WrongList.h"

Support::Support(QWidget *parent) :
    QDialog(parent),
    Employee(),
    ui(new Ui::Support)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this,SLOT(clocksetter()));
    timer->start(1000);

}

Support::~Support()
{
    delete ui;
}

void Support::showNewMessage()
{
    QString path = "Files/Messages/" + this->username + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    QJsonArray arr;

    for(int i = 0 ; i < o[this->username].toArray().size() ; i+=4){
        if((o[this->username].toArray())[i+1].toString() == "u")
        {
            arr.append((o[this->username].toArray())[i].toString());
            arr.append((o[this->username].toArray())[i+1].toString());
            arr.append((o[this->username].toArray())[i+2].toString());
            arr.append((o[this->username].toArray())[i+3].toString());
        }
    }

    if(arr.size())
    {
        for(int i=0; i < arr.size(); i+=4)
        {
            NewMessages *n = new NewMessages(this);
            n->setWindowTitle("پیام جدید");
            n->setValue(arr, i);
            n->currentEmp = this->username;

            n->exec();

        }
    }


    f.close();
}

void Support::updateEmpValues(Employee emp)
{
    this->setFirstName(emp.getFirstName());
    this->setLastName(emp.getLastName());
    this->setId(emp.getId());
    this->setPNumber(emp.getPNumber());
    this->setLNumber(emp.getLNumber());
    this->setAddress(emp.getAddress());

    this->setUsername(emp.getUsername());
    this->setPassword(emp.getPassword());
    this->setUnit(emp.getUnit());
    this->setFixed(emp.getFixed());
    this->setPercent_s(emp.getPercent_s());
    this->setPercent_d(emp.getPercent_d());
    this->setSalary(emp.getSalary());
    this->setNOClient(emp.getNOClient());
    this->setNOVacations(emp.getNOVacations());
    this->setVariable(emp.getVariable());
    this->setImageUrl(emp.getimageUrl());
}

void Support::on_see_prof_clicked()
{
    Profile *dial = new Profile(this);
    dial->setWindowTitle("پروفایل");
    dial->setValue(this);
    QObject::connect(dial,&Profile::sendUpdatedValuseToOperator,this,&Support::updateEmpValues);


    dial->exec();
}

void Support::on_Del_clt_clicked()
{
    EditClient *EC = new EditClient(this);
    EC->cl.setemployeeUsername(this->getUsername());
    EC->unit = "ساپورت";
    EC->setWindowTitle("ویرایش اطلاعات مشتری");


    EC->exec();
}

void Support::on_see_clt_clicked()
{
    ClientList *LC = new ClientList(this);
    LC->unit = "ساپورت";
    LC->setWindowTitle("لیست مشتریان");
    LC->on_show_clicked();

    LC->exec();
}

void Support::on_logout_clicked()
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

void Support::on_see_prof_2_clicked()
{
    SendBox *s = new SendBox(this);
    s->setWindowTitle("ارسال پیام");
    s->messageText = this->ui->messageText->toPlainText();
    s->currentEmp = this->username;
    s->exec();
}



void Support::on_Inbox_clicked()
{
    MessageInbox *in = new MessageInbox(this);
    in->setWindowTitle("صندوق پیام ها");
    in->showMessage(this->username);

    in->exec();
}

void Support::on_Add_aponion_clicked()
{
    AddSuggestions *s = new AddSuggestions(this);
    s->setWindowTitle("افزودن پیشنهادات و انتقادات");
    s->setCombo();
    s->currentEmp = this->username;

    s->exec();
}

void Support::clocksetter()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->time->setText(time_text);



}

void Support::on_Add_aponion_2_clicked()
{
    SuggestionsList *SL = new SuggestionsList(this);
    SL->setWindowTitle("لیست پیشنهادات و انتقادات");
    SL->setValues();

    SL->exec();
}


void Support::showActivedClients()
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



        if(o["contractType"].toString() == "ساپورت")
        {
            if(o["status"].toBool() == true)
            {
                int cnt;
                ui->activeClientTable->insertRow(ui->activeClientTable->rowCount());
                cnt = ui->activeClientTable->rowCount() - 1;

                ui->activeClientTable->setItem(cnt, 0, new QTableWidgetItem(o["companyName"].toString()));
                ui->activeClientTable->setItem(cnt, 1, new QTableWidgetItem(o["bossName"].toString()));
                ui->activeClientTable->setItem(cnt, 2, new QTableWidgetItem(o["companyPhoneNumber"].toString()));
                ui->activeClientTable->setItem(cnt, 3, new QTableWidgetItem(o["stateName"].toString()));
                ui->activeClientTable->setItem(cnt, 4, new QTableWidgetItem("درحال پیگیری"));
            }

        }




    }

    //setValue()
}

void Support::on_addWrong_clicked()
{
    AddWrong *w = new AddWrong(this);

    w->setWindowTitle("افزودن مشکل گزارش شده");
    w->setCombo();
    w->currentEmp = this->username;

    w->exec();
}

void Support::on_wrongList_clicked()
{
    WrongList *WL = new WrongList(this);
    WL->setWindowTitle("لیست مشکلات گزارش شده");
    WL->setValues();

    WL->exec();
}
