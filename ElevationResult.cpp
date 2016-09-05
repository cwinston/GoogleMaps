#include <exception>
using namespace std;

#include "ElevationResult.h"
#include "LatLng.h"

googleMaps::ElevationResult::ElevationResult(QObject* parent)
{
    setParent(parent);
}

googleMaps::ElevationResult::~ElevationResult() {

}

googleMaps::ElevationResult::ElevationResult(const googleMaps::ElevationResult& rhs) {
}

googleMaps::ElevationResult& googleMaps::ElevationResult::operator=(const googleMaps::ElevationResult& rhs)
{
    return *this;
}

void googleMaps::ElevationResult::setElevation(qreal elevation) {
    this->m_elevation = elevation;
}

qreal googleMaps::ElevationResult::getElevation() {
    return this->m_elevation;
}

void googleMaps::ElevationResult::setLocation(googleMaps::LatLng location) {
    this->m_location = location;
}

googleMaps::LatLng googleMaps::ElevationResult::getLocation() {
    return this->m_location;
}

void googleMaps::ElevationResult::setResolution(qreal resolution) {
    this->m_resolution = resolution;
}

qreal googleMaps::ElevationResult::getResolution() {
    return this->m_resolution;
}

