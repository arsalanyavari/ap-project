#include "Client.h"


Client::Client()
{
    this->status = true;
}

QString Client::getCompanyName()
{
    return companyName;
}

QString Client::getCompanyType()
{
    return companyType;
}

QString Client::getBossName()
{
    return bossName;
}

QString Client::getBossEmail()
{
    return bossEmail;
}

QString Client::getContractType()
{
    return contractType;
}

QString Client::getStateName()
{
    return stateName;
}

QString Client::getCityName()
{
    return cityName;
}

QString Client::getBossPhoneNumber()
{
    return bossPhoneNumber;
}

QString Client::getCompanyPhoneNumber()
{
    return companyPhoneNumber;
}

QString Client::getCompanyAddress()
{
    return companyAddress;
}

QString Client::getemployeeUsername()
{
    return this->employeeUsername;
}

bool Client::getStatus()
{
    return this->status;
}

QString Client::getPastCompanyName()
{
    return this->pastCompanyName;
}

void Client::setCompanyName(QString CompanyName)
{
    this->companyName = CompanyName;
}

void Client::setCompanyType(QString CompanyType)
{
    this->companyType = CompanyType;
}

void Client::setBossName(QString BossName)
{
    this->bossName = BossName;
}

void Client::setBossEmail(QString BossEmail)
{
    this->bossEmail = BossEmail;
}

void Client::setContractType(QString ContractType)
{
    this->contractType = ContractType;
}

void Client::setStateName(QString StateName)
{
    this->stateName = StateName;
}

void Client::setCityName(QString CityName)
{
    this->cityName = CityName;
}

void Client::setBossPhoneNumber(QString BossPhoneNumber)
{
    this->bossPhoneNumber = BossPhoneNumber;
}

void Client::setCompanyPhoneNumber(QString CompanyPhoneNumber)
{
    this->companyPhoneNumber = CompanyPhoneNumber;
}

void Client::setCompanyAddress(QString CompanyAddress)
{
    this->companyAddress = CompanyAddress;
}

void Client::setemployeeUsername(QString employeeUsername)
{
    this->employeeUsername = employeeUsername;
}

void Client::setStatus(bool s)
{
    this->status = s;
}

void Client::setPastCompanyName(QString CompanyName)
{
    this->pastCompanyName = CompanyName;
}

void Client::updateJsonValues()
{

    QString path = "Files/Clients/" + this->companyName + ".json";
    QFile f(path);
    f.open(QIODevice::WriteOnly);

    QJsonObject o;

    o["companyName"] = companyName;
    o["companyType"] = companyType;
    o["companyPhoneNumber"] = companyPhoneNumber;
    o["companyAddress"] = companyAddress;
    o["bossName"] = bossName;
    o["bossEmail"] = bossEmail;
    o["bossPhoneNumber"] = bossPhoneNumber;
    o["stateName"] = stateName;
    o["cityName"] = cityName;
    o["contractType"] = contractType;
    o["employeeUsername"] = employeeUsername;
    o["status"] = this->status;

    QJsonDocument d(o);
    f.write(d.toJson());

    f.close();


    updateJsonValues_companiesName();
    return;
}

void Client::updateJsonValues_companiesName()
{
    QFile g("Files/Clients/companiesName.json");
    g.open(QIODevice::ReadOnly);
    QByteArray r = g.readAll();
    QJsonDocument t = QJsonDocument::fromJson(r);
    QJsonObject o = t.object();

    QJsonArray arr;

    int tag = -1;

    for(int i = 0 ; i < o["companiesName"].toArray().size() ; i++)
    {
        arr.append((o["companiesName"].toArray())[i].toString());
        if(arr[i] == this->companyName || arr[i] == this->pastCompanyName)
        {
            tag = i;
        }
    }
    g.close();


    if(tag == -1)
    {
        arr.append(this->companyName);
    }
    else
    {
        arr[tag] = this->companyName;
    }



    QFile f("Files/Clients/companiesName.json");
    f.open(QIODevice::WriteOnly);


    QJsonObject obj;
    obj["companiesName"] = arr;
    QJsonDocument d(obj);
    f.write(d.toJson());
    f.close();



    return;
}
