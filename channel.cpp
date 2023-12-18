#include "channel.h"

QJsonObject parseJsonFile(const QString& filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        auto msg = QString("File (%1) open fail: %2.").arg(filename,file.errorString());
        qFatal("%s",msg.toStdString().c_str());
        return QJsonObject();
    }

    QJsonParseError jsonErr;
    auto jsonDoc = QJsonDocument::fromJson(file.readAll(),&jsonErr);
    if(jsonErr.error != QJsonParseError::NoError){
        auto msg = QString("File (%1) parse error: %2.").arg(filename,jsonErr.errorString());
        qFatal("%s",msg.toStdString().c_str());
        return QJsonObject();
    }
    return jsonDoc.object();
}

// construct Channels from QJsonObject,not 
Channels::Channels(const QJsonObject &jsonObj)
{
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse bool output
    this->output = jsonObj["output"].toBool();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
}

QJsonObject Channels::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("Resolution",this->resolution);
    obj.insert("description",this->description);
    obj.insert("errorno",this->errorno);
    obj.insert("maximum",this->maximum);
    obj.insert("minimum",this->minimum);
    obj.insert("output",this->output);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    return obj;
}

bool Channels::saveToJsonFile(const QString& filename)
{
    QJsonObject rootObj = this->toQJsonObject();
    QJsonDocument document;
     document.setObject(rootObj);
    QByteArray byte_array = document.toJson(QJsonDocument::Indented);
    QFile file1(filename);
    if (!file1.exists()) {
        qWarning("File does not exist: %s", filename.toStdString().c_str());
        return false;
    }
    if(!file1.open(QIODevice::WriteOnly)){
        auto msg = QString("File1 (%1) open fail: %2.").arg(filename,file1.errorString());
        qFatal("%s",msg.toStdString().c_str());
        return false;
    }
    file1.write(byte_array);
    file1.close();
    return true;
}


// construct Channel from QJsonObject,not 
Channel::Channel(const QJsonObject &jsonObj)
{
    // parse Channels channels
    this->channels = Channels(jsonObj["channels"].toObject());
}

QJsonObject Channel::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("channels",this->channels.toQJsonObject());
    return obj;
}

bool Channel::saveToJsonFile(const QString& filename)
{
    QJsonObject rootObj = this->toQJsonObject();
    QJsonDocument document;
     document.setObject(rootObj);
    QByteArray byte_array = document.toJson(QJsonDocument::Indented);
    QFile file1(filename);
    if (!file1.exists()) {
        qWarning("File does not exist: %s", filename.toStdString().c_str());
        return false;
    }
    if(!file1.open(QIODevice::WriteOnly)){
        auto msg = QString("File1 (%1) open fail: %2.").arg(filename,file1.errorString());
        qFatal("%s",msg.toStdString().c_str());
        return false;
    }
    file1.write(byte_array);
    file1.close();
    return true;
}


