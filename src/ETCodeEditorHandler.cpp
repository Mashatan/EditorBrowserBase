// Date: 2014
// Author: Ali Mashatan
// Email : ali.mashatan@gmail.com

#include <ETCodeEditorHandler.h>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>


ETCodeEditorHandler::ETCodeEditorHandler(QObject *obj)
{
    m_ptrObject = obj;
    bool result = QObject::connect(obj, SIGNAL(onEventHandler(const QString)),
                     this, SLOT(doEventHandler(const QString)));
    Q_ASSERT(result);
}

void ETCodeEditorHandler::appendAnnotation(int line, int start, int end, QString text)
{
    Item item;
    item.line = line;
    item.start = start;
    item.end = end;
    item.text = text;
    m_List.append(item);
}

void ETCodeEditorHandler::clearAnnotation()
{
    m_List.clear();
}


void ETCodeEditorHandler::doEventHandler(const QString message)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(message.toLatin1());
    QJsonObject jsonObj = jsonDoc.object();
    switch (jsonObj["type"].toInt())
    {
        case ehChange:
        {
            //Access to source code.
            //qDebug() << "data: " << jsonObj["data"].toString();

            //It's just a compiler simulation.
            QTimer::singleShot(10, this, SLOT(doSimulationCompileTimer()));

        }break;
        default:
        {
            qDebug() << "message:" << message;
        }
    }
}

void ETCodeEditorHandler::doSimulationCompileTimer()
{
    //Making a static annotation.
    {
        clearAnnotation();
        appendAnnotation(2, 9, 19, "function unknown.");
        appendAnnotation(4, 4, 12, "variable unknown.");
    }

    //Preparing json data from annotation list.
    QJsonObject jsonObj;
    jsonObj["type"] = 200;
    QJsonArray jsonArray;
    foreach (Item p, this->m_List)
    {
        QJsonObject jsonData;
        jsonData["line"] = p.line;
        jsonData["start"] = p.start;
        jsonData["end"] = p.end;
        jsonData["text"] = p.text;
        jsonArray.append(jsonData);
    }
    jsonObj["data"] = jsonArray;
    QJsonDocument jsonDoc(jsonObj);

    //Sending json data to IDE.
    updateAnnotation(jsonDoc.toJson(QJsonDocument::Indented));
}

void ETCodeEditorHandler::updateAnnotation(QString message)
{
    QVariant returnedValue;
    QVariant msg = message;
    QMetaObject::invokeMethod(m_ptrObject, "updateAnnotation",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, msg));
}
