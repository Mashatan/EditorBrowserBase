// Date: 2014
// Author: Ali Mashatan
// Email : ali.mashatan@gmail.com

#pragma once
#include <QDebug>
#include <QObject>
#include <QQuickItem>
#include <ETCodeEditorHandler.h>

class ETCodeEditorExtension: public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QQuickItem* codeEditor MEMBER m_ptrCodeEditor WRITE setCodeEditor)

public:

    ETCodeEditorExtension();
    virtual ~ETCodeEditorExtension();

    void setCodeEditor(QQuickItem* ptrCodeEditor);

    QQuickItem * getCodeEditor();

private:
    QQuickItem* m_ptrCodeEditor;
    ETCodeEditorHandler *m_ptrCodeEditorHandler;
};

