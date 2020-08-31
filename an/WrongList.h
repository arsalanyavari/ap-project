#ifndef WRONGLIST_H
#define WRONGLIST_H

#include <QDialog>

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

namespace Ui {
class WrongList;
}

class WrongList : public QDialog
{
    Q_OBJECT

public:
    explicit WrongList(QWidget *parent = nullptr);
    ~WrongList();

    void setValues();

private slots:
    void on_exit_clicked();

private:
    Ui::WrongList *ui;
};

#endif // WRONGLIST_H
