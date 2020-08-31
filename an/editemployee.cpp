#include <QMessageBox>
#include "editemployee.h"
#include "ui_editemployee.h"
#include "Employee.h"
#include "SureWarning.h"


editemployee::editemployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editemployee)
{
    ui->setupUi(this);
}

editemployee::~editemployee()
{
    delete ui;
}

void editemployee::on_pushButton_2_clicked()
{
    ch = false;
    QFile g("Files/Employees/EmployeeUsername.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();
    int i = 0;
    for(; i < o["employee"].toArray().size() ; i++){
        arr.append((o["employee"].toArray())[i].toString());
    }
    g.close();
    i=0;

    for (; i < arr.size(); i++) {
        QString path = "Files/Employees/" + arr[i].toString() + ".json";
        QFile f(path);

        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        f.close();

        if(o[arr[i].toString()].toObject()["human"].toObject()["firstName"].toString() == ui->employeeName_3->text() && o[arr[i].toString()].toObject()["human"].toObject()["lastName"].toString() == ui->employeeFamily->text())
        {
            ui->salary_2->setText(o[arr[i].toString()].toObject()["employee"].toObject()["salary"].toString());
            ui->salary_2->setEnabled(true);
            ui->percent_2->setText(o[arr[i].toString()].toObject()["employee"].toObject()["percent_s"].toString());
            ui->percent_2->setEnabled(true);
            if(o[arr[i].toString()].toObject()["employee"].toObject()["unit"].toString() == "کارمند فروش")
               ui->employeeType_2->setCurrentIndex(1);
            else if(o[arr[i].toString()].toObject()["employee"].toObject()["unit"].toString() == "کارمند پشتیبانی")
                ui->employeeType_2->setCurrentIndex(2);
            ui->employeeType_2->setEnabled(true);
            ui->delete_3->setEnabled(true);
            ui->save_2->setEnabled(true);
            ui->employeeName_3->setEnabled(false);
            ui->employeeFamily->setEnabled(false);
            u_name = o[arr[i].toString()].toObject()["employee"].toObject()["username"].toString();
            ch = false;
            break;
        }
        else {
            ch = true;
        }
    }

    if(i==arr.size() &&  ch) {
        QMessageBox::warning(this,"اخطار", "نام یا نام خانوادگی صحیح نمیباشد");
    }



}

void editemployee::on_save_2_clicked()
{
    QString path = "Files/Employees/" + u_name + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();
    f.close();


    Employee *emp = new Employee();
    emp->setFirstName(o[u_name].toObject()["human"].toObject()["firstName"].toString());
    emp->setLastName(o[u_name].toObject()["human"].toObject()["lastName"].toString());
    emp->setUnit(ui->employeeType_2->currentText());
    emp->setId(o[u_name].toObject()["human"].toObject()["id"].toString());
    emp->setLNumber(o[u_name].toObject()["human"].toObject()["lNumber"].toString());
    emp->setPNumber(o[u_name].toObject()["human"].toObject()["pNumber"].toString());
    emp->setSalary(ui->salary_2->text());
    emp->setPercent_d(ui->percent_2->text().toDouble());
    emp->setPercent_s(ui->percent_2->text());
    emp->setAddress(o[u_name].toObject()["human"].toObject()["address"].toString());
    emp->setPassword(o[u_name].toObject()["employee"].toObject()["password"].toString());
    emp->setFixed(o[u_name].toObject()["employee"].toObject()["fixed"].toString());
    emp->setImageUrl(o[u_name].toObject()["employee"].toObject()["imageUrl"].toString());
    emp->setVariable(o[u_name].toObject()["employee"].toObject()["variable"].toString());
    emp->setNOClient(o[u_name].toObject()["employee"].toObject()["numberofClient"].toString());
    emp->setNOVacations(o[u_name].toObject()["employee"].toObject()["numberofVacations"].toString());



    QString Path = "Files/Employees/" + u_name + ".json";
    QFile g(Path);


    g.open(QIODevice::WriteOnly);

    QJsonObject O , p , q , r;
    p["fixed"] = emp->getSalary();
    p["imageUrl"] = emp->getimageUrl();
    p["numberofClient"] = emp->getNOClient();
    p["numberofVacations"] = emp->getNOVacations();
    p["password"] = emp->getId();
    p["percent_d"] = emp->getPercent_d();
    p["percent_s"] = emp->getPercent_s();
    p["salary"] = emp->getSalary();
    p["unit"] = emp->getUnit();
    p["username"] = u_name;
    p["variable"] = emp->getVariable();
    O["employee"] = p;

    q["address"] = emp->getAddress();
    q["firstName"]= emp->getFirstName();
    q["id"] = emp->getId();
    q["lNumber"] = emp->getLNumber();
    q["lastName"] = emp->getLastName();
    q["pNumber"] = emp->getPNumber();

    O["human"] = q;
    r[u_name] = O;

    QJsonDocument e(r);
    g.write(e.toJson());

    g.close();



    this->close();

}

void editemployee::on_delete_3_clicked()
{
    SureWarning *sw = new SureWarning(this);
    sw->setMessage("مطمئنید؟");
    sw->exec();

    if(sw->test)
    {
        QFile g("Files/Employees/EmployeeUsername.json");
        g.open(QIODevice::ReadOnly);
        QByteArray r = g.readAll();
        QJsonDocument t = QJsonDocument::fromJson(r);
        QJsonObject o = t.object();

        for(int i = 0 ; i < o["employee"].toArray().size() ; i++){
            if((o["employee"].toArray())[i].toString()==u_name)
                continue;
            arr_2.append((o["employee"].toArray())[i].toString());
        }
        g.close();

        QFile f("Files/Employees/EmployeeUsername.json");
        f.open(QIODevice::WriteOnly);
        QJsonObject obj;
        obj["employee"] = arr_2;
        QJsonDocument d(obj);
        f.write(d.toJson());
        f.close();

        QFile h("Files/Employees/FiredEmployeeUsername.json");
        h.open(QIODevice::ReadOnly);
        QByteArray s = h.readAll();
        QJsonDocument u = QJsonDocument::fromJson(s);
        QJsonObject p = u.object();

        for(int i = 0 ; i < p["employee"].toArray().size() ; i++){
            if((p["employee"].toArray())[i].toString()==u_name)
                continue;
            arr_3.append((p["employee"].toArray())[i].toString());
        }
        arr_3.append(u_name);
        h.close();

        QFile a("Files/Employees/FiredEmployeeUsername.json");
        a.open(QIODevice::WriteOnly);
        QJsonObject Obj;
        Obj["employee"] = arr_3;
        QJsonDocument e(Obj);
        a.write(e.toJson());
        a.close();


    }

    this->close();

}
