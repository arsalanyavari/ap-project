#ifndef PROJECTLIST_H
#define PROJECTLIST_H

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

#include <QDialog>

namespace Ui {
class ProjectList;
}

class ProjectList : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectList(QWidget *parent = nullptr);
    ~ProjectList();

    void setValues();


private slots:
    void on_pushButton_clicked();

private:
    Ui::ProjectList *ui;
};

#endif // PROJECTLIST_H
