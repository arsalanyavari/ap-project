#ifndef CLIENTLIST_H
#define CLIENTLIST_H

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"
#include <QDialog>

namespace Ui {
class ClientList;
}

class ClientList : public QDialog
{
    Q_OBJECT

public:
    explicit ClientList(QWidget *parent = nullptr);
    ~ClientList();

    QString unit;

    void on_show_clicked();

private slots:

    void on_exit_clicked();

private:
    Ui::ClientList *ui;

    QJsonArray arr;
    void readFile();

};

#endif // CLIENTLIST_H
