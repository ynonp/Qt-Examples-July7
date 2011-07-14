#include "shoppingitem.h"
#include <QDebug>

ShoppingItem::ShoppingItem()
{
}

ShoppingItem::ShoppingItem(const ShoppingItem &other)
{
    *this = other;
}

ShoppingItem::ShoppingItem(const QString &name,
             quint32        price,
             int            quantity)
{
    iName = name;
    iPrice = price;
    iQuantity = quantity;
}



const ShoppingItem &ShoppingItem::operator=(const ShoppingItem &other)
{
    iName     = other.getName();
    iPrice    = other.getPrice();
    iQuantity = other.getQuantity();
    return *this;
}

bool ShoppingItem::operator==(const ShoppingItem &other)
{
    return ( ( iName     == other.getName() ) &&
             ( iPrice    == other.getPrice() ) &&
             ( iQuantity == other.getQuantity() ) );
}

void ShoppingItem::setName(const QString &name)
{
    iName = name;
}

void ShoppingItem::setPrice(quint32 price)
{
    iPrice = price;
}

void ShoppingItem::setQuantity(int qty)
{
    iQuantity = qty;
}

const QString &ShoppingItem::getName() const
{
    return iName;
}

quint32 ShoppingItem::getPrice() const
{
    return iPrice;
}

int ShoppingItem::getQuantity() const
{
    return iQuantity;
}

QDebug operator<<(QDebug d, const ShoppingItem &item)
{
    d << item.getName() << endl;
    d << "Cost per unit = " << item.getPrice() << endl;
    d << "Qty: " << item.getQuantity() << endl;
    d << "Total: " << item.getQuantity() * item.getPrice() << endl;

    return d;
}


QDataStream &operator<<(QDataStream &out, const ShoppingItem &item)
{
    out << item.getName();
    out << item.getPrice();
    out << item.getQuantity();

    return out;
}

QDataStream &operator>>(QDataStream &in,  ShoppingItem &item)
{
    QString name;
    quint32 price;
    int qty;

    in >> name;
    in >> price;
    in >> qty;

    item.setName(name);
    item.setPrice(price);
    item.setQuantity(qty);
    return in;
}

