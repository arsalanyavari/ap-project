#include "Employee.h"


Employee::Employee()
    :Human()
{
    this->fixed = "empty";
    this->variable = "empty";
    this->percent_d = 0;
    this->percent_s = "empty";
    this->salary = "empty";
    this->numberofClient = "empty";
    this->numberofVacations = "empty";
    this->unit = "empty";
}

void Employee::setEmployee(QString username)
{
    QString path = "Files/Employees/" + username + ".json";
    QFile f(path);

    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();

    this->firstName = ((o[username].toObject())["human"].toObject())["firstName"].toString();
    this->lastName = ((o[username].toObject())["human"].toObject())["lastName"].toString();
    this->pNumber = ((o[username].toObject())["human"].toObject())["pNumber"].toString();
    this->lNumber = ((o[username].toObject())["human"].toObject())["lNumber"].toString();
    this->id = ((o[username].toObject())["human"].toObject())["id"].toString();
    this->address = ((o[username].toObject())["human"].toObject())["address"].toString();


    this->username = ((o[username].toObject())["employee"].toObject())["username"].toString();
    this->password = ((o[username].toObject())["employee"].toObject())["password"].toString();
    this->fixed = ((o[username].toObject())["employee"].toObject())["fixed"].toString();
    this->variable = ((o[username].toObject())["employee"].toObject())["variable"].toString();
    this->percent_d = ((o[username].toObject())["employee"].toObject())["percent_d"].toDouble();
    this->percent_s = ((o[username].toObject())["employee"].toObject())["percent_s"].toString();
    this->salary = ((o[username].toObject())["employee"].toObject())["salary"].toString();
    this->numberofClient = ((o[username].toObject())["employee"].toObject())["numberofClient"].toString();
    this->numberofVacations = ((o[username].toObject())["employee"].toObject())["numberofVacations"].toString();
    this->unit = ((o[username].toObject())["employee"].toObject())["unit"].toString();
    this->imageUrl = ((o[username].toObject())["employee"].toObject())["imageUrl"].toString();
}

QString Employee::getUsername()
{
   return this->username;
}

QString Employee::getPassword()
{
    return this->password;
}

QString Employee::getFixed()
{
    return this->fixed;
}

QString Employee::getVariable()
{
    return this->variable;
}

QString Employee::getPercent_s()
{
    return this->percent_s;
}

double Employee::getPercent_d()
{
    return this->percent_d;
}

QString Employee::getSalary()
{
    return this->salary;
}

QString Employee::getNOClient()
{
    return this->numberofClient;
}

QString Employee::getNOVacations()
{
    return this->numberofVacations;
}

QString Employee::getUnit()
{
    return this->unit;
}

QString Employee::getimageUrl()
{
    return this->imageUrl;
}

void Employee::setUsername(QString username)
{
    this->username = username;
}

void Employee::setPassword(QString password)
{
    this->password = password;
}

void Employee::setFixed(QString fixed)
{
    this->fixed = fixed;
}

void Employee::setVariable(QString variable)
{
    this->variable = variable;
}

void Employee::setPercent_d(double percent_d)
{
    this->percent_d = percent_d;
}

void Employee::setPercent_s(QString percent_s)
{
    this->percent_s = percent_s;
}

void Employee::setSalary(QString salary)
{
    this->salary = salary;
}

void Employee::setNOClient(QString noClient)
{
    this->numberofClient = noClient;
}

void Employee::setNOVacations(QString noVactions)
{
    this->numberofVacations = noVactions;
}

void Employee::setUnit(QString unit)
{
    this->unit = unit;
}

void Employee::setImageUrl(QString NimageUrl)
{
    this->imageUrl = NimageUrl;
}

void Employee::calculateSalary()
{
    this->salary = fixed + (variable.toInt() * percent_d);
}

void Employee::updateJsonValues()
{
        QString path = "Files/Employees/" + this->getUsername() + ".json";
        QFile i(path);

        i.open(QIODevice::ReadOnly);
        QByteArray b = i.readAll();
        QJsonDocument c = QJsonDocument::fromJson(b);
        QJsonObject o = c.object();

        QJsonObject j;

        QJsonObject user;
        QJsonObject human;
        human["firstName"] = this->getFirstName();
        human["lastName"] = this->getLastName();
        human["pNumber"] = this->getPNumber();
        human["lNumber"] = this->getLNumber();
        human["id"] = this->getId();
        human["address"] = this->getAddress();

        QJsonObject employee;
        employee["username"] = this->getUsername();
        employee["password"] = this->getPassword();
        employee["fixed"] = this->getFixed();
        employee["variable"] = this->getVariable();
        employee["percent_d"] = this->getPercent_d();
        employee["percent_s"] = this->getPercent_s();
        employee["salary"] = this->getSalary();
        employee["numberofClient"] = this->getNOClient();
        employee["numberofVacations"] = this->getNOVacations();
        employee["unit"] = this->getUnit();
        employee["imageUrl"] = this->getimageUrl();

        user["human"] = human;
        user["employee"] = employee;
        j[this->getUsername()] = user;


        QJsonDocument d(j);
        QFile f(path);
        f.open(QIODevice::WriteOnly);
        f.write(d.toJson());
}
