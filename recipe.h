#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>

class Recipe : public QObject
{
    Q_OBJECT
public:
    explicit Recipe(QObject *parent = nullptr);

signals:

public slots:
};

#endif // RECIPE_H