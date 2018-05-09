#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "ingredient.h"
#include "recipe.h"

#include <QVector>
#include <QJsonObject>

class ApplicationManager
{
public:
    ApplicationManager();

    bool readIngredientsFile(const QString& path = "");
    bool readRecipesFile(const QString& path = "");

    QList<QObject*> ingredients();

private:
    void read(const QJsonObject&);
    void write(QJsonObject&) const;

    QList<QObject*> m_ingredients;
    QList<Recipe*> m_recipes;
};

#endif // APPLICATIONMANAGER_H
