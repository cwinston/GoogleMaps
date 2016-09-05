#include <exception>
using namespace std;

#include "PathElevationRequest.h"
#include "LatLng.h"

googleMaps::PathElevationRequest::PathElevationRequest(QObject *parent) {
}

googleMaps::PathElevationRequest::~PathElevationRequest() {

}

googleMaps::PathElevationRequest::PathElevationRequest(const PathElevationRequest& rhs)
{

}

googleMaps::PathElevationRequest& googleMaps::PathElevationRequest::operator=(const googleMaps::PathElevationRequest rhs)
{
    return  *this;
}

void googleMaps::PathElevationRequest::addLocation(googleMaps::LatLng position)
{

}

void googleMaps::PathElevationRequest::removeLocation(googleMaps::LatLng location)
{

}

QList<googleMaps::LatLng> googleMaps::PathElevationRequest::getPath() {
    return this->m_path;
}

void googleMaps::PathElevationRequest::setSamples(qreal samples) {
    this->m_samples = samples;
}

qreal googleMaps::PathElevationRequest::getSamples() {
    return this->m_samples;
}

