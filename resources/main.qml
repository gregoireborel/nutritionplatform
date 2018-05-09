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
        anchors.top: parent.top
        anchors.topMargin: 40
        anchors.left: parent.left
        anchors.leftMargin: 20
    }

    WeekPlanner
    {
        width: 700
        height: 500
        anchors.top: parent.top
        anchors.topMargin: 40
        anchors.horizontalCenter: parent.horizontalCenter
    }

    RecipesList
    {
        width: 200
        anchors.top: parent.top
        anchors.topMargin: 40
        anchors.right: parent.right
        anchors.rightMargin: 20
    }

}
