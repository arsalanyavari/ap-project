#include "warning.h"
#include "ui_warning.h"

Warning::Warning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warning)
{
    ui->setupUi(this);
}

Warning::~Warning()
{
    delete ui;
}

void Warning::setMessage(QString txt)
{
    ui->warningText->setText(txt);
}

void Warning::on_pushButton_clicked()
{
    this->close();
}
