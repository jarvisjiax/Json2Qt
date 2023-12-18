#include "SensorS401.h"



// construct Modbus from QJsonObject,not 
Modbus::Modbus(const QJsonObject &jsonObj)
{
    // parse int address
    this->address = jsonObj["address"].toInt();
    // parse QString bandrate
    this->bandrate = jsonObj["bandrate"].toString();
    // parse int bandrateindex
    this->bandrateindex = jsonObj["bandrateindex"].toInt();
    // parse int databits
    this->databits = jsonObj["databits"].toInt();
    // parse QString parity
    this->parity = jsonObj["parity"].toString();
    // parse int stopbits
    this->stopbits = jsonObj["stopbits"].toInt();
    // parse QString flowcontrol
    this->flowcontrol = jsonObj["flowcontrol"].toString();
    // parse QString mode
    this->mode = jsonObj["mode"].toString();
    // parse int modeindex
    this->modeindex = jsonObj["modeindex"].toInt();
    // parse QString version
    this->version = jsonObj["version"].toString();
}

QJsonObject Modbus::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("address",this->address);
    obj.insert("bandrate",this->bandrate);
    obj.insert("bandrateindex",this->bandrateindex);
    obj.insert("databits",this->databits);
    obj.insert("parity",this->parity);
    obj.insert("stopbits",this->stopbits);
    obj.insert("flowcontrol",this->flowcontrol);
    obj.insert("mode",this->mode);
    obj.insert("modeindex",this->modeindex);
    obj.insert("version",this->version);
    return obj;
}

bool Modbus::saveToJsonFile(const QString& filename)
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


// construct Sdi from QJsonObject,not 
Sdi::Sdi(const QJsonObject &jsonObj)
{
    // parse QString bandrate
    this->bandrate = jsonObj["bandrate"].toString();
    // parse int bandrateindex
    this->bandrateindex = jsonObj["bandrateindex"].toInt();
    // parse QString version
    this->version = jsonObj["version"].toString();
}

QJsonObject Sdi::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("bandrate",this->bandrate);
    obj.insert("bandrateindex",this->bandrateindex);
    obj.insert("version",this->version);
    return obj;
}

bool Sdi::saveToJsonFile(const QString& filename)
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


// construct Ethernet from QJsonObject,not 
Ethernet::Ethernet(const QJsonObject &jsonObj)
{
    // parse QString ipaddr
    this->ipaddr = jsonObj["ipaddr"].toString();
    // parse QString netmask
    this->netmask = jsonObj["netmask"].toString();
    // parse QString gateway
    this->gateway = jsonObj["gateway"].toString();
    // parse QString dns
    this->dns = jsonObj["dns"].toString();
    // parse QString dhcp
    this->dhcp = jsonObj["dhcp"].toString();
    // parse int port
    this->port = jsonObj["port"].toInt();
}

QJsonObject Ethernet::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("ipaddr",this->ipaddr);
    obj.insert("netmask",this->netmask);
    obj.insert("gateway",this->gateway);
    obj.insert("dns",this->dns);
    obj.insert("dhcp",this->dhcp);
    obj.insert("port",this->port);
    return obj;
}

bool Ethernet::saveToJsonFile(const QString& filename)
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


// construct Mbus from QJsonObject,not 
Mbus::Mbus(const QJsonObject &jsonObj)
{
    // parse QString version
    this->version = jsonObj["version"].toString();
}

QJsonObject Mbus::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("version",this->version);
    return obj;
}

bool Mbus::saveToJsonFile(const QString& filename)
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


// construct Velocity from QJsonObject,not 
Velocity::Velocity(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse bool output
    this->output = jsonObj["output"].toBool();
}

QJsonObject Velocity::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("output",this->output);
    return obj;
}

bool Velocity::saveToJsonFile(const QString& filename)
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


// construct Flow from QJsonObject,not 
Flow::Flow(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse bool output
    this->output = jsonObj["output"].toBool();
}

QJsonObject Flow::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("output",this->output);
    return obj;
}

bool Flow::saveToJsonFile(const QString& filename)
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


// construct Consumption from QJsonObject,not 
Consumption::Consumption(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse bool output
    this->output = jsonObj["output"].toBool();
}

QJsonObject Consumption::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("output",this->output);
    return obj;
}

bool Consumption::saveToJsonFile(const QString& filename)
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


// construct Revconsumption from QJsonObject,not 
Revconsumption::Revconsumption(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse bool output
    this->output = jsonObj["output"].toBool();
}

