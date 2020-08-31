#ifndef MESSAGEINBOX_H
#define MESSAGEINBOX_H

#include <QDialog>

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

namespace Ui {
class MessageInbox;
}

class MessageInbox : public QDialog
{
    Q_OBJECT

public:
    explicit MessageInbox(QWidget *parent = nullptr);
    ~MessageInbox();

    void showMessage(QString currentEmp);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MessageInbox *ui;
};

#endif // MESSAGEINBOX_H
