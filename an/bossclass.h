#ifndef BOSSCLASS_H
#define BOSSCLASS_H
#include "Human.h"

#include <iostream>
using namespace std;
#include <QMainWindow>

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

class bossclass
    :public Human
{
protected:
    QString username;
    QString password;
    QString imageUrl;

public:
    bossclass();


    void updateJsonFile();

    QString getUsername();
    QString getPassword();
    QString getimageUrl();
    void setUsername(QString username);
    void setPassword(QString password);
    void setImageUrl(QString NimageUrl);

};

#endif
