#ifndef TECHNOQTUTILS_H
#define TECHNOQTUTILS_H
#include <QVariantList>

template <typename T>
QVariantList convert2VariantList( const QList<T> &list )
{
    QVariantList newList;
    foreach( const T &item, list )
        newList << item;

    return newList;
}

template <typename T>
QList<T> convertFromVariantList( const QVariantList &list )
{
    QList<T> newList;
    foreach( const T &item, list )
        newList << item;

    return newList;
}

#endif // TECHNOQTUTILS_H
