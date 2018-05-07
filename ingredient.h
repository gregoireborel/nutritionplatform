#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QObject>

class Ingredient : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString uom READ uom WRITE setUom NOTIFY uomChanged)
    Q_PROPERTY(int quantity READ quantity WRITE setQuantity NOTIFY quantityChanged)
    Q_PROPERTY(int proteins READ proteins WRITE setProteins NOTIFY proteinsChanged)
    Q_PROPERTY(int carbohydrates READ carbohydrates WRITE setCarbohydrates NOTIFY carbohydratesChanged)
    Q_PROPERTY(int lipids READ lipids WRITE setLipids NOTIFY lipidsChanged)

public:
    explicit Ingredient(QObject* parent = nullptr);
    Ingredient(const QString&, const QString&, int, int, int, int);

    QString name() const;
    void setName(const QString&);

    QString uom() const;
    void setUom(const QString&);

    int quantity() const;
    void setQuantity(const int);

    int proteins() const;
    void setProteins(const int);

    int carbohydrates() const;
    void setCarbohydrates(const int);

    int lipids() const;
    void setLipids(const int);

    void read(const QJsonObject&);
    void write(QJsonObject&) const;

    void print(int indentation = 0) const;

signals:
    void nameChanged(const QString&);
    void uomChanged(const QString&);
    void quantityChanged(const int);
    void proteinsChanged(const int);
    void carbohydratesChanged(const int);
    void lipidsChanged(const int);

private:
    QString m_name;
    QString m_uom;
    int m_quantity;
    int m_proteins;
    int m_carbohydrates;
    int m_lipids;
};

#endif // INGREDIENT_H
