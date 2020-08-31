#ifndef EDITCLIENT_H
#define EDITCLIENT_H

#include <QDialog>
#include "Client.h"

namespace Ui {
class EditClient;
}

class EditClient : public QDialog
{
    Q_OBJECT

public:
    explicit EditClient(QWidget *parent = nullptr);
    ~EditClient();

    Client cl;
    QString pastCompanyName;
    QString unit;

    void applyChanges();

private slots:
    void on_pushButton_clicked();

    void on_save_clicked();

    void on_delete_2_clicked();

    void on_contractType_activated(int index);

private:
    Ui::EditClient *ui;

    void updateSuggestions_Projects();
};

#endif // EDITCLIENT_H
