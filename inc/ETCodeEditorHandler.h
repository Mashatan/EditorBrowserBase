// Date: 2014
// Author: Ali Mashatan
// Email : ali.mashatan@gmail.com

#pragma once
#include <QDebug>
#include <QObject>
#include <private/qquickwebview_p.h>

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
    ETCodeEditorHandler(QQuickWebView* ptrWebView);
    void appendAnnotation(int line, int start, int end, QString text);
    void clearAnnotation();

public slots:
    void doMessageReceived(const QVariantMap&);

private slots:
    void doSimulationCompileTimer();

private:

    QVector <Item> m_List;
    enum eventHandlerEnum
    {
        ehChange=100,
    };

    QQuickWebView *m_ptrWebView;
    void updateAnnotation(QString message);
};
