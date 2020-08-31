#include "SureWarning.h"
#include "ui_SureWarning.h"

SureWarning::SureWarning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SureWarning)
{
    ui->setupUi(this);
}

SureWarning::~SureWarning()
{
    delete ui;
}

void SureWarning::setMessage(QString message)
{
    this->ui->label->setText(message);
    return;
}

void SureWarning::on_buttonBox_accepted()
{
    test = 1;
    this->close();
}

void SureWarning::on_buttonBox_rejected()
{
    test = 0;
    this->close();
}
