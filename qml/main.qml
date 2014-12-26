// Date: 2014
// Author: Ali Mashatan
// Email : ali.mashatan@gmail.com

import QtQuick 2.0
import QtQuick.Controls 1.0
import QtWebKit 3.0
import QtWebKit.experimental 1.0
import ETCodeEditorExtension 1.0

ScrollView {
    width: 1280
    height: 720
    WebView {
        experimental.preferences.navigatorQtObjectEnabled: true
        experimental.onMessageReceived: {
          onEventHandler(message.data)
        }
        signal onEventHandler(string message)
        id: editorBrowser
        url: "qrc:///html/editor_webbase.html"
        anchors.fill: parent

        function updateAnnotation(message) {
            editorBrowser.experimental.postMessage(message)
        }
    }
    ETCodeEditorExtension {
        codeEditor: editorBrowser
    }
}
