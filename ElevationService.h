#include <exception>
using namespace std;

#ifndef __ElevationService_h__
#define __ElevationService_h__

#include "PathElevationRequest.h"
#include "LocationElevationRequest.h"
#include "ElevationResult.h"
#include "LatLng.h"

#define INVALID_REQUEST "INVALID_REQUEST"
#define STATUS_OK "STATUS_OK"
#define OVER_QUERY_LIMIT "OVER_QUERY_LIMIT"
#define REQUEST_DENIED "REQUEST_DENIED"
#define UNKNOWN_ERROR "UNKNOWN_ERROR"
#define PATH_REQUEST "path"
#define LOCATION_REQUEST "location"

namespace googleMaps
{
	class PathElevationRequest;
	class LocationElevationRequest;
	class ElevationResult;
	class LatLng;
	class ElevationService;
}

namespace googleMaps
{
    enum EElevationStatus
    {
        ES_INVALID_REQUEST,
        ES_STATUS_OK,
        ES_OVER_QUERY_LIMIT,
        ES_REQUEST_DENIED,
        ES_UNKNOWN_ERROR
    };

    class ElevationService: public QObject
	{
        Q_OBJECT
    protected:
            googleMaps::PathElevationRequest m_pathRequest;
            googleMaps::LocationElevationRequest m_locationRequest;
            QVariantList m_results;
            QString m_requestType;
        public:
            explicit ElevationService(QObject* parent = 0);
            ElevationService(const googleMaps::ElevationService& rhs);
            void getElevationAlongPath(const googleMaps::PathElevationRequest request);
            void getElevationForLocations(const googleMaps::LocationElevationRequest request);
            googleMaps::PathElevationRequest getLastPathElevationRequest() const;
            googleMaps::LocationElevationRequest getLastLocationElevationRequest() const;
            QVariantList& getElevationResults();
            static googleMaps::PathElevationRequest createPathElevationRequest(QList<googleMaps::LatLng> paths, qreal samples);
            static googleMaps::LocationElevationRequest createLocationElevationRequest(QList<googleMaps::LatLng> locations);

        public slots:
            void updateElevationResults(QVariantList results, QString status);

        signals:
            void elevationResultsReceived(QVariantList results, QString status);
            void requestElevationPath(googleMaps::PathElevationRequest request);
            void requestElevation4Location(googleMaps::LocationElevationRequest request);
	};
    Q_DECLARE_METATYPE(googleMaps::ElevationService)
}

#endif
