#include <exception>
using namespace std;

#ifndef __PathElevationRequest_h__
#define __PathElevationRequest_h__

#include "LatLng.h"

namespace googleMaps
{
	class LatLng;
	class PathElevationRequest;
}

namespace googleMaps
{
    class PathElevationRequest : public QObject
	{
        Q_OBJECT
        protected:
            QList<googleMaps::LatLng> m_path;
            qreal m_samples;

        public:
            PathElevationRequest(QObject *parent = 0);
            //copy constructor
            PathElevationRequest(const PathElevationRequest& rhs);
            ~PathElevationRequest();
            googleMaps::PathElevationRequest& operator=(const googleMaps::PathElevationRequest rhs);
            void addLocation(googleMaps::LatLng position);
            void removeLocation(googleMaps::LatLng location);
            void setPath(QList<googleMaps::LatLng> path);
            QList<googleMaps::LatLng> getPath();
            void setSamples(qreal samples);
            qreal getSamples();
	};
}

#endif
