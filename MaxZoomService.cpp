#include <exception>
using namespace std;

#include "MaxZoomService.h"
#include "MaxZoomResult.h"
#include "LatLng.h"

googleMaps::MaxZoomService::MaxZoomService() {
}

void googleMaps::MaxZoomService::getMaxZoomAtLatLng(googleMaps::LatLng latLng) {
	throw "Not yet implemented";
}

void googleMaps::MaxZoomService::setResults(googleMaps::MaxZoomResult results) {
    this->m_results = results;
}

googleMaps::MaxZoomResult googleMaps::MaxZoomService::getResults() const
{
    return this->m_results;
}

