#include "changepassword.h"
#include "ui_changepassword.h"
#include "warning.h"
ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
}

ChangePassword::~ChangePassword()
{
    delete ui;
}
void ChangePassword::setOldPass(QString oldPass)
{
    this->oldPass = oldPass;
    this->newPass = oldPass;
    return;
}

void ChangePassword::on_saveButton_clicked()
{

    if(this->oldPass == this->ui->currentPass->text() &&
            this->ui->newPass_1->text() == this->ui->newPass_2->text() &&
            this->ui->newPass_1->text() != nullptr)
    {
        Warning *wn = new Warning(this);
        wn->setWindowTitle("successful");
        wn->setMessage("تغییرات با موفقیت اعمال شد");
        wn->exec();

        this->newPass = this->ui->newPass_1->text();
        emit sendNewPassToEmp(newPass);

        this->close();
    }
    else if(oldPass == this->ui->currentPass->text() &&
            this->ui->newPass_1->text() != this->ui->newPass_2->text())
    {
        Warning *wn = new Warning(this);
        wn->setWindowTitle("Error");
        wn->setMessage("لطفا دقت کنید!");
        wn->exec();
        this->close();

    }
    else if(oldPass != this->ui->currentPass->text() &&
            this->ui->newPass_1->text() == this->ui->newPass_2->text())
    {
        Warning *wn = new Warning(this);
        wn->setWindowTitle("Error");
        wn->setMessage("لطفا پسورد فعلی را درست وارد کنید");
        wn->exec();
        this->close();

    }
    else if(oldPass != this->ui->currentPass->text() &&
            this->ui->newPass_1->text() != this->ui->newPass_2->text())
    {
        Warning *wn = new Warning(this);
        wn->setWindowTitle("Error");
        wn->setMessage("لطفا پسورد فعلی را درست وارد کنید");
        wn->exec();
        this->close();

    }
    else if(oldPass == this->ui->currentPass->text() &&
            this->ui->newPass_1->text() == this->ui->newPass_2->text() &&
            this->ui->newPass_1->text() == nullptr)
    {
        Warning *wn = new Warning(this);
        wn->setWindowTitle("Error");
        wn->setMessage("فیلد های گذرواژه جدید نمیتواند خالی باشد");
        wn->exec();
        this->close();

    }

    return;
}
