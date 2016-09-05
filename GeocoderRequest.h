#include <exception>
using namespace std;

#ifndef __GeocoderRequest_h__
#define __GeocoderRequest_h__

#include "LatLngBounds.h"
#include "LatLng.h"
#include "GeocoderComponentRestrictions.h"

namespace googleMaps
{
    class LatLngBounds;
    class LatLng;
    class GeocoderRequest;
    class GeocoderComponentRestrictions;
}

namespace googleMaps
{
    class GeocoderRequest : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString address READ getAddress WRITE setAddress NOTIFY addressChanged)
        Q_PROPERTY(QString region READ getRegion WRITE setRegion NOTIFY regionChanged)
        Q_PROPERTY(QString placeID READ getPlaceId WRITE setPlaceId NOTIFY placeIDChanged)
  //      Q_PROPERTY(bool navigateUsingLocationName READ navigateUsingLocName NOTIFY navigateUsingLocationNameChanged)
        protected:
            QString m_address;
            googleMaps::LatLngBounds m_bounds;
            QString m_region;
            QString m_placeId;
            googleMaps::LatLng m_location;
            googleMaps::GeocoderComponentRestrictions m_componentRestrictions;

        public:
            explicit GeocoderRequest(QObject *parent = 0);
            //copy constructor
            GeocoderRequest(const GeocoderRequest& rhs);
            virtual ~GeocoderRequest();
            GeocoderRequest googleMaps::GeocoderRequest::operator =(const GeocoderRequest& rhs);
            void setAddress(const QString aAddress);
            QString getAddress() const;
            void setBounds(const googleMaps::LatLngBounds aBounds);
            googleMaps::LatLngBounds getBounds() const;
            void setRegion(const QString aRegion);
            QString getRegion()  const;
            void setPlaceId(const QString aPlaceId);
            QString getPlaceId()  const;
            void setLocation(const googleMaps::LatLng aLocation);
            googleMaps::LatLng getLocation() const;
            void setComponentRestrictions(const googleMaps::GeocoderComponentRestrictions aComponentRestrictions);
            googleMaps::GeocoderComponentRestrictions getComponentRestrictions() const;

        signals:
            void addressChanged(const QString& newAddress);
            void regionChanged(const QString& region);
            void placeIDChanged(const QString& placeId);

    };

}

Q_DECLARE_METATYPE(googleMaps::GeocoderRequest)

#endif
