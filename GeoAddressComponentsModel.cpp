#include <exception>
using namespace std;

#include "GeoAddressComponentsModel.h"
#include <QAbstractListModel>

googleMaps::GeoAddressComponentsModel::GeoAddressComponentsModel(QObject* parent): QAbstractListModel(parent)
{
}

QVariant googleMaps::GeoAddressComponentsModel::data(const QModelIndex& index, int role) const
{
    if (index.row() < 0 || index.row() >= m_addressComponents.count())
        return QVariant();

    const GeocoderAddressComponent* sData = m_addressComponents[index.row()];

    return QVariant();
}

//bool googleMaps::GeoAddressComponentsModel::insertRows(int row, int column, QModelIndex parent)
//{
//    beginInsertRows(QModelIndex(), rowCount(), rowCount());
//     //   m_addressComponents << data;
//        endInsertRows();
//}

QHash<int, QByteArray> googleMaps::GeoAddressComponentsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

           return roles;
}

bool googleMaps::GeoAddressComponentsModel::removeRows(int row, int count, const QModelIndex& parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    while (count--) m_addressComponents.takeAt(row);
    endRemoveRows();
    return true;
}

int googleMaps::GeoAddressComponentsModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_addressComponents.count();
}

bool googleMaps::GeoAddressComponentsModel::setData(const QModelIndex &index, const QVariant &value, int role  )
{
    role = Qt::EditRole;
    if (index.isValid() && role == Qt::EditRole)
    {
        GeocoderAddressComponent* component = m_addressComponents.at(index.row());
       // component = value;
        m_addressComponents.replace(index.row(), component);
        emit dataChanged(index, index);
        return true;
    }
    else
    {
        return false;
    }
}
