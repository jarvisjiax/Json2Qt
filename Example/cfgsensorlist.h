#ifndef CFGSENSORLIST_H
#define CFGSENSORLIST_H

// Code generate by Json2Qt.py https://github.com/Loukei/Json2Qt.git
// ## How to Use:
// QJsonObject jsonObj = parseJsonFile("test.json");
// auto cfgsensorlist = Cfgsensorlist(jsonObj);
// ## Convert to json text
// auto jsonObj = cfgsensorlist.toQJsonObject();
// QJsonDocument jsonDoc(jsonObj);
// qDebug() << jsonDoc.toJson();

#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>


// class Sensorlist
class Sensorlist{
public:
    Sensorlist() = default;
    Sensorlist(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    int index;
    QString name;
    QString description;
    QString sn;
    QString type;
    int addr;
    QString ipdaddr;
};

// class Cfgsensorlist
class Cfgsensorlist{
public:
    Cfgsensorlist() = default;
    Cfgsensorlist(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    int total;
    QList<Sensorlist> sensorlist;
};

#endif // CFGSENSORLIST_H
