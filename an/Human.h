#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
using namespace std;
#include <QMainWindow>


class Human
{
protected:
    QString firstName;
    QString lastName;
    QString address;
    QString pNumber;
    QString lNumber;
    QString id;

public:
    Human();

    QString getFirstName();
    QString getLastName();
    QString getAddress();
    QString getId();
    QString getPNumber();
    QString getLNumber();

    void setFirstName(QString Nfirstname);
    void setLastName(QString Nlastname);
    void setAddress(QString Naddress);
    void setId(QString Nid);
    void setPNumber(QString NpNumber);
    void setLNumber(QString NlNumber);


    virtual QString getUsername() = 0;
    virtual QString getPassword() = 0;
    virtual QString getimageUrl() = 0;
    virtual void setUsername(QString username) = 0;
    virtual void setPassword(QString password) = 0;
    virtual void setImageUrl(QString NimageUrl) = 0;

};

#endif // HUMAN_H
