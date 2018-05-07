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

    QList<Ingredient*> ingredients() const;

private:
    void read(const QJsonObject&);
    void write(QJsonObject&) const;

    QList<Ingredient*> m_ingredients;
    QList<Recipe*> m_recipes;
};

#endif // APPLICATIONMANAGER_H
