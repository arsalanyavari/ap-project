#include "bossclass.h"


bossclass::bossclass()
    :Human()
{
}
QString bossclass::getUsername()
{
   return this->username;
}

QString bossclass::getPassword()
{
    return this->password;
}

QString bossclass::getimageUrl()
{
    return this->imageUrl;
}

void bossclass::setUsername(QString username)
{
    this->username = username;
}

void bossclass::setPassword(QString password)
{
    this->password = password;
}

void bossclass::setImageUrl(QString NimageUrl)
{
    this->imageUrl = NimageUrl;
}

void bossclass::updateJsonFile()
{

        QString path = "Files/Boss/" + this->getUsername() + ".json";
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

        QJsonObject boss;
        boss["username"] = this->getUsername();
        boss["password"] = this->getPassword();
        boss["imageUrl"] = this->getimageUrl();

        user["human"] = human;
        user["boss"] = boss;
        j["modir"] = user;


        QJsonDocument d(j);
        QFile f(path);
        f.open(QIODevice::WriteOnly);
        f.write(d.toJson());




}
