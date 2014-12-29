// Date: 2014
// Author: Ali Mashatan
// Email : ali.mashatan@gmail.com

#include <ETCodeEditorExtension.h>
#include <iostream>
#include <private/qquickwebview_p.h>
#include <private/qquickwebpage_p.h>

ETCodeEditorExtension::ETCodeEditorExtension()
{
    m_ptrCodeEditorHandler = NULL;
}

ETCodeEditorExtension::~ETCodeEditorExtension()
{
    if (m_ptrCodeEditorHandler != NULL)
    {
        delete m_ptrCodeEditorHandler;
    }
}

void ETCodeEditorExtension::setCodeEditor(QQuickItem *ptrCodeEditor)
{
    m_ptrCodeEditor = ptrCodeEditor;
    QQuickWebView * webView = dynamic_cast<QQuickWebView*>(ptrCodeEditor);
    webView->experimental()->setFlickableViewportEnabled(false);
    m_ptrCodeEditorHandler = new ETCodeEditorHandler(webView);
}

QQuickItem *ETCodeEditorExtension::getCodeEditor()
{
    return m_ptrCodeEditor;
}

