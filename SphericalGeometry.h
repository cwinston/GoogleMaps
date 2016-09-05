#include <exception>
using namespace std;

#ifndef __SphericalGeometry_h__
#define __SphericalGeometry_h__

#include "LatLng.h"


namespace googleMaps
{
	class LatLng;
	class SphericalGeometry;
   // class AbstractGoogleMapsService;
}

namespace googleMaps
{
    class SphericalGeometry : public QObject
	{
        Q_OBJECT
        protected:
            qreal m_distanceResult;
            googleMaps::LatLng m_positionResult;

        public:
            SphericalGeometry(QObject* parent = 0);
            ~SphericalGeometry();

            /// <summary>
            ///
            /// Return Value:  number
            /// Return unit: meters
            /// Returns the area of a closed path. The computed area uses the same units as the radius. The radius defaults to the Earth's radius in meters, in which case the area is in square meters.
            /// </summary>
            qreal computeArea(QList<googleMaps::LatLng> path);

            /// <summary>
            ///
            /// Return Value:  number
            /// Returns the distance, in meters, between two LatLngs. You can optionally specify a custom radius. The radius defaults to the radius of the Earth.
            /// </summary>
            qreal computeDistanceBetween(googleMaps::LatLng from, googleMaps::LatLng to);

            /// <summary>
            ///
            /// Return Value:  number
            /// Returns the heading from one LatLng to another LatLng. Headings are expressed in degrees clockwise from North within the range [-180,180).
            /// </summary>
            qreal computeHeading(googleMaps::LatLng from, googleMaps::LatLng to);

            /// <summary>
            ///
            /// Return Value:  number
            /// Returns the length of the given path.
            /// </summary>
            qreal computeLength(QList<googleMaps::LatLng> path);

            /// <summary>
            ///
            /// Return Value:  LatLng
            /// Returns the LatLng resulting from moving a distance from an origin in the specified heading (expressed in degrees clockwise from north).
            /// </summary>
            googleMaps::LatLng computeOffset(googleMaps::LatLng from, qreal distance, qreal heading);

            /// <summary>
            /// Returns the location of origin when provided with a LatLng destination, meters travelled and original heading. Headings are expressed in degrees clockwise from North. This function returns null when no solution is available.
            /// </summary>
            googleMaps::LatLng computeOffsetOrigin(googleMaps::LatLng to, qreal distance, qreal heading);

            /// <summary>
            /// Returns the LatLng which lies the given fraction of the way between the origin LatLng and the destination LatLng.
            /// </summary>
            googleMaps::LatLng interpolate(googleMaps::LatLng from, googleMaps::LatLng to, qreal fraction);
            void setDistanceResult(const qreal aDistanceResult);
            qreal getDistanceResult() const;
            void setPositionResult(const googleMaps::LatLng aPositionResult);
            googleMaps::LatLng getPositionResult() const;
	};
}

#endif
