#include <iostream>
using namespace std;
#include <string.h>
#include <string>
#include "Human.h"

Human::Human()
{
    this->firstName = "empty";
    this->lastName = "empty";
    this->address = "empty";
    this->id = "empty";
    this->pNumber = "empty";
    this->lNumber = "empty";

}

QString Human::getFirstName()
{
    return this->firstName;
}

QString Human::getLastName()
{
    return this->lastName;
}

QString Human::getAddress()
{
    return this->address;
}

QString Human::getId()
{
    return this->id;
}

QString Human::getPNumber()
{
    return this->pNumber;
}

QString Human::getLNumber()
{
    return this->lNumber;
}

void Human::setFirstName(QString Nfirstname)
{
    this->firstName = Nfirstname;
}

void Human::setLastName(QString Nlastname)
{
    this->lastName = Nlastname;
}

void Human::setAddress(QString Naddress)
{
    this->address = Naddress;
}

void Human::setId(QString Nid)
{
    this->id =Nid;
}

void Human::setPNumber(QString NpNumber)
{
    this->pNumber =NpNumber;
}

void Human::setLNumber(QString NlNumber)
{
    this->lNumber =NlNumber;
}
