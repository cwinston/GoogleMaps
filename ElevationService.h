#include <exception>
using namespace std;

#ifndef __ElevationService_h__
#define __ElevationService_h__

#include "PathElevationRequest.h"
#include "LocationElevationRequest.h"
#include "ElevationResult.h"
#include "LatLng.h"
//#include "AbstractGoogleMapsService.h"

#define INVALID_REQUEST "INVALID_REQUEST"
#define STATUS_OK "STATUS_OK"
#define OVER_QUERY_LIMIT "OVER_QUERY_LIMIT"
#define REQUEST_DENIED "REQUEST_DENIED"
#define UNKNOWN_ERROR "UNKNOWN_ERROR"

namespace googleMaps
{
	class PathElevationRequest;
	class LocationElevationRequest;
	class ElevationResult;
	class LatLng;
	// class AbstractGoogleMapsService;
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
        public:
            explicit ElevationService(QObject* parent = 0);
            ~ElevationService();
            void getElevationAlongPath(googleMaps::PathElevationRequest request, EElevationStatus status);
            void getElevationForLocations(googleMaps::LocationElevationRequest request, EElevationStatus status);
            void elevationResultsReceived(googleMaps::ElevationResult result, EElevationStatus status);
            static googleMaps::PathElevationRequest createPathElevationRequest(QList<googleMaps::LatLng> path, qreal samples);
            static googleMaps::LocationElevationRequest createLocationElevationRequest(QList<googleMaps::LatLng> locations);

        protected slots:
            void handleResultsReceived(QList<googleMaps::ElevationResult>);
	};
}

#endif
