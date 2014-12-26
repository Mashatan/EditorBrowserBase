// Date: 2014
// Author: Ali Mashatan
// Email : ali.mashatan@gmail.com

#include <ETCodeEditorExtension.h>
#include <iostream>


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
    m_ptrCodeEditorHandler = new ETCodeEditorHandler(m_ptrCodeEditor);
}

QQuickItem *ETCodeEditorExtension::getCodeEditor()
{
    return m_ptrCodeEditor;
}

