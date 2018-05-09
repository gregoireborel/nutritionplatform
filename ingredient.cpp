#include "ingredient.h"

#include <QJsonObject>
#include <QTextStream>

Ingredient::Ingredient(QObject *parent) : QObject(parent)
{    
}

Ingredient::Ingredient(const QString& name, const QString& uom, int q, int p, int c, int l, QObject* parent) :
    QObject(parent), m_name(name), m_uom(uom), m_quantity(q), m_proteins(p), m_carbohydrates(c), m_lipids(l)
{
}

QString Ingredient::name() const
{
    return m_name;
}

void Ingredient::setName(const QString& name)
{
    if (m_name != name)
    {
        m_name = name;
        emit nameChanged(name);
    }
}

QString Ingredient::uom() const
{
    return m_uom;
}

void Ingredient::setUom(const QString& uom)
{
    if (m_uom != uom)
    {
        m_uom = uom;
        emit uomChanged(uom);
    }
}

int Ingredient::quantity() const
{
    return m_quantity;
}

void Ingredient::setQuantity(const int quantity)
{
    if (m_quantity != quantity)
    {
        m_quantity = quantity;
        emit quantityChanged(quantity);
    }
}

int Ingredient::proteins() const
{
    return m_proteins;
}

void Ingredient::setProteins(const int proteins)
{
    if (m_proteins != proteins)
    {
        m_proteins = proteins;
        emit proteinsChanged(proteins);
    }
}

int Ingredient::carbohydrates() const
{
    return m_carbohydrates;
}

void Ingredient::setCarbohydrates(const int carbohydrates)
{
    if (m_carbohydrates != carbohydrates)
    {
        m_carbohydrates = carbohydrates;
        emit carbohydratesChanged(carbohydrates);
    }
}

int Ingredient::lipids() const
{
    return m_lipids;
}

void Ingredient::setLipids(const int lipids)
{
    if (m_lipids != lipids)
    {
        m_lipids = lipids;
        emit lipidsChanged(lipids);
    }
}

void Ingredient::read(const QJsonObject& json)
{
    // Why no isInt() checker?
    if (json.contains("name") && json["name"].isString())
        m_name = json["name"].toString();
    if (json.contains("uom") && json["uom"].isString())
        m_uom = json["uom"].toString();
    if (json.contains("quantity"))
        m_quantity = json["quantity"].toInt();
    if (json.contains("proteins"))
        m_proteins = json["proteins"].toInt();
    if (json.contains("carbohydrates"))
        m_carbohydrates = json["carbohydrates"].toInt();
    if (json.contains("lipids"))
        m_lipids = json["lipids"].toInt();
}

void Ingredient::write(QJsonObject& json) const
{
    json["name"] = m_name;
    json["uom"] = m_uom;
    json["quantity"] = m_quantity;
    json["proteins"] = m_proteins;
    json["carbohydrates"] = m_carbohydrates;
    json["lipids"] = m_lipids;
}

void Ingredient::print(int indentation) const
{
    const QString indent(indentation * 2, ' ');
  //  QTextStream(stdout) << indent << m_quantity << m_uom << m_name << "P"  "\n";
}
