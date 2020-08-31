#ifndef BOSSPROFILE_H
#define BOSSPROFILE_H

#include <QDialog>
#include "bossclass.h"
#include "changepassword.h"

namespace Ui {
class bossprofile;
}

class bossprofile : public QDialog
{
    Q_OBJECT

public:
    explicit bossprofile(QWidget *parent = nullptr);
    ~bossprofile();

    void setValue();
    QString currentPass;

public slots:
    void set_New_Pass(QString newPass);

private slots:
    void on_pic_change_clicked();

    void on_Chenge_pass_clicked();

    void on_save_clicked();

    void on_Exit_clicked();

private:
    Ui::bossprofile *ui;


    bossclass bc;

};

#endif // BOSSPROFILE_H
