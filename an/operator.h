#ifndef OPERATOR_H
#define OPERATOR_H

#include <QTimer>
#include <QDialog>
#include "Employee.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Operator; }
QT_END_NAMESPACE

class Operator : public QDialog , public Employee
{
    Q_OBJECT

public:
    Operator(QWidget *parent = nullptr);
    ~Operator();

    void showNewMessage();
    void showActivedClients();

private slots:
    void on_see_prof_clicked();

    void on_Add_clt_clicked();

    void on_Del_clt_clicked();

    void on_see_clt_clicked();

    void on_logout_clicked();

    void on_see_prof_2_clicked();

    void on_Inbox_clicked();

public slots:
    void updateEmpValues(Employee emp);

    void clocksetter();

private:
    Ui::Operator *ui;
    QTimer *timer;
};
#endif // OPERATOR_H
