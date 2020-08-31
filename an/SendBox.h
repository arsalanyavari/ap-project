#ifndef SENDBOX_H
#define SENDBOX_H

#include <QDialog>

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

namespace Ui {
class SendBox;
}

class SendBox : public QDialog
{
    Q_OBJECT

private:
    QJsonArray arr;
    void readFile();
    void showCombo(QString unit);
    void sendNewMessage(QString empUsername);

    bool supportCheck;
    bool marketingCheck;
    bool operatorCheck;



public:
    explicit SendBox(QWidget *parent = nullptr);
    ~SendBox();

    QString messageText;
    QString currentEmp;
    void hideBoss();

private slots:
    void on_exit_clicked();

    void on_support_clicked();

    void on_marketing_clicked();

    void on_operator_2_clicked();

    void on_boss_clicked();

    void on_select_clicked();

private:
    Ui::SendBox *ui;
};

#endif // SENDBOX_H
