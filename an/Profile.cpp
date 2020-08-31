#include <QPixmap>
#include <QFileDialog>
#include "Profile.h"
#include "Employee.h"
#include "ui_Profile.h"
#include "warning.h"

Profile::Profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
}

Profile::~Profile()
{
    delete ui;
}

void Profile::applyChanges()
{
    emp.setFirstName(ui->nameLable1->text());
    emp.setLastName(ui->nameLable2->text());
    emp.setId(ui->idLable->text());
    emp.setPNumber(ui->pnumberLable->text());
    emp.setLNumber(ui->lnumberLable->text());
    emp.setAddress(ui->addressLable->text());
    emp.setUsername(ui->usernameLable->text());

    emp.setUnit(ui->unitLable->text());
    emp.setFixed(ui->fixedLable->text());
    emp.setPercent_s(ui->percentLable->text());
    emp.setPercent_d(ui->percentLable->text().toDouble());
    emp.setSalary(ui->salaryLable->text());
    emp.setNOClient(ui->noClient->text());
    emp.setNOVacations(ui->novacationLable->text());
    emp.setVariable(ui->variableLable->text());

    return;

}
void Profile::conversionFromPtr(Employee* emp)
{
    this->emp.setFirstName(emp->getFirstName());
    this->emp.setLastName(emp->getLastName());
    this->emp.setId(emp->getId());
    this->emp.setPNumber(emp->getPNumber());
    this->emp.setLNumber(emp->getLNumber());
    this->emp.setAddress(emp->getAddress());

    this->emp.setUsername(emp->getUsername());
    this->emp.setPassword(emp->getPassword());
    this->emp.setUnit(emp->getUnit());
    this->emp.setFixed(emp->getFixed());
    this->emp.setPercent_s(emp->getPercent_s());
    this->emp.setPercent_d(emp->getPercent_d());
    this->emp.setSalary(emp->getSalary());
    this->emp.setNOClient(emp->getNOClient());
    this->emp.setNOVacations(emp->getNOVacations());
    this->emp.setVariable(emp->getVariable());
    this->emp.setImageUrl(emp->getimageUrl());

    return;
}

void Profile::setValue(Employee *x)
{
    conversionFromPtr(x);

    ui->nameLable1->setText(x->getFirstName());
    ui->nameLable2->setText(x->getLastName());
    ui->idLable->setText(x->getId());
    ui->pnumberLable->setText(x->getPNumber());
    ui->lnumberLable->setText(x->getLNumber());
    ui->addressLable->setText(x->getAddress());


    ui->unitLable->setText(x->getUnit());
    ui->fixedLable->setText(x->getFixed());
    ui->percentLable->setText(x->getPercent_s());
    ui->salaryLable->setText(x->getSalary());
    ui->noClient->setText(x->getNOClient());
    ui->novacationLable->setText(x->getNOVacations());
    ui->variableLable->setText(x->getVariable());

    ui->usernameLable->setText(x->getUsername());


    QPixmap pm(x->getimageUrl());
    ui->photoLable->setPixmap(pm);
    ui->photoLable->setScaledContents(true);




    return;



}


void Profile::setNewPass(QString newPass)
{
    this->emp.setPassword(newPass);
}


void Profile::on_pic_change_clicked()
{
    QString s1 =
    QFileDialog::getOpenFileName(this, "Open a file", "directoryToOpen",
    "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)");

    this->emp.setImageUrl(s1);

    QPixmap pm(s1);
    ui->photoLable->setPixmap(pm);
    ui->photoLable->setScaledContents(true);

     return;

}

void Profile::on_Chenge_pass_clicked()
{

    ChangePassword *cp = new ChangePassword(this);
    cp->setOldPass(this->emp.getPassword());


        QObject::connect(cp,&ChangePassword::sendNewPassToEmp,this,&Profile::setNewPass);


     cp->exec();

    return;
}

void Profile::on_save_clicked()
{
    this->applyChanges();
    emit sendUpdatedValuseToOperator(emp);
    emp.updateJsonValues();
    this->close();

    return;
}
