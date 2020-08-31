#ifndef CLIENTLIST_H
#define CLIENTLIST_H

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"
#include <QDialog>

namespace Ui {
class client_list;
}

class client_list : public QDialog
{
    Q_OBJECT

public:
    explicit client_list(QWidget *parent = nullptr);
    ~client_list();

public slots:
    void on_show_3_clicked();
private slots:

    void on_exit_3_clicked();

private:
    Ui::client_list *ui;

    QJsonArray arr;
    void readFile();

};

#endif // CLIENTLIST_H
