#include "cfgsensorlist.h"


// construct Sensorlist from QJsonObject,not 
Sensorlist::Sensorlist(const QJsonObject &jsonObj)
{
    // parse int index
    this->index = jsonObj["index"].toInt();
    // parse QString name
    this->name = jsonObj["name"].toString();
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString sn
    this->sn = jsonObj["sn"].toString();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int addr
    this->addr = jsonObj["addr"].toInt();
    // parse QString ipdaddr
    this->ipdaddr = jsonObj["ipdaddr"].toString();
}

QJsonObject Sensorlist::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("index",this->index);
    obj.insert("name",this->name);
    obj.insert("description",this->description);
    obj.insert("sn",this->sn);
    obj.insert("type",this->type);
    obj.insert("addr",this->addr);
    obj.insert("ipdaddr",this->ipdaddr);
    return obj;
}

bool Sensorlist::saveToJsonFile(const QString& filename)
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


// construct Cfgsensorlist from QJsonObject,not 
Cfgsensorlist::Cfgsensorlist(const QJsonObject &jsonObj)
{
    // parse int total
    this->total = jsonObj["total"].toInt();
    // parse Sensorlist sensorlist
//    this->sensorlist = Sensorlist(jsonObj["sensorlist"].toObject());
    // parse QList<Sensorlist> sensorlist
    QJsonArray sensorlistArray = jsonObj["sensorlist"].toArray();
    for(auto i:sensorlistArray){
        this->sensorlist.append(Sensorlist(i.toObject()));
    }
}

QJsonObject Cfgsensorlist::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("total",this->total);
//    obj.insert("sensorlist",this->sensorlist.toQJsonObject());
    //fill sensorlist
    QJsonArray SensorlistArray;
    for(auto i:this->sensorlist){
        SensorlistArray.append(i.toQJsonObject());
    }
    obj.insert("sensorlist",SensorlistArray);
    return obj;
}

bool Cfgsensorlist::saveToJsonFile(const QString& filename)
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


