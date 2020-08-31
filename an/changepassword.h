#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = nullptr);
    ~ChangePassword();

    void setOldPass(QString oldPass);

signals:
    void sendNewPassToEmp(QString newPass);

private slots:
    void on_saveButton_clicked();

private:
    Ui::ChangePassword *ui;
    QString oldPass;
    QString newPass;
};

#endif // CHANGEPASSWORD_H
