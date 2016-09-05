#include <exception>
using namespace std;

#include "LocationElevationRequest.h"
#include "LatLng.h"

googleMaps::LocationElevationRequest::LocationElevationRequest(QObject *parent) {
}

googleMaps::LocationElevationRequest::~LocationElevationRequest()
{
}

void googleMaps::LocationElevationRequest::addLocation(googleMaps::LatLng location) {
	throw "Not yet implemented";
}

void googleMaps::LocationElevationRequest::removeLocation(googleMaps::LatLng location) {
	throw "Not yet implemented";
}

QList<googleMaps::LatLng> googleMaps::LocationElevationRequest::getLocations() {
    return this->m_locations;
}

