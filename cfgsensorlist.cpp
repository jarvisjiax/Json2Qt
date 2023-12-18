#include "cfgsensorlist.h"

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

// construct Cfgsensorlist from QJsonObject,not 
Cfgsensorlist::Cfgsensorlist(const QJsonObject &jsonObj)
{
    // parse QList<Sensorlist*> sensorlist
    QJsonArray sensorlistArray = jsonObj["sensorlist"].toArray();
    for(auto i:sensorlistArray){
        this->sensorlist.append(new Sensorlist(i.toObject()));
    }
}

QJsonObject Cfgsensorlist::toQJsonObject() const
{
    QJsonObject obj;
    //fill sensorlist
    QJsonArray SensorlistArray;
    for(auto i:this->sensorlist){
        SensorlistArray.append(i->toQJsonObject());
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