QJsonObject Revconsumption::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("output",this->output);
    return obj;
}

bool Revconsumption::saveToJsonFile(const QString& filename)
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


// construct Temperature from QJsonObject,not 
Temperature::Temperature(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse bool output
    this->output = jsonObj["output"].toBool();
}

QJsonObject Temperature::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("output",this->output);
    return obj;
}

bool Temperature::saveToJsonFile(const QString& filename)
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


// construct Channels from QJsonObject,not 
Channels::Channels(const QJsonObject &jsonObj)
{
    // parse QList<QString> channels
    QJsonArray channelsArray = jsonObj["channels"].toArray();
    for(auto i:channelsArray){
        this->channels.append(i.toString());
    }
    // parse Velocity velocity
    this->velocity = Velocity(jsonObj["Velocity"].toObject());
    // parse Flow flow
    this->flow = Flow(jsonObj["Flow"].toObject());
    // parse Consumption consumption
    this->consumption = Consumption(jsonObj["Consumption"].toObject());
    // parse Revconsumption revconsumption
    this->revconsumption = Revconsumption(jsonObj["Revconsumption"].toObject());
    // parse Temperature temperature
    this->temperature = Temperature(jsonObj["Temperature"].toObject());
}

QJsonObject Channels::toQJsonObject() const
{
    QJsonObject obj;
    //fill channels
    QJsonArray ChannelsArray;
    for(auto i:this->channels){
        ChannelsArray.append(i);
    }
    obj.insert("channels",ChannelsArray);
    obj.insert("Velocity",this->velocity.toQJsonObject());
    obj.insert("Flow",this->flow.toQJsonObject());
    obj.insert("Consumption",this->consumption.toQJsonObject());
    obj.insert("Revconsumption",this->revconsumption.toQJsonObject());
    obj.insert("Temperature",this->temperature.toQJsonObject());
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


// construct Innerdiameter from QJsonObject,not 
Innerdiameter::Innerdiameter(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse QString input
    this->input = jsonObj["input"].toString();
}

QJsonObject Innerdiameter::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("input",this->input);
    return obj;
}

bool Innerdiameter::saveToJsonFile(const QString& filename)
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


// construct Gastype from QJsonObject,not 
Gastype::Gastype(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse QString input
    this->input = jsonObj["input"].toString();
}

QJsonObject Gastype::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("input",this->input);
    return obj;
}

bool Gastype::saveToJsonFile(const QString& filename)
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


// construct Constant from QJsonObject,not 
Constant::Constant(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse QString input
    this->input = jsonObj["input"].toString();
}

QJsonObject Constant::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("input",this->input);
    return obj;
}

bool Constant::saveToJsonFile(const QString& filename)
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


// construct Reftemperature from QJsonObject,not 
Reftemperature::Reftemperature(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse QString input
    this->input = jsonObj["input"].toString();
}

QJsonObject Reftemperature::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("input",this->input);
    return obj;
}

bool Reftemperature::saveToJsonFile(const QString& filename)
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


// construct Flowunit from QJsonObject,not 
Flowunit::Flowunit(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse QString input
    this->input = jsonObj["input"].toString();
    // parse QList<QString> options
    QJsonArray optionsArray = jsonObj["options"].toArray();
    for(auto i:optionsArray){
        this->options.append(i.toString());
    }
    // parse QList<int> optionsindex
    QJsonArray optionsindexArray = jsonObj["optionsindex"].toArray();
    for(auto i:optionsindexArray){
        this->optionsindex.append(i.toInt());
    }
}

QJsonObject Flowunit::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("input",this->input);
    //fill options
    QJsonArray OptionsArray;
    for(auto i:this->options){
        OptionsArray.append(i);
    }
    obj.insert("options",OptionsArray);
    //fill optionsindex
    QJsonArray OptionsindexArray;
    for(auto i:this->optionsindex){
        OptionsindexArray.append(i);
    }
    obj.insert("optionsindex",OptionsindexArray);
    return obj;
}

bool Flowunit::saveToJsonFile(const QString& filename)
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


