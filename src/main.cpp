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

#if 0
    Sample sample;
    view.engine()->rootContext()->setContextProperty("cppClass",&sample);
#endif

    qmlRegisterType<ETCodeEditorExtension>("ETCodeEditorExtension", 1, 0, "ETCodeEditorExtension");


    view.setSource(QUrl("qrc:///qml/main.qml"));
    view.show();

#if 0
    QObject *object = (QObject*)view.rootObject();


    QVariant returnedValue;
    QVariant msg = "Hello from C++";
    QMetaObject::invokeMethod(object, "myQmlFunction",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, msg));
#endif
    return app.exec();
}
