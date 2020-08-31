#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>

#include "Client.h"

namespace Ui {
class AddClient;
}

class AddClient : public QDialog
{
    Q_OBJECT

public:
    explicit AddClient(QWidget *parent = nullptr);
    ~AddClient();

    Client cl;
    void applyChanges();


private slots:
    void on_save_clicked();

    void on_contractType_activated(int index);

    void on_empUsername_activated(const QString &arg1);

private:
    Ui::AddClient *ui;

};

#endif // ADDCLIENT_H
