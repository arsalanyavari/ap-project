#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>
#include "Employee.h"
#include "changepassword.h"

namespace Ui {
class Profile;
}

class Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    ~Profile();
    Employee emp;

    void setValue(Employee* );
    void applyChanges();
    void conversionFromPtr(Employee* );

signals:
    void sendUpdatedValuseToOperator(Employee emp);


public slots:
    void setNewPass(QString newPass);


private slots:
    void on_pic_change_clicked();

    void on_Chenge_pass_clicked();

    void on_save_clicked();

private:
    Ui::Profile *ui;
};

#endif // PROFILE_H
