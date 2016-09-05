#include <exception>
using namespace std;

#include "ElevationService.h"
#include "PathElevationRequest.h"
#include "LocationElevationRequest.h"
#include "ElevationResult.h"
#include "LatLng.h"

googleMaps::ElevationService::ElevationService(QObject *parent)
{
}

googleMaps::ElevationService::~ElevationService()
{

}

void googleMaps::ElevationService::getElevationAlongPath(googleMaps::PathElevationRequest request, EElevationStatus status) {
	throw "Not yet implemented";
}

void googleMaps::ElevationService::getElevationForLocations(googleMaps::LocationElevationRequest request, EElevationStatus status) {
	throw "Not yet implemented";
}

void googleMaps::ElevationService::elevationResultsReceived(googleMaps::ElevationResult result, EElevationStatus status) {
	throw "Not yet implemented";
}

void googleMaps::ElevationService::handleResultsReceived(QList<ElevationResult>)
{
	throw "Not yet implemented";
}

googleMaps::PathElevationRequest googleMaps::ElevationService::createPathElevationRequest(QList<googleMaps::LatLng> path, qreal samples) {
	throw "Not yet implemented";
}

googleMaps::LocationElevationRequest googleMaps::ElevationService::createLocationElevationRequest(QList<googleMaps::LatLng> locations) {
	throw "Not yet implemented";
}

