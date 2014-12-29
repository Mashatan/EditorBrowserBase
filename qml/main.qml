// Date: 2014
// Author: Ali Mashatan
// Email : ali.mashatan@gmail.com

import QtQuick 2.0
import QtQuick.Controls 1.0
import QtWebKit 3.0
import QtWebKit.experimental 1.0
import ETCodeEditorExtension 1.0

Rectangle {
    width: 1280
    height: 720
    WebView {
        focus: true
        experimental.preferences.navigatorQtObjectEnabled: true
        signal onEventHandler(string message)
        id: editorBrowser
        url: "qrc:///html/editor_webbase.html"
        anchors.fill: parent
    }
    ETCodeEditorExtension {
        codeEditor: editorBrowser
    }
}
