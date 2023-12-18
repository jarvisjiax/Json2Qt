#ifndef CHANNEL_H
#define CHANNEL_H

// Code generate by Json2Qt.py https://github.com/Loukei/Json2Qt.git
// ## How to Use:
// QJsonObject jsonObj = parseJsonFile("test.json");
// auto channel = Channel(jsonObj);
// ## Convert to json text
// auto jsonObj = channel.toQJsonObject();
// QJsonDocument jsonDoc(jsonObj);
// qDebug() << jsonDoc.toJson();

#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>


// class Channels
class Channels{
public:
    Channels() = default;
    Channels(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);

    FLELD(int,resolution)
    FLELD(QString,description)
    FLELD(int,errorno)
    FLELD(int,maximum)
    FLELD(int,minimum)
    FLELD(bool,output)
    FLELD(QString,type)
    FLELD(int,typeindex)
    FLELD(QString,unit)
    FLELD(int,unitindex)
};

// class Channel
class Channel{
public:
    Channel() = default;
    Channel(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);

    FLELD(Channels,channels)
};

#endif // CHANNEL_H
