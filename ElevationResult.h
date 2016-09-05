#include <exception>
using namespace std;

#ifndef __ElevationResult_h__
#define __ElevationResult_h__

#include "LatLng.h"

namespace googleMaps
{
	class LatLng;
	class ElevationResult;
}

namespace googleMaps
{
	/**
     * The result of an ElevationService request, consisting of the set of elevation coordinates and their elevation values.
     * Note that a single request may produce multiple ElevationResults.
	 */
    class ElevationResult : public QObject
	{
        protected:
            qreal m_elevation;
            googleMaps::LatLng m_location;
		/**
         * The distance, in meters, between sample points from which the elevation was interpolated.
         * This property will be missing if the resolution is not known.
         *  Note that elevation data becomes more coarse (larger resolution values) when multiple points are passed.
         *  To obtain the most accurate elevation value for a point, it should be queried independently.
		 */
            qreal m_resolution;

        public:
            explicit ElevationResult(QObject* parent = 0);
            ~ElevationResult();
            ElevationResult(const googleMaps::ElevationResult& rhs);
            googleMaps::ElevationResult& operator=(const googleMaps::ElevationResult& rhs);
            void setElevation(qreal elevation);
            qreal getElevation();
            void setLocation(googleMaps::LatLng location);
            googleMaps::LatLng getLocation();
            void setResolution(qreal resolution);
            qreal getResolution();
	};
}

#endif
