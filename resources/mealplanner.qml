import QtQuick 2.10
import QtQuick.Controls 1.4

Item
{
    property string title

    Row
    {
        Switch
        {
        }

        Button
        {
            text: "Save"
        }

        Button
        {
            text: "Browse"
        }
    }



}
