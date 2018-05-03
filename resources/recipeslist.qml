import QtQuick 2.10

ListView
{
    id: recipesListView

    ListModel
    {
        id: model
        ListElement {
            name:'abc'
            number:'123'
        }
        ListElement {
            name:'efg'
            number:'456'
        }
        ListElement {
            name:'xyz'
            number:'789'
        }
    }

    model: model

    delegate: Component {
        Item {
            width: parent.width
            height: 40
            Column {
                Text { text: 'Name:' + name }
                Text { text: 'Number:' + number }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: recipesListView.currentIndex = index
            }
        }
    }
    highlight: Rectangle {
        color: 'grey'
        Text {
            anchors.centerIn: parent
            text: 'Hello ' + model.get(recipesListView.currentIndex).name
            color: 'white'
        }
    }
    focus: true
    onCurrentItemChanged: console.log(model.get(recipesListView.currentIndex).name + ' selected')
}
