#include <exception>
using namespace std;

#ifndef __SphericalGeometry_h__
#define __SphericalGeometry_h__

#include "LatLng.h"


namespace googleMaps
{
	class LatLng;
	class SphericalGeometry;
}

namespace googleMaps
{

    class SphericalGeometry : public QObject
	{
        Q_OBJECT
        Q_PROPERTY(googleMaps::LatLng positionResult READ getPositionResults NOTIFY positionResultReceived)
        Q_PROPERTY(qreal distanceResult READ getDistanceResult NOTIFY distanceResultReceived)
        protected:
            qreal m_distanceResult;
            googleMaps::LatLng m_positionResult;

        public:
            explicit SphericalGeometry(QObject* parent = 0);
            SphericalGeometry(const googleMaps::SphericalGeometry &rhs, QObject* parent = 0);

            /// <summary>
            ///
            /// Return Value:  number
            /// Return unit: meters
            /// Returns the area of a closed path. The computed area uses the same units as the radius. The radius defaults to the Earth's radius in meters, in which case the area is in square meters.
            /// </summary>
            void computeArea(QList<googleMaps::LatLng> path);

            /// <summary>
            ///
            /// Return Value:  number
            /// Returns the distance, in meters, between two LatLngs. You can optionally specify a custom radius. The radius defaults to the radius of the Earth.
            /// </summary>
            void computeDistanceBetween(const googleMaps::LatLng from, const googleMaps::LatLng to);

            /// <summary>
            ///
            /// Return Value:  number
            /// Returns the heading from one LatLng to another LatLng. Headings are expressed in degrees clockwise from North within the range [-180,180).
            /// </summary>
            void computeHeading(const googleMaps::LatLng from, const googleMaps::LatLng to);

            /// <summary>
            ///
            /// Return Value:  number
            /// Returns the length of the given path.
            /// </summary>
            void computeLength(const QList<googleMaps::LatLng> path);

            /// <summary>
            ///
            /// Return Value:  LatLng
            /// Returns the LatLng resulting from moving a distance from an origin in the specified heading (expressed in degrees clockwise from north).
            /// </summary>
            void computeOffset(const googleMaps::LatLng from, const qreal distance, const qreal heading);

            /// <summary>
            /// Returns the location of origin when provided with a LatLng destination, meters travelled and original heading. Headings are expressed in degrees clockwise from North. This function returns null when no solution is available.
            /// </summary>
            void computeOffsetOrigin(const googleMaps::LatLng to, const qreal distance, const qreal heading);

            /// <summary>
            /// Returns the LatLng which lies the given fraction of the way between the origin LatLng and the destination LatLng.
            /// </summary>
            void interpolate(const googleMaps::LatLng from, const googleMaps::LatLng to, const qreal fraction);
            qreal getDistanceResult() const;            
            googleMaps::LatLng getPositionResults() const;

         signals:
            void positionResultReceived();
            void distanceResultReceived();
            void computeOffsetOriginRequest(qreal toLat, qreal toLng, qreal distance, qreal heading);
            void interpolateRequest(qreal fromLat, qreal fromLng, qreal toLat, qreal toLng, qreal fraction);
            void computeOffsetRequest(qreal fromLat, qreal fromLng, qreal distance, qreal heading);
            //void computeLengthRequest(QVariantList path);
            void computeHeadingRequest(qreal fromLat, qreal fromLng, qreal toLat, qreal toLng);
            void computeDistanceBetweenRequest(qreal fromLat, qreal fromLng, qreal toLat, qreal toLng);
            //void computeAreaRequest(QVariantList path);

         public slots:
            void setPositionResult(const googleMaps::LatLng aPositionResult);
            void setDistanceResult(const qreal aDistanceResult);
	};
}

Q_DECLARE_METATYPE(googleMaps::SphericalGeometry)
#endif
