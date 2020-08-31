#ifndef CLIENT_H
#define CLIENT_H

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

class Client
{
protected:
    QString companyName;
    QString companyType;
    QString bossName;
    QString bossEmail;
    QString contractType;
    QString stateName;
    QString cityName;
    QString bossPhoneNumber;
    QString companyPhoneNumber;
    QString companyAddress;
    QString employeeUsername;
    bool status;

    QString pastCompanyName;

public:
    Client();


    QString getCompanyName();
    QString getCompanyType();
    QString getBossName();
    QString getBossEmail();
    QString getContractType();
    QString getStateName();
    QString getCityName();
    QString getBossPhoneNumber();
    QString getCompanyPhoneNumber();
    QString getCompanyAddress();
    QString getemployeeUsername();
    bool getStatus();

    QString getPastCompanyName();


    void setCompanyName(QString CompanyName);
    void setCompanyType(QString CompanyType);
    void setBossName(QString BossName);
    void setBossEmail(QString BossEmail);
    void setContractType(QString ContractType);
    void setStateName(QString StateName);
    void setCityName(QString CityName);
    void setBossPhoneNumber(QString BossPhoneNumber);
    void setCompanyPhoneNumber(QString CompanyPhoneNumber);
    void setCompanyAddress(QString CompanyAddress);
    void setemployeeUsername(QString employeeUsername);
    void setStatus(bool s);

    void setPastCompanyName(QString CompanyName);


    void updateJsonValues();
    void updateJsonValues_companiesName();
};

#endif // CLIENT_H
