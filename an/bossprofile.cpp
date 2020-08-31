#include <QPixmap>
#include <QFileDialog>
#include "bossprofile.h"
#include "ui_bossprofile.h"
#include "warning.h"

bossprofile::bossprofile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bossprofile)
{
    ui->setupUi(this);
}

bossprofile::~bossprofile()
{
    delete ui;
}

void bossprofile::setValue()
{
    QString path = "Files/Boss/modir.json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();


    ui->name_input->setText(o["modir"].toObject()["human"].toObject()["firstName"].toString());
    ui->family_input->setText(o["modir"].toObject()["human"].toObject()["lastName"].toString());
    ui->ID_input->setText(o["modir"].toObject()["human"].toObject()["id"].toString());
    ui->Tell_number_input->setText(o["modir"].toObject()["human"].toObject()["pNumber"].toString());
    ui->Tell_number2_input->setText(o["modir"].toObject()["human"].toObject()["lNumber"].toString());
    ui->Uname->setText(o["modir"].toObject()["boss"].toObject()["username"].toString());

    QPixmap pm(o["modir"].toObject()["boss"].toObject()["imageUrl"].toString());
    ui->photo->setPixmap(pm);
    ui->photo->setScaledContents(true);
    bc.setImageUrl(o["modir"].toObject()["boss"].toObject()["imageUrl"].toString());



    this->currentPass = o["modir"].toObject()["boss"].toObject()["password"].toString();
    this->bc.setPassword(this->currentPass);


    f.close();
}


void bossprofile::set_New_Pass(QString newPass)
{
    this->bc.setPassword(newPass);
}

void bossprofile::on_pic_change_clicked()
{
    QString s1 =
    QFileDialog::getOpenFileName(this, "Open a file", "directoryToOpen",
    "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)");

    this->bc.setImageUrl(s1);

    QPixmap pm(s1);
    ui->photo->setPixmap(pm);
    ui->photo->setScaledContents(true);


}

void bossprofile::on_Chenge_pass_clicked()
{
    ChangePassword cp(this);
    cp.setOldPass(this->bc.getPassword());


    QObject::connect(&cp,&ChangePassword::sendNewPassToEmp,this,&bossprofile::set_New_Pass);


    cp.exec();

    return;
}

void bossprofile::on_save_clicked()
{

    bc.setUsername(ui->Uname->text());
    bc.setId(ui->ID_input->text());
    bc.setPNumber(ui->Tell_number_input->text());
    bc.setLNumber(ui->Tell_number2_input->text());
    bc.setFirstName(ui->name_input->text());
    bc.setLastName(ui->family_input->text());




    QString Path = "Files/Boss/modir.json";
    QFile g(Path);


    g.open(QIODevice::WriteOnly);

    QJsonObject O , p , q , r;
    p["imageUrl"] = bc.getimageUrl();
    p["password"] = bc.getPassword();
    p["username"] = bc.getUsername();
    O["boss"] = p;

    q["firstName"]= bc.getFirstName();
    q["id"] = bc.getId();
    q["lNumber"] = bc.getLNumber();
    q["lastName"] = bc.getLastName();
    q["pNumber"] = bc.getPNumber();

    O["human"] = q;
    r["modir"] = O;

    QJsonDocument e(r);
    g.write(e.toJson());

    g.close();

    this->close();
}

void bossprofile::on_Exit_clicked()
{
    this->close();
}
