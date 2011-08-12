/*
qgvdial is a cross platform Google Voice Dialer
Copyright (C) 2010  Yuvraaj Kelkar

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

Contact: yuvraaj@gmail.com
*/

import Qt 4.7

Item {
    id: container
    objectName: "PinSettingsPage"

    height: mainColumn.height + 2
    property real pixHeight: 500

    function setValues(bEnable, pin) {
        console.debug ("QML: Setting Pin settings")
        pinSupport.check = bEnable;
        textPin.text = pin;
    }

    signal sigDone(bool bSave)
    signal sigPinSettingChanges(bool bEnable, string pin)

    property bool bEnable: pinSupport.check

    Column {
        id: mainColumn
        anchors {
            top: parent.top
            left: parent.left
        }
        spacing: 2
        width: parent.width

        RadioButton {
            id: pinSupport
            width: parent.width
            pixelSize: container.pixHeight

            text: "Use PIN for GV dial"
        }// RadioButton (pinSupport)

        Row {
            width: parent.width
            spacing: 2

            opacity: (bEnable ? 1 : 0)

            Text {
                id: lblPin
                text: "Pin:"
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: container.pixHeight
                height: paintedHeight + 2
            }

            MyTextEdit {
                id: textPin
                width: parent.width - lblPin.width
                anchors.verticalCenter: parent.verticalCenter
                text: "0000"
                validator: IntValidator { bottom: 0; top: 9999 }
                pixelSize: container.pixHeight
                height: lblPin.height
            }
        }// Row (pin)

        Row {
            id: rowSaveCancel

            height: btnSave.height
            anchors {
                left: parent.left
                leftMargin: 1
            }
            width: parent.width - 2
            spacing: 2

            MyButton {
                mainText: "Save"
                width: (parent.width / 2) - parent.spacing
                mainPixelSize: container.pixHeight
                height: mainPixelSize * 3 / 2

                onClicked: {
                    container.sigPinSettingChanges (bEnable, textPin.text);
                    container.sigDone(true);
                }
            }//MyButton (Save)

            MyButton {
                mainText: "Cancel"
                width: (parent.width / 2) - parent.spacing
                mainPixelSize: container.pixHeight
                height: mainPixelSize * 3 / 2

                onClicked: container.sigDone(false);
            }//MyButton (Cancel)
        }// Save and cancel buttons
    }// Column
}// Item (top level)