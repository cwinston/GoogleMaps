#include <exception>
using namespace std;
#include <QObject>
#include <QVariantList>

#ifndef __GeocoderAddressComponent_h__
#define __GeocoderAddressComponent_h__

#define GEO_ADDRESS_COMPONENTS "address_components"
#define GEO_FORMATTED_ADDRESS "formatted_address"
#define GEO_GEOMETRY  "geometry"
#define GEO_PARTIAL_MATCH "partial_match"
#define GEO_PLACE_ID "place_id"
#define GEO_TYPES "types"
#define GEO_ADDY_LONG_NAME "long_name"
#define GEO_ADDY_SHORT_NAME  "short_name"

namespace googleMaps
{
    class GeocoderAddressComponent;
}

namespace googleMaps
{

        class GeocoderAddressComponent : public QObject
		{
            Q_OBJECT
            Q_PROPERTY(QString longName READ getLongName WRITE setLongName NOTIFY longNameChanged)
            Q_PROPERTY(QString shortName READ getShortName WRITE setShortName NOTIFY shortNameChanged)
            Q_PROPERTY(QVariantList types READ exportTypes NOTIFY typesChanged)
            protected:
                QString m_longName;
                QString m_shortName;
                QList<QString> m_types;

            public:
                explicit GeocoderAddressComponent(QObject *parent = 0);
                //copy constructor
                GeocoderAddressComponent(const GeocoderAddressComponent& rhs);

                //assignment operator
                GeocoderAddressComponent& operator=(const GeocoderAddressComponent &rhs);
                virtual ~GeocoderAddressComponent();
                void setLongName(const QString lname);
                QString getLongName() const;
                void setShortName(const QString sname);
                QString getShortName() const;
                void setTypes(const QList<QString> aTypes);
                QList<QString> getTypes() const;
                QVariantList exportTypes();
                void deserialize(const QVariant& data);

            signals:
                void longNameChanged(const QString& lname);
                void shortNameChanged(const QString& sname);
                void typesChanged(const QString& type);
		};
}

Q_DECLARE_METATYPE(googleMaps::GeocoderAddressComponent)

#endif
