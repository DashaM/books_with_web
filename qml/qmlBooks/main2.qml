//import QtQuick 1.0
import Qt 4.7


Rectangle {
     id: rectangle1
    width: 600
    height: 300
    anchors.fill: parent



    gradient: Gradient {
    GradientStop {
    position: 0
    color: "#FF66FF"

    }

    GradientStop {
    position: 1
    color: "#FFFF66"
    }
    }


    //Кнопка
    Rectangle {
        id: button //Имя кнопки

        //Размещаем в центре
        x: 494
        y: 11

        //Размеры кнопки
        width: 100
        height: 30

        //Цвет кнопки
       color: "gray"
        //color: button.pressed ? "gray" : "lightgreen"

       radius: 6
       border.width: 3
       border.color: "#f5f9f4"


        //Текст кнопки
        Text {
            id: buttonLabel
            text: "Пуск"
            anchors.centerIn: parent;
        }





        //Действие мыши
        MouseArea {
            anchors.fill: parent
                        id: mouseArea
                        x: 0
                        y: 0
                        anchors.rightMargin: 0
                        anchors.bottomMargin: 0
                        anchors.leftMargin: 0
                        anchors.topMargin: 0
                        hoverEnabled: true
                        onEntered: parent.border.color = "red"
                        onExited: parent.border.color = "white"
                        //При нажатии вызвать фугкцию window.FunctionC()
                        onClicked:{ window.FunctionC()
                        }





        }

    }

    //Строка ввода
        Rectangle {
            id: textinputRect //Имя строки ввода

            //Размещаем ниже
            x: 494
            y: 76

            //Размеры строки ввода
            width: 100
            height: 18

            //цвет строки ввода
            color: "gray"

            radius: 6
            border.width: 3
            border.color: "#f5f9f4"

            TextInput {
                id: textinput
                x: 4
                y: 2
                objectName: "textinput"
                color: "#151515";
                selectionColor: "blue"
                font.pixelSize: 12;
                width: parent.width-4
                anchors.centerIn: parent
                focus: true
                text:"file:///G:/lib.htm"
                anchors.verticalCenterOffset: 0
                anchors.horizontalCenterOffset: 2
                }
        }

        ListView {
            id: list_view1
            x: 15
            y: 19
            width: 150
            height: 236
            delegate: Item {
                x: 5
                height: 40
                Row {
                    id: row1
                    spacing: 10
                    Rectangle {
                        width: 40
                        height: 40
                        color: "black"
                    }

                    Text {
                        text: modelData;
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                }
            }
          //  model: model2
        }







}



