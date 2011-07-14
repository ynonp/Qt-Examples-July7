#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include <QString>
#include <QMetaType>
#include <QDataStream>

class ShoppingItem
{
public:
    explicit ShoppingItem();
    ShoppingItem(const ShoppingItem &other);
    ShoppingItem(const QString &name,
                 quint32        price,
                 int            quantity);


    const ShoppingItem &operator=(const ShoppingItem &other);

    bool operator==(const ShoppingItem &other);

    void setName(const QString &name);
    void setPrice(quint32 price);
    void setQuantity(int qty);

    const QString &getName() const;
    quint32        getPrice() const;
    int            getQuantity() const;

private:
    QString iName;
    quint32 iPrice;
    int     iQuantity;
};

QDebug operator<<(QDebug d, const ShoppingItem &item);
QDataStream &operator<<(QDataStream &out, const ShoppingItem &item);
QDataStream &operator>>(QDataStream &in,  ShoppingItem &item);

Q_DECLARE_METATYPE(ShoppingItem)

#endif // SHOPPINGITEM_H