// construct Consumptionunit from QJsonObject,not 
Consumptionunit::Consumptionunit(const QJsonObject &jsonObj)
{
    // parse QString description
    this->description = jsonObj["description"].toString();
    // parse QString unit
    this->unit = jsonObj["unit"].toString();
    // parse int unitindex
    this->unitindex = jsonObj["unitindex"].toInt();
    // parse QString type
    this->type = jsonObj["type"].toString();
    // parse int typeindex
    this->typeindex = jsonObj["typeindex"].toInt();
    // parse int resolution
    this->resolution = jsonObj["Resolution"].toInt();
    // parse int minimum
    this->minimum = jsonObj["minimum"].toInt();
    // parse int maximum
    this->maximum = jsonObj["maximum"].toInt();
    // parse int errorno
    this->errorno = jsonObj["errorno"].toInt();
    // parse QString input
    this->input = jsonObj["input"].toString();
}

QJsonObject Consumptionunit::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("description",this->description);
    obj.insert("unit",this->unit);
    obj.insert("unitindex",this->unitindex);
    obj.insert("type",this->type);
    obj.insert("typeindex",this->typeindex);
    obj.insert("Resolution",this->resolution);
    obj.insert("minimum",this->minimum);
    obj.insert("maximum",this->maximum);
    obj.insert("errorno",this->errorno);
    obj.insert("input",this->input);
    return obj;
}

bool Consumptionunit::saveToJsonFile(const QString& filename)
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


// construct Settings from QJsonObject,not 
Settings::Settings(const QJsonObject &jsonObj)
{
    // parse QList<QString> settings
    QJsonArray settingsArray = jsonObj["settings"].toArray();
    for(auto i:settingsArray){
        this->settings.append(i.toString());
    }
    // parse Innerdiameter innerdiameter
    this->innerdiameter = Innerdiameter(jsonObj["innerdiameter"].toObject());
    // parse Gastype gastype
    this->gastype = Gastype(jsonObj["gastype"].toObject());
    // parse Constant constant
    this->constant = Constant(jsonObj["Constant"].toObject());
    // parse Reftemperature reftemperature
    this->reftemperature = Reftemperature(jsonObj["Reftemperature"].toObject());
    // parse Flowunit flowunit
    this->flowunit = Flowunit(jsonObj["flowunit"].toObject());
    // parse Consumptionunit consumptionunit
    this->consumptionunit = Consumptionunit(jsonObj["consumptionUnit"].toObject());
}

QJsonObject Settings::toQJsonObject() const
{
    QJsonObject obj;
    //fill settings
    QJsonArray SettingsArray;
    for(auto i:this->settings){
        SettingsArray.append(i);
    }
    obj.insert("settings",SettingsArray);
    obj.insert("innerdiameter",this->innerdiameter.toQJsonObject());
    obj.insert("gastype",this->gastype.toQJsonObject());
    obj.insert("Constant",this->constant.toQJsonObject());
    obj.insert("Reftemperature",this->reftemperature.toQJsonObject());
    obj.insert("flowunit",this->flowunit.toQJsonObject());
    obj.insert("consumptionUnit",this->consumptionunit.toQJsonObject());
    return obj;
}

bool Settings::saveToJsonFile(const QString& filename)
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


// construct Sensors401 from QJsonObject,not 
Sensors401::Sensors401(const QJsonObject &jsonObj)
{
    // parse QString name
    this->name = jsonObj["name"].toString();
    // parse int connetiontype
    this->connetiontype = jsonObj["connetiontype"].toInt();
    // parse Modbus modbus
    this->modbus = Modbus(jsonObj["modbus "].toObject());
    // parse Sdi sdi
    this->sdi = Sdi(jsonObj["sdi"].toObject());
    // parse Ethernet ethernet
    this->ethernet = Ethernet(jsonObj["ethernet"].toObject());
    // parse Mbus mbus
    this->mbus = Mbus(jsonObj["mbus"].toObject());
    // parse Channels channels
    this->channels = Channels(jsonObj["channels"].toObject());
    // parse Settings settings
    this->settings = Settings(jsonObj["settings"].toObject());
}

QJsonObject Sensors401::toQJsonObject() const
{
    QJsonObject obj;
    obj.insert("name",this->name);
    obj.insert("connetiontype",this->connetiontype);
    obj.insert("modbus ",this->modbus.toQJsonObject());
    obj.insert("sdi",this->sdi.toQJsonObject());
    obj.insert("ethernet",this->ethernet.toQJsonObject());
    obj.insert("mbus",this->mbus.toQJsonObject());
    obj.insert("channels",this->channels.toQJsonObject());
    obj.insert("settings",this->settings.toQJsonObject());
    return obj;
}

bool Sensors401::saveToJsonFile(const QString& filename)
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


