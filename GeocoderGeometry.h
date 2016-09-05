#include <exception>
using namespace std;

#ifndef __GeocoderGeometry_h__
#define __GeocoderGeometry_h__

#include "LatLngBounds.h"
#include "LatLng.h"

#define GEO_GEOMETRY_BOUNDS "bounds"
#define GEO_GEOMETRY_LOCATION "location"
#define GEO_GEOMETRY_LOC_TYPE  "location_type"
#define GEO_GEOMETRY_VIEWPORT "viewport"

#define GEO_LOCATION_APPROX "APPROXIMATE"
#define GEO_LOCATION_GEOMETRIC_CENTER "GEOMETRIC_CENTER"
#define GEO_LOCATION_RANGE_INTERPOLATED "RANGE_INTERPOLATED"
#define GEO_LOCATION_ROOFTOP "ROOFTOP"



namespace googleMaps
{
    class LatLngBounds;
    class LatLng;
    // enum GeocoderLocationType;
    class GeocoderGeometry;
}


namespace googleMaps
{
    enum EGeocoderLocationType
    {
        APPROXIMATE,
        GEOMETRIC_CENTER,
        RANGE_INTERPOLATED,
        ROOFTOP
    };

    class GeocoderGeometry : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(LatLngBounds bounds READ getBounds WRITE setBounds NOTIFY boundsChanged)
        Q_PROPERTY(LatLng location READ getLocation WRITE setLocation NOTIFY locationChanged)
        Q_PROPERTY(EGeocoderLocationType locationType READ getLocationType WRITE setLocationType NOTIFY locationTypeChanged)
        Q_PROPERTY(LatLngBounds viewport READ getViewport WRITE setViewport NOTIFY viewportChanged)
        Q_ENUMS(EGeocoderLocationType)

        protected:
            googleMaps::LatLngBounds m_bounds;
            googleMaps::LatLng m_location;
            googleMaps::EGeocoderLocationType m_locationType;
            googleMaps::LatLngBounds m_viewport;


        public:
            explicit GeocoderGeometry(QObject* parent = 0);


            //copy constructor
             GeocoderGeometry(const GeocoderGeometry& rhs);

            //assignment operator
            GeocoderGeometry& operator=(const GeocoderGeometry &rhs);

            virtual ~GeocoderGeometry();
            void setBounds(const googleMaps::LatLngBounds aBounds);
            LatLngBounds getBounds() const;
            void setLocation(const googleMaps::LatLng aLocation);
            googleMaps::LatLng getLocation() const;
            void setLocationType(const googleMaps::EGeocoderLocationType locationType);
            googleMaps::EGeocoderLocationType getLocationType() const;
            void setViewport(const googleMaps::LatLngBounds aViewport);
            LatLngBounds getViewport()const;
            void deserialize(const QVariantMap& data);

        signals:
            void boundsChanged(bool modified);
            void locationChanged(bool modified);
            void locationTypeChanged(bool modified);
            void viewportChanged(bool modified);
    };
}

    Q_DECLARE_METATYPE(googleMaps::GeocoderGeometry)
#endif
