// Date: 2014
// Author: Ali Mashatan
// Email : ali.mashatan@gmail.com

#pragma once
#include <QDebug>
#include <QObject>

class ETCodeEditorHandler:public QObject
{
    Q_OBJECT
public:
    struct Item
    {
        int line;
        int start;
        int end;
        QString text;
    };
    ETCodeEditorHandler(QObject* obj);
    void appendAnnotation(int line, int start, int end, QString text);
    void clearAnnotation();

public slots:
    void doEventHandler(const QString message);

private slots:
    void doSimulationCompileTimer();

private:

    QVector <Item> m_List;
    enum eventHandlerEnum
    {
        ehChange=100,
    };

    QObject *m_ptrObject;
    void updateAnnotation(QString message);
};
