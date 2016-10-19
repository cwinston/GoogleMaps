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
            QList<googleMaps::LatLng> m_locations;

        public:
            explicit LocationElevationRequest(QObject *parent = 0);
            LocationElevationRequest(const LocationElevationRequest& rhs);
            ~LocationElevationRequest();
            void addLocation(googleMaps::LatLng location);
            void removeLocation(googleMaps::LatLng location);
            QList<googleMaps::LatLng> getLocations() const;
	};
}

#endif
