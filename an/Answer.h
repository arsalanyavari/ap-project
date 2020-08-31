#ifndef ANSWER_H
#define ANSWER_H

#include <QDialog>
#include <QDateTime>
#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"


namespace Ui {
class Answer;
}

class Answer : public QDialog
{
    Q_OBJECT

public:
    explicit Answer(QWidget *parent = nullptr);
    ~Answer();

    QString currentEmp;
    QString geterEmp;

private slots:
    void on_sendButton_clicked();

private:
    Ui::Answer *ui;
};

#endif // ANSWER_H
