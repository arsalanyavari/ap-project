#ifndef BOSS_H
#define BOSS_H

#include <QDialog>

#include <QString>

namespace Ui {
class boss;
}

class boss : public QDialog
{
    Q_OBJECT

public:
    explicit boss(QWidget *parent = nullptr);
    ~boss();

    void showNewMessage();
    void showActivedClients();


private slots:
    void on_see_prof_6_clicked();

    void on_see_calls_3_clicked();

    void on_see_emp_3_clicked();

    void on_Add_emp_3_clicked();

    void on_Inbox_clicked();

    void sending_message(QString message);



    void on_Del_emp_3_clicked();

    void on_see_prof_5_clicked();

    void on_logout_clicked();

private:
    Ui::boss *ui;
};

#endif // BOSS_H
