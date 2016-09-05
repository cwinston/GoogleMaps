#include <exception>
using namespace std;
#include <QObject>

#ifndef __GeocoderComponentRestrictions__h__
#define __GeocoderComponentRestrictions__h__

namespace googleMaps
{
     class GeocoderComponentRestrictions;
}

namespace googleMaps
{
        class GeocoderComponentRestrictions : public QObject
		{
            Q_OBJECT
            Q_PROPERTY(QString administrativeArea READ getAdministrativeArea WRITE setAdministrativeArea NOTIFY administrativeAreaChanged)
            Q_PROPERTY(QString country READ getCountry WRITE setCountry NOTIFY countryChanged)
            Q_PROPERTY(QString locality READ getLocality  WRITE setLocality NOTIFY localityChanged)
            Q_PROPERTY(QString postalCode READ getPostalCode WRITE setPostalCode NOTIFY postalCodeChanged)
            Q_PROPERTY(QString route READ getRoute WRITE setRoute NOTIFY routeChanged)
            protected:
                QString m_administrativeArea;
                QString m_country;
                QString m_locality;
                QString m_postalCode;
                QString m_route;


            public:
                explicit GeocoderComponentRestrictions(QObject* parent = 0);
                //copy constructor
                GeocoderComponentRestrictions(const GeocoderComponentRestrictions& rhs);
                //assignment operator
                GeocoderComponentRestrictions& operator=(const GeocoderComponentRestrictions &rhs);
                virtual ~GeocoderComponentRestrictions();
                void setAdministrativeArea(const  QString aAdministrativeArea);
                QString getAdministrativeArea() const ;
                void setCountry(const QString aCountry);
                QString getCountry() const;
                void setLocality(const QString aLocality);
                QString getLocality() const;
                void setPostalCode(const QString aPostalCode);
                QString getPostalCode() const ;
                void setRoute(const QString aRoute);
                QString getRoute() const;
                void deserialize(const QVariantMap& data);

            signals:
                void administrativeAreaChanged(bool modified);
                void countryChanged(bool modified);
                void localityChanged(bool modified);
                void postalCodeChanged(bool modified);
                void routeChanged(bool modified);
		};
}

#endif
