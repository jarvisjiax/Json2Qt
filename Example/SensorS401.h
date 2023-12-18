#ifndef SENSORS401_H
#define SENSORS401_H

// Code generate by Json2Qt.py https://github.com/Loukei/Json2Qt.git
// ## How to Use:
// QJsonObject jsonObj = parseJsonFile("test.json");
// auto sensors401 = Sensors401(jsonObj);
// ## Convert to json text
// auto jsonObj = sensors401.toQJsonObject();
// QJsonDocument jsonDoc(jsonObj);
// qDebug() << jsonDoc.toJson();

#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>

//QJsonObject parseJsonFile(const QString& filename);

// class Modbus
class Modbus{
public:
    Modbus() = default;
    Modbus(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    int address;
    QString bandrate;
    int bandrateindex;
    int databits;
    QString parity;
    int stopbits;
    QString flowcontrol;
    QString mode;
    int modeindex;
    QString version;
};

// class Sdi
class Sdi{
public:
    Sdi() = default;
    Sdi(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString bandrate;
    int bandrateindex;
    QString version;
};

// class Ethernet
class Ethernet{
public:
    Ethernet() = default;
    Ethernet(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString ipaddr;
    QString netmask;
    QString gateway;
    QString dns;
    QString dhcp;
    int port;
};

// class Mbus
class Mbus{
public:
    Mbus() = default;
    Mbus(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString version;
};

// class Velocity
class Velocity{
public:
    Velocity() = default;
    Velocity(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    bool output;
};

// class Flow
class Flow{
public:
    Flow() = default;
    Flow(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    bool output;
};

// class Consumption
class Consumption{
public:
    Consumption() = default;
    Consumption(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    bool output;
};

// class Revconsumption
class Revconsumption{
public:
    Revconsumption() = default;
    Revconsumption(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    bool output;
};

// class Temperature
class Temperature{
public:
    Temperature() = default;
    Temperature(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    bool output;
};

// class Channels
class Channels{
public:
    Channels() = default;
    Channels(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QList<QString> channels;
    Velocity velocity;
    Flow flow;
    Consumption consumption;
    Revconsumption revconsumption;
    Temperature temperature;
};

// class Innerdiameter
class Innerdiameter{
public:
    Innerdiameter() = default;
    Innerdiameter(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    QString input;
};

// class Gastype
class Gastype{
public:
    Gastype() = default;
    Gastype(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    QString input;
};

// class Constant
class Constant{
public:
    Constant() = default;
    Constant(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    QString input;
};

// class Reftemperature
class Reftemperature{
public:
    Reftemperature() = default;
    Reftemperature(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    QString input;
};

// class Flowunit
class Flowunit{
public:
    Flowunit() = default;
    Flowunit(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    QString input;
    QList<QString> options;
    QList<int> optionsindex;
};

// class Consumptionunit
class Consumptionunit{
public:
    Consumptionunit() = default;
    Consumptionunit(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString description;
    QString unit;
    int unitindex;
    QString type;
    int typeindex;
    int resolution;
    int minimum;
    int maximum;
    int errorno;
    QString input;
};

// class Settings
class Settings{
public:
    Settings() = default;
    Settings(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QList<QString> settings;
    Innerdiameter innerdiameter;
    Gastype gastype;
    Constant constant;
    Reftemperature reftemperature;
    Flowunit flowunit;
    Consumptionunit consumptionunit;
};

// class Sensors401
class Sensors401{
public:
    Sensors401() = default;
    Sensors401(const QJsonObject &jsonObj);
    QJsonObject toQJsonObject() const;
    bool saveToJsonFile(const QString& filename);
    QString name;
    int connetiontype;
    Modbus modbus;
    Sdi sdi;
    Ethernet ethernet;
    Mbus mbus;
    Channels channels;
    Settings settings;
};

#endif // SENSORS401_H
