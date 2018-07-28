#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "OpenAndroidGallery.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<OpenAndroidGallery>("Apadana.OpenAndroidGallery", 1, 0, "OpenAndroidGallery");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
