// Date: 2014
// Author: Ali Mashatan
// Email : ali.mashatan@gmail.com

#include <QApplication>
#include <QQuickView>
#include <ETCodeEditorExtension.h>
#include <QtWebKitWidgets/QWebView>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QtQml>

#include <iostream>

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    QQuickView view;

    qmlRegisterType<ETCodeEditorExtension>("ETCodeEditorExtension", 1, 0, "ETCodeEditorExtension");
    view.setSource(QUrl("qrc:///qml/main.qml"));
    view.show();

    return app.exec();
}
