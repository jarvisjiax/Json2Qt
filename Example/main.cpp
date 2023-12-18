/******************************************************************************
 * @Author                : jarvis<1405191257@qq.com>                         *
 * @CreatedDate           : 2023-12-13 12:22:29                               *
 * @LastEditors           : jarvis<1405191257@qq.com>                         *
 * @LastEditDate          : 2023-12-15 10:46:02                               *
 * @FilePath              : S335/Json2Qt/Example/main.cpp                     *
 * @CopyRight             : Jarvis<1405191257@qq.com>                         *
 *****************************************************************************/

#include <QCoreApplication>
#include "user.h"
#include "SensorS401.h"

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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QJsonObject jsonObj = parseJsonFile("C:/user.json");
//    auto user = User(jsonObj);
//    qDebug() << "User:" << user.toQJsonObject();





    QJsonObject jsonObj = parseJsonFile("cfgsensors401.json");
    auto sensor401 = Sensors401(jsonObj);

    qDebug()<<"Sensors401.S401.name"<<sensor401.name;
    qDebug()<<"Sensors401.S401.connetiontype"<<sensor401.connetiontype;
    qDebug()<<"Sensors401.S401.modbus.address"<<sensor401.modbus.address;
    qDebug()<<"Sensors401.S401.modbus.bandrate"<<sensor401.modbus.bandrate;
    qDebug()<<"Sensors401.S401.modbus.bandrateindex"<<sensor401.modbus.bandrateindex;
    qDebug()<<"Sensors401.S401.modbus.databits"<<sensor401.modbus.databits;
    qDebug()<<"Sensors401.S401.ethernet.ip"<<sensor401.ethernet.ipaddr;
    qDebug()<<"Sensors401.S401.ethernet.port"<<sensor401.ethernet.port;
    qDebug()<<"Sensors401.S401.setting.flowunit.options"<<sensor401.settings.flowunit.options;

    sensor401.ethernet.ipaddr="192.168.8.8";
    sensor401.saveToJsonFile("cfgsensors401.json");


		// "index": 1,
		// "name": "S430",
		// "description": "S430",
		// "sn": "12345679",
		// "type": "SDI",
        // "addr":1,
        // "ipdaddr": "192.168.1.101"

    qDebug()<<"======================================================";

    QJsonObject senlist = parseJsonFile("cfgsensorlist.json");
    auto cfgsenlist = Cfgsensorlist(senlist);

    for(int i = 0;i<cfgsenlist.sensorlist.length();i++){

        qDebug()<<"index="<<cfgsenlist.sensorlist.at(i).index;
        qDebug()<<"name="<<cfgsenlist.sensorlist.at(i).name;
        qDebug()<<""<<cfgsenlist.sensorlist.at(i).sn;
        qDebug()<<""<<cfgsenlist.sensorlist.at(i).type;
        qDebug()<<""<<cfgsenlist.sensorlist.at(i).addr;
        qDebug()<<""<<cfgsenlist.sensorlist.at(i).ipdaddr;

    }


 

//    return a.exec();
}


// S401:{
//     name: "S401",
//     connetiontype:0
//     modbus:{
//         address: 1,
//         bandrate: "115200",
//         bandrateindex:0,
//         databits: 8,
//         parity: "none",
//         stopbits: 1,
//         flowcontrol: "none",
//         mode: "rtu",
//         modeindex:1
//         version:"v1.0"
//     },
//     sdi:{
//         bandrate: "115200",
//         bandrateindex:0,
//         version: "v1.0",
//     },
//     ethernet:{
//         ipaddr: "192.168.1.100",
//         netmask: "255.255.255.0",
//         gateway: "192.168.1.1",
//         dns: "192.168.1.1",
//         dhcp: "true"
//         port:502        
//     },
//     mbus:{
//         version: "v1.0",
//     },
//     channels:{
//         channels:["Velocity","Flow","Consumption","Revconsumption","Temperature",],
//         Velocity:{
//             description:"Velocity",
//             unit:"m/s",
//             unitindex:0,
//             type:"float",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             output:false
//         },
//         Flow:{
//             description:"Flow",
//             unit:"m3/h",
//             unitindex:0,
//             type:"float",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             output:true
//         },
//         Consumption:{
//             description:"Consumption",
//             unit:"m3",
//             unitindex:0,
//             type:"float",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             output:true
//         },
//         Revconsumption:{
//             description:"Reversed Consumption",
//             unit:"m3",
//             unitindex:0,
//             type:"float",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             output:false
//         },
//         Temperature:{
//             description:"Temperature",
//             unit:"°C",
//             unitindex:0,
//             type:"float",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             output:false
//         }
//     },
//     settings:{
//         settings:["innerdiameter","gastype","Constant","Reftemperature","flowunit","consumptionUnit"],
//         innerdiameter:{
//             description:"Inner Diameter",
//             unit:"mm",
//             unitindex:0,
//             type:"float",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             input:"lineEdit"
//         },
//         gastype:{
//             description:"Gas Type",
//             unit:"",
//             unitindex:0,
//             type:"string",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             input:"comboBox"
//         },
//         Constant:{
//             description:"Constant",
//             unit:"",
//             unitindex:0,
//             type:"float",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             input:"lineEdit"
//         },
//         Reftemperature:{
//             description:"Reference Temperature",
//             unit:"",
//             unitindex:0,
//             type:"float",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             input:"lineEdit"
//         },
//         flowunit:{
//             description:"Flow Unit",
//             unit:"",
//             unitindex:0,
//             type:"string",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             input:"comboBox"
//             options:["Air","N2","Ar","CO2,"He","H2"],
//             optionsindex:[1,2,3.4,5,6,7]    
//         },
//         consumptionUnit:{
//             description:"Consumption Unit",
//             unit:"",
//             unitindex:0,
//             type:"string",
//             typeindex:0,
//             Resolution:1,
//             minimum:0,
//             maximum:1000,
//             errorno:-9999,
//             input:"comboBox"
//         }
//     }

// }
