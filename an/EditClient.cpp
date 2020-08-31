#include "EditClient.h"
#include "ui_EditClient.h"
#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"
#include "warning.h"
#include "SureWarning.h"

EditClient::EditClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditClient)
{
    ui->setupUi(this);
}

EditClient::~EditClient()
{
    delete ui;
}

void EditClient::on_pushButton_clicked()
{
    QString path = "Files/Clients/" + ui->companyName->text() + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();

    if(f.exists())
    {
        if(o["contractType"].toString() == this->unit || this->unit == "اپراتور")
        {
            this->pastCompanyName = o["companyName"].toString();

            ui->companyPN->setEnabled(1);
            ui->companyType->setEnabled(1);
            ui->companyPN->setEnabled(1);
            ui->companyAddress->setEnabled(1);
            ui->bossName->setEnabled(1);
            ui->bossEmail->setEnabled(1);
            ui->bossPN->setEnabled(1);
            ui->stateName->setEnabled(1);
            ui->cityName->setEnabled(1);
            ui->contractType->setEnabled(1);
            ui->save->setEnabled(1);
            ui->delete_2->setEnabled(1);
            ui->status->setEnabled(1);
            ui->empUsername->setEnabled(1);

            ui->companyName->setText(o["companyName"].toString());
            ui->companyPN->setText(o["companyPhoneNumber"].toString());
            ui->companyType->setCurrentText(o["companyType"].toString());
            ui->companyAddress->setText(o["companyAddress"].toString());
            ui->bossName->setText(o["bossName"].toString());
            ui->bossEmail->setText(o["bossEmail"].toString());
            ui->bossPN->setText(o["bossPhoneNumber"].toString());
            ui->stateName->setCurrentText(o["stateName"].toString());
            ui->cityName->setText(o["cityName"].toString());
            ui->contractType->setCurrentText(o["contractType"].toString());
            if(o["status"].toBool()){
                ui->status->setCurrentIndex(0);
            }
            else{
                ui->status->setCurrentIndex(1);
            }
            ui->empUsername->addItem(o["employeeUsername"].toString());
        }
        else{
            Warning *wn = new Warning(this);
            wn->setMessage("ّبرای شما شرکتی با این نام وجود ندارد");

            wn->exec();
        }

    }
    else
    {
        Warning *wn = new Warning(this);
        wn->setMessage("شرکتی با این نام وجود ندارد");

        wn->exec();
    }
    f.close();

}

void EditClient::applyChanges()
{
    cl.setCompanyName(ui->companyName->text());
    cl.setCompanyType(ui->companyType->currentText());
    cl.setCompanyPhoneNumber(ui->companyPN->text());
    cl.setCompanyAddress(ui->companyAddress->text());
    cl.setBossName(ui->bossName->text());
    cl.setBossEmail(ui->bossEmail->text());
    cl.setBossPhoneNumber(ui->bossPN->text());
    cl.setStateName(ui->stateName->currentText());
    cl.setCityName(ui->cityName->text());
    cl.setContractType(ui->contractType->currentText());
    cl.setContractType(ui->contractType->currentText());
    if(ui->status->currentIndex() == 0){
        cl.setStatus(true);
    }
    else{
        cl.setStatus(false);
    }
    cl.setemployeeUsername(ui->empUsername->currentText());

}



