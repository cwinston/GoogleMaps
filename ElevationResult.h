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
        Q_PROPERTY(qreal elevation READ getElevation WRITE setElevation NOTIFY elevationChanged)
        Q_PROPERTY(googleMaps::LatLng location READ getLocation WRITE setLocation NOTIFY locationChanged)
        Q_PROPERTY(qreal resolution READ getResolution WRITE setResolution NOTIFY resolutionChanged)
        Q_OBJECT
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
            virtual ~ElevationResult();
            ElevationResult(const googleMaps::ElevationResult& rhs);
            googleMaps::ElevationResult& operator=(const googleMaps::ElevationResult& rhs);
            qreal getElevation() const;
            googleMaps::LatLng getLocation() const;
            qreal getResolution() const;

        public slots:
            void setResolution(qreal resolution);
            void setElevation(qreal elevation);
            void setLocation(googleMaps::LatLng location);

        signals:
            void elevationChanged();
            void locationChanged();
            void resolutionChanged();
	};

        Q_DECLARE_METATYPE(googleMaps::ElevationResult)
}

#endif
