import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 1280
    height: 720
    title: qsTr("Nutrition Plaform")
    color: "#d7d6d5"

    IngredientsList
    {
        width: 200
        anchors.left: parent.left
        anchors.leftMargin: 20
    }

    WeekPlanner
    {
        width: 500
        anchors.horizontalCenter: parent.horizontalCenter
    }

    RecipesList
    {
        width: 200
        anchors.right: parent.right
        anchors.rightMargin: 20
    }

}
