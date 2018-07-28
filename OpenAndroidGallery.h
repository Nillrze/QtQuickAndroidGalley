#ifndef OPENANDROIDGALLERY_H
#define OPENANDROIDGALLERY_H

#include <QObject>

class OpenAndroidGallery : public QObject
{
    Q_OBJECT

 //   Q_PROPERTY(void name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit OpenAndroidGallery(QObject *parent = nullptr);

signals:

    void sigSendPath(QString path);

public slots:

    void openGallery();

};

#endif // OPENANDROIDGALLERY_H