void EditClient::on_save_clicked()
{
    QFile g("Files/Clients/companiesName.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();


    int tag = -1;

    for(int i = 0 ; i < o["companiesName"].toArray().size() ; i++)
    {
        if((o["companiesName"].toArray())[i].toString() == ui->companyName->text())
        {
            tag = i;
        }
    }
    g.close();

    if(tag > -1)
    {
        if(pastCompanyName != this->ui->companyName->text()){
            Warning *warn = new Warning(this);
            warn->setMessage("شرکتی با این نام موجود است");
            warn->exec();
        }
        else if(pastCompanyName == this->ui->companyName->text()){
            this->cl.setPastCompanyName(this->pastCompanyName);
            this->applyChanges();
            this->cl.updateJsonValues();

            this->close();
        }
    }
    else if(tag == -1)
    {
        this->cl.setPastCompanyName(this->pastCompanyName);
        this->applyChanges();
        this->cl.updateJsonValues();

        QString path = "Files/Clients/" + pastCompanyName + ".json";
        QFile::remove(path);

        this->close();
        updateSuggestions_Projects();
    }


}

void EditClient::on_delete_2_clicked()
{
    SureWarning *sw = new SureWarning(this);
    sw->setMessage("مطمئنید؟");
    sw->exec();

    if(sw->test == 1)
    {
        QString path = "Files/Clients/" + ui->companyName->text() + ".json";
        QFile::remove(path);



        QFile g("Files/Clients/companiesName.json");
        g.open(QIODevice::ReadOnly);
        QByteArray r = g.readAll();
        QJsonDocument t = QJsonDocument::fromJson(r);
        QJsonObject o = t.object();



        QJsonArray arr;
        for(int i = 0 ; i < o["companiesName"].toArray().size() ; i++)
        {
            if((o["companiesName"].toArray())[i].toString() == ui->companyName->text())
            {
                continue;
            }
            arr.append((o["companiesName"].toArray())[i].toString());
        }
        g.close();



        QFile f("Files/Clients/companiesName.json");
        f.open(QIODevice::WriteOnly);

        QJsonObject obj;
        obj["companiesName"] = arr;
        QJsonDocument d(obj);
        f.write(d.toJson());
        f.close();

        this->close();
    }

}

void EditClient::on_contractType_activated(int index)
{
    ui->empUsername->clear();


    QFile g("Files/Employees/EmployeeUsername.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();

    QJsonArray arr;
    for(int i = 0 ; i < o["employee"].toArray().size() ; i++)
    {
        arr.append((o["employee"].toArray())[i].toString());
    }
    g.close();


    if(index == 0)
    {
        for(int i=0; i<arr.size() ;i++)
        {
            QString path = "Files/Employees/" + arr[i].toString() +".json";
            QFile g(path);
            g.open(QIODevice::ReadOnly);
            QByteArray r = g.readAll();
            QJsonDocument t = QJsonDocument::fromJson(r);
            QJsonObject o = t.object();

            if(((o[arr[i].toString()].toObject())["employee"].toObject())["unit"].toString() == "کارمند فروش"){
                ui->empUsername->addItem(arr[i].toString());
            }
        }



    }
    else if(index == 1)
    {
        for(int i=0; i<arr.size() ;i++)
        {
            QString path = "Files/Employees/" + arr[i].toString() +".json";
            QFile g(path);
            g.open(QIODevice::ReadOnly);
            QByteArray r = g.readAll();
            QJsonDocument t = QJsonDocument::fromJson(r);
            QJsonObject o = t.object();

            if(((o[arr[i].toString()].toObject())["employee"].toObject())["unit"].toString() == "کارمند پشتیبانی"){
                ui->empUsername->addItem(arr[i].toString());
            }
         }
    }
}

void EditClient::updateSuggestions_Projects()
{
    //Suggestions
    QString path = "Files/Suggestions/" + this->pastCompanyName + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    QJsonArray a;
    for(int i = 0 ; i < o[this->pastCompanyName ].toArray().size() ; i++){
        a.append((o[this->pastCompanyName ].toArray())[i].toString());
    }
    f.close();
    QFile::remove(path);


    QString path1 = "Files/Suggestions/" + ui->companyName->text() + ".json";
    QFile g(path1);
    g.open(QIODevice::WriteOnly);

    QJsonObject obj;
    obj[ui->companyName->text()] = a;
    QJsonDocument h(obj);
    g.write(h.toJson());
    g.close();



    //Projects
    QString path5 = "Files/Projects/" + this->pastCompanyName + ".json";
    QFile t(path5);

    t.open(QIODevice::ReadOnly);
    QByteArray z = t.readAll();
    QJsonDocument x = QJsonDocument::fromJson(z);
    QJsonObject object = x.object();


    QJsonArray array;
    for(int i = 0 ; i < object[this->pastCompanyName ].toArray().size() ; i++){
        array.append((object[this->pastCompanyName ].toArray())[i].toString());
    }
    t.close();
    QFile::remove(path5);


    QString path6 = "Files/Projects/" + ui->companyName->text() + ".json";
    QFile y(path6);
    y.open(QIODevice::WriteOnly);

    QJsonObject object2;
    object2[ui->companyName->text()] = array;
    QJsonDocument l(object2);
    y.write(l.toJson());
    y.close();

    this->close();




    //Wrongs
    QString path10 = "Files/Wrongs/" + this->pastCompanyName + ".json";
    QFile file(path10);

    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    QJsonDocument jd = QJsonDocument::fromJson(ba);
    QJsonObject object10 = jd.object();


    QJsonArray array10;
    for(int i = 0 ; i < object10[this->pastCompanyName ].toArray().size() ; i++){
        array10.append((object10[this->pastCompanyName ].toArray())[i].toString());
    }
    file.close();
    QFile::remove(path10);


    QString path11 = "Files/Wrongs/" + ui->companyName->text() + ".json";
    QFile file2(path11);
    file2.open(QIODevice::WriteOnly);

    QJsonObject object11;
    object11[ui->companyName->text()] = array10;
    QJsonDocument doc(object11);
    file2.write(doc.toJson());
    file2.close();





    this->close();
}
