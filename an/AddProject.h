#ifndef ADDPROJECT_H
#define ADDPROJECT_H

#include <QDialog>

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

namespace Ui {
class AddProject;
}

class AddProject : public QDialog
{
    Q_OBJECT

public:
    explicit AddProject(QWidget *parent = nullptr);
    ~AddProject();

    void setCombo();
    void save();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddProject *ui;

    QJsonArray arr;
};

#endif // ADDPROJECT_H
