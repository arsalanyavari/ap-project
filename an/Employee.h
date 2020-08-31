#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Human.h"

#include <iostream>
using namespace std;
#include <QMainWindow>

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

class Employee
    :public Human
{
protected:
    QString username;
    QString password;
    QString fixed;
    QString variable;
    double percent_d;
    QString percent_s;
    QString salary;
    QString numberofClient;
    QString numberofVacations;
    QString unit;
    QString imageUrl;

public:
    Employee();
    void setEmployee(QString username);

    QString getUsername();
    QString getPassword();
    QString getFixed();
    QString getVariable();
    QString getPercent_s();
    double getPercent_d();
    QString getSalary();
    QString getNOClient();
    QString getNOVacations();
    QString getUnit();
    QString getimageUrl();

    void updateJsonValues();

    void setUsername(QString username);
    void setPassword(QString password);
    void setFixed(QString fixed);
    void setVariable(QString variable);
    void setPercent_d(double percent_d);
    void setPercent_s(QString percent_s);
    void setSalary(QString salary);
    void setNOClient(QString noClient);
    void setNOVacations(QString noVactions);
    void setUnit(QString unit);
    void setImageUrl(QString NimageUrl);


    void calculateSalary();
};

#endif // EMPLOYEE_H
