#ifndef MARKETING_H
#define MARKETING_H

#include <QDialog>
#include <QTimer>
#include "Employee.h"

namespace Ui {
class Marketing;
}

class Marketing : public QDialog ,public Employee
{
    Q_OBJECT

public:
    explicit Marketing(QWidget *parent = nullptr);
    ~Marketing();

    void showNewMessage();
    void showActivedClients();


private slots:
    void on_see_prof_clicked();

    void on_Del_clt_clicked();

    void on_see_clt_clicked();

    void on_logout_clicked();

    void on_see_prof_2_clicked();

    void on_Inbox_clicked();

    void on_AddProject_clicked();

    void on_ProjectList_clicked();

public slots:
    void updateEmpValues(Employee emp);

    void clocksetter();

private:
    Ui::Marketing *ui;
    QTimer *timer;
};

#endif // MARKETING_H
