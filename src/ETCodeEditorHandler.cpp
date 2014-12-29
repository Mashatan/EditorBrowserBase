// Date: 2014
// Author: Ali Mashatan
// Email : ali.mashatan@gmail.com

#include <ETCodeEditorHandler.h>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>


ETCodeEditorHandler::ETCodeEditorHandler(QQuickWebView * ptrwebView)
{
    m_ptrWebView = ptrwebView;
    bool result;
    result = QObject::connect(ptrwebView->experimental(), SIGNAL(messageReceived(const QVariantMap&)),
                   this, SLOT(doMessageReceived(const QVariantMap&)));
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


void ETCodeEditorHandler::doMessageReceived(const QVariantMap& message)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(message.value("data").toByteArray());
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
        appendAnnotation(2, 9, 19, "function <span style=\"color:blue;\">myFunction</span> unknown.");
        appendAnnotation(4, 4, 12, "variable <span style=\"color:blue;\">document</span> unknown.");
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
    m_ptrWebView->experimental()->postMessage(message);
}
