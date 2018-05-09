import QtQuick 2.10

ListView
{
    id: ingredientsListView
    model: ingredientsModel
    anchors.fill: parent

    delegate: Item
    {
        width: 200
        height: 40

        Text { text: model.modelData.name }

        MouseArea
        {
            anchors.fill: parent
            onClicked: ingredientsListView.currentIndex = index
        }
    }

    highlight: Rectangle
    {
        color: 'grey'
        width: 200
    }
    focus: true
    //onCurrentItemChanged: console.log(model.get(ingredientsListView.currentIndex).name + ' selected')
}
