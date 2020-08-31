#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QJsonDocument"
#include "QJsonObject"

#include <QtDebug>


#include "boss.h"
#include "operator.h"
#include "Support.h"
#include "Marketing.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->warning->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_submit_clicked()
{
    QFile file("Files/Boss/modir.json");
    file.open(QIODevice::ReadOnly);
    QByteArray buffer= file.readAll();
    QJsonDocument duc = QJsonDocument::fromJson(buffer);
    QJsonObject obj = duc.object();


    if(ui->userinput->text() == ((obj["modir"].toObject())["boss"].toObject())["username"].toString())
    {
        if(ui->passinput->text() == ((obj["modir"].toObject())["boss"].toObject())["password"].toString())
        {
            boss *b_page = new boss();
            b_page->show();
            b_page->showActivedClients();
            b_page->showNewMessage();
            this->close();
        }
        else
        {
            ui->warning->setVisible(true);
        }
    }



    else
    {
        ui->warning->setVisible(true);
    }


    QFile g("Files/Employees/EmployeeUsername.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();
    
    
    QJsonArray arr;
    int tag = -1;
    for(int i = 0 ; i < o["employee"].toArray().size() ; i++){
        arr.append((o["employee"].toArray())[i].toString());
        if(ui->userinput->text() == arr[i].toString())
            tag = i;
    }
    g.close(); 
    




    if(tag > -1)
    {
        QString path = "Files/Employees/" + arr[tag].toString() +".json";
        QFile f(path);
        f.open(QIODevice::ReadOnly);
        QByteArray j = f.readAll();
        QJsonDocument u = QJsonDocument::fromJson(j);
        QJsonObject ob = u.object();

        if(ui->passinput->text() == ((ob[arr[tag].toString()].toObject())["employee"].toObject())["password"].toString())
        {
            if(((ob[arr[tag].toString()].toObject())["employee"].toObject())["unit"].toString() == "کارمند اپراتور")
            {
                Operator *o =new Operator();
                o->setEmployee(arr[tag].toString());

                o->show();
                o->showActivedClients();
                o->showNewMessage();
            }
            else if(((ob[arr[tag].toString()].toObject())["employee"].toObject())["unit"].toString() == "کارمند پشتیبانی")
            {
                Support *s =new Support();
                s->setEmployee(arr[tag].toString());

                s->show();
                s->showActivedClients();
                s->showNewMessage();
            }
            else if(((ob[arr[tag].toString()].toObject())["employee"].toObject())["unit"].toString() == "کارمند فروش")
            {
                Marketing *m =new Marketing();
                m->setEmployee(arr[tag].toString());

                m->show();
                m->showActivedClients();
                m->showNewMessage();

            }

            this->close();
        }
        else
        {
            ui->warning->setVisible(true);
        }

        f.close();
    }
    
    else
    {
        ui->warning->setVisible(true);
    }

}
