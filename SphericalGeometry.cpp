#include <exception>
using namespace std;

#include "SphericalGeometry.h"
#include "LatLng.h"

googleMaps::SphericalGeometry::SphericalGeometry(QObject *parent) {
}

googleMaps::SphericalGeometry::~SphericalGeometry() {

}

qreal googleMaps::SphericalGeometry::computeArea(QList<googleMaps::LatLng> path) {
	throw "Not yet implemented";
}

qreal googleMaps::SphericalGeometry::computeDistanceBetween(googleMaps::LatLng from, googleMaps::LatLng to) {
	throw "Not yet implemented";
}

qreal googleMaps::SphericalGeometry::computeHeading(googleMaps::LatLng from, googleMaps::LatLng to) {
	throw "Not yet implemented";
}

qreal googleMaps::SphericalGeometry::computeLength(QList<googleMaps::LatLng> path) {
	throw "Not yet implemented";
}

googleMaps::LatLng googleMaps::SphericalGeometry::computeOffset(googleMaps::LatLng from, qreal distance, qreal heading) {
	throw "Not yet implemented";
}

googleMaps::LatLng googleMaps::SphericalGeometry::computeOffsetOrigin(googleMaps::LatLng to, qreal distance, qreal heading) {
	throw "Not yet implemented";
}

googleMaps::LatLng googleMaps::SphericalGeometry::interpolate(googleMaps::LatLng from, googleMaps::LatLng to, qreal fraction) {
	throw "Not yet implemented";
}

void googleMaps::SphericalGeometry::setDistanceResult(const qreal aDistanceResult) {
    this->m_distanceResult = aDistanceResult;
}

qreal googleMaps::SphericalGeometry::getDistanceResult() const {
    return this->m_distanceResult;
}

void googleMaps::SphericalGeometry::setPositionResult(const googleMaps::LatLng aPositionResult) {
    this->m_positionResult = aPositionResult;
}

googleMaps::LatLng googleMaps::SphericalGeometry::getPositionResult() const {
    return this->m_positionResult;
}

