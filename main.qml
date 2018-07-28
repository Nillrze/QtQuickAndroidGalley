import QtQuick 2.11
import QtQuick.Controls 2.2
import QtQuick.Window 2.11
import Apadana.OpenAndroidGallery 1.0

Window {
    visible: true
    width: 320
    height: 568
    title: qsTr("openGallery")

    OpenAndroidGallery{
        id: openG
        onSigSendPath: img.source ="file://" + path
    }

    Button{
        width: 200
        height: 40
        text: "open Gallery"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked : openG.openGallery()
    }

    Image {id:img ; width: 200; height: 200; anchors.centerIn: parent; }

}
