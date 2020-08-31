#include <QMessageBox>
#include <QString>
#include "send_box.h"
#include "ui_send_box.h"


send_box::send_box(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::send_box)
{
    ui->setupUi(this);
}

send_box::~send_box()
{
    delete ui;
}

void send_box::on_select_clicked()
{
    if(!ui->operator_2->isChecked() && !ui->poshtibani->isChecked() && !ui->marketing->isChecked())
    {
     QMessageBox::warning(this, "اخطار", "هیچ آیتمی انتخاب نشده است!");
    }

    else {

    QString m ="";
    if(ui->operator_2->isChecked())
        m = "Operator";
    if(ui->poshtibani->isChecked())
        m = m + " " + "Poshtibani";
    if(ui->marketing->isChecked())
        m = m + " " + "Marketing";
    emit send_message(m);
    }

    this->close();
}

void send_box::on_exit_clicked()
{
    this->close();
}
