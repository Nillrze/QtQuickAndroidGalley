#include "OpenAndroidGallery.h"

#include <QtAndroidExtras/QAndroidJniObject>
#include <QCoreApplication>
#include <QFile>
#include <QDebug>

QString selectedFileName;

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
Java_org_qtproject_example_QtAndroidGallery_fileSelected(JNIEnv */*env*/,
                                                             jobject /*obj*/,
                                                             jstring results)
{
    selectedFileName = QAndroidJniObject(results).toString();
}

#ifdef __cplusplus
}
#endif


OpenAndroidGallery::OpenAndroidGallery(QObject *parent) : QObject(parent)
{

}

void OpenAndroidGallery::openGallery()
{
    selectedFileName = "#";
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/QtAndroidGallery",
                                              "openAnImage",
                                              "()V");

    while(selectedFileName == "#")
        qApp->processEvents();

    if(QFile(selectedFileName).exists())
    {
        qDebug() << "selectedFileName   ;;  " <<  selectedFileName ;
        emit sigSendPath(selectedFileName);
    }

}
