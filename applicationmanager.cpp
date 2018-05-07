#include "applicationmanager.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

ApplicationManager::ApplicationManager()
{

}

bool ApplicationManager::readIngredientsFile(const QString& path)
{
    QFile loadFile(path);

    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    read(loadDoc.object());
    return true;
}

QList<Ingredient*> ApplicationManager::ingredients() const
{
    return m_ingredients;
}

void ApplicationManager::read(const QJsonObject& json)
{
    if (json.contains("ingredients") && json["ingredients"].isArray())
    {
        QJsonArray ingredientsArray = json["ingredients"].toArray();

        m_ingredients.reserve(ingredientsArray.size());

        for (int ingredientsIndex = 0; ingredientsIndex < ingredientsArray.size(); ++ingredientsIndex)
        {
            QJsonObject ingredientsObject = ingredientsArray[ingredientsIndex].toObject();
            Ingredient* ingredient = new Ingredient;
            ingredient->read(ingredientsObject);
            m_ingredients.append(ingredient);
        }
    }
}

void ApplicationManager::write(QJsonObject& json) const
{
    QJsonArray ingredientArray;

    foreach (const Ingredient* ingredient, m_ingredients)
    {
        QJsonObject ingredientObject;
        ingredient->write(ingredientObject);
        ingredientArray.append(ingredientObject);
    }
    json["ingredients"] = ingredientArray;
}
