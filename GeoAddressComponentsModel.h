#include <exception>
using namespace std;

#ifndef __GeoAddressComponentsModel_h__
#define __GeoAddressComponentsModel_h__

#include <QAbstractListModel>
#include "GeocoderAddressComponent.h"

namespace googleMaps
{
	class GeoAddressComponentsModel;
    class GeocoderAddressComponent;
}

namespace googleMaps
{
    class GeoAddressComponentsModel: public QAbstractListModel
	{
        Q_OBJECT
        protected:
            QList<GeocoderAddressComponent*> m_addressComponents;
            virtual QHash<int , QByteArray> roleNames() const;
        public:
            explicit GeoAddressComponentsModel(QObject* parent = 0);
            virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
          //  virtual bool insertRows(int row, int column, QModelIndex parent = QModelIndex());

            virtual bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex());
            virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
            virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	};
}



#endif
