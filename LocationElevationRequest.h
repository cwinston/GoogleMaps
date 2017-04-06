#include <exception>
using namespace std;

#ifndef __LocationElevationRequest_h__
#define __LocationElevationRequest_h__

#include "LatLng.h"

namespace googleMaps
{
	class LatLng;
    //class LocationElevationRequest;
}

namespace googleMaps
{
    class LocationElevationRequest : public QObject
	{
        Q_OBJECT
        protected:
            QVariantList m_locations;

        public:
            explicit LocationElevationRequest(QObject *parent = 0);
            LocationElevationRequest(const LocationElevationRequest& rhs);
            googleMaps::LocationElevationRequest& operator=(const googleMaps::LocationElevationRequest rhs);
            virtual ~LocationElevationRequest();
            void addLocation(googleMaps::LatLng location);
            QVariantList getLocations() const;
            void clearLocations();
        public slots:
            void updateLocations(const QVariantList locations);

        signals:
            void locationsChanged();
	};
    Q_DECLARE_METATYPE(googleMaps::LocationElevationRequest)
}

#endif
