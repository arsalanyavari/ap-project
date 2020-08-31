#ifndef NEWMESSAGES_H
#define NEWMESSAGES_H

#include <QDialog>

namespace Ui {
class NewMessages;
}

class NewMessages : public QDialog
{
    Q_OBJECT

public:
    explicit NewMessages(QWidget *parent = nullptr);
    ~NewMessages();

    void setValue(QJsonArray arr, int i);
    QString currentEmp;

private slots:
    void on_pushButton_2_clicked();

    void on_answer_clicked();

private:
    Ui::NewMessages *ui;

    void seen();
};

#endif // NEWMESSAGES_H
