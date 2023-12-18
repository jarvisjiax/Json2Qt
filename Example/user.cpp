#include "user.h"


// construct User from QJsonObject,not 
User::User(const QJsonObject &jsonObj)
{
    // parse int userid
    this->userid = jsonObj["userid"].toInt();
    // parse QString username
    this->username = jsonObj["username"].toString();
    // parse bool verified
    this->verified = jsonObj["verified"].toBool();
    // parse double weight
    this->weight = jsonObj["weight"].toDouble();
    // parse QList<int> items
    QJsonArray itemsArray = jsonObj["items"].toArray();
    for(auto i:itemsArray){
        this->items.append(i.toInt());
    }
    // parse QList<QString> games
    QJsonArray gamesArray = jsonObj["games"].toArray();
    for(auto i:gamesArray){
        this->games.append(i.toString());
    }
}

QJsonObject User::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("userid",this->userid);
    obj.insert("username",this->username);
    obj.insert("verified",this->verified);
    obj.insert("weight",this->weight);
    //fill items
    QJsonArray ItemsArray;
    for(auto i:this->items){
        ItemsArray.append(i);
    }
    obj.insert("items",ItemsArray);
    //fill games
    QJsonArray GamesArray;
    for(auto i:this->games){
        GamesArray.append(i);
    }
    obj.insert("games",GamesArray);
    return obj;
}


