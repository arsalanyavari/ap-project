#ifndef SUPPORT_H
#define SUPPORT_H

#include <QTimer>
#include <QDialog>
#include "Employee.h"

namespace Ui {
class Support;
}

class Support : public QDialog ,public Employee
{
    Q_OBJECT

public:
    explicit Support(QWidget *parent = nullptr);
    ~Support();

    void showNewMessage();
    void showActivedClients();

private slots:
    void on_see_prof_clicked();

    void on_Del_clt_clicked();

    void on_see_clt_clicked();

    void on_logout_clicked();

    void on_see_prof_2_clicked();

    void on_Inbox_clicked();

    void on_Add_aponion_clicked();

    void on_Add_aponion_2_clicked();

    void on_addWrong_clicked();

    void on_wrongList_clicked();

public slots:
    void updateEmpValues(Employee emp);

    void clocksetter();

private:
    Ui::Support *ui;

    QTimer *timer;
};

#endif // SUPPORT_H
