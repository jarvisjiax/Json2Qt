QJsonObject parseJsonFile(const QString& filename);

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