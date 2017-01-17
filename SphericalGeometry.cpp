#include <exception>
using namespace std;

#include <QDebug>
#include "SphericalGeometry.h"
#include "LatLng.h"
#include "qtutils.h"

googleMaps::SphericalGeometry::SphericalGeometry(QObject *parent)
{
    setParent(parent);
     qDebug() << "[SphericalGeometry]  ";
    m_distanceResult = -1;
    m_positionResult = LatLng(-1,-1);
}


void googleMaps::SphericalGeometry::computeArea(QList<googleMaps::LatLng> path)
{
    qDebug() << "[SphericalGeometry]   computeAreaRequest: ";
    //emit computeAreaRequest(convert2VariantList(path));
}

void googleMaps::SphericalGeometry::computeDistanceBetween(const LatLng from, const LatLng to)
{
    qDebug() << "[SphericalGeometry]   computeDistanceBetweenRequest: ";
    emit computeDistanceBetweenRequest(from.lat(), from.lng(), to.lat(), to.lng());
}








void googleMaps::SphericalGeometry::computeLength(const QList<googleMaps::LatLng> path)
{
    qDebug() << "[SphericalGeometry]   computeLengthRequest: ";
   // emit computeLengthRequest(convert2VariantList(path));
}

void googleMaps::SphericalGeometry::computeOffset(const googleMaps::LatLng from, const qreal distance, const qreal heading)
{
    qDebug() << "[SphericalGeometry]   computeOffsetRequest: ";
    emit computeOffsetRequest(from.lat(), from.lng(), distance, heading);
}

void googleMaps::SphericalGeometry::computeOffsetOrigin(const googleMaps::LatLng to, const qreal distance, const qreal heading)
{
    qDebug() << "[SphericalGeometry]   computeOffsetOriginRequest: ";
    emit computeOffsetOriginRequest(to.lat(), to.lng(), distance, heading);
}

void googleMaps::SphericalGeometry::interpolate(const LatLng from, const LatLng to, const qreal fraction)
{
    qDebug() << "[SphericalGeometry]   interpolateRequest: ";
    emit interpolateRequest(from.lat(), from.lng(), to.lat(), to.lng(), fraction);
}

void googleMaps::SphericalGeometry::computeHeading(const googleMaps::LatLng from, const googleMaps::LatLng to)
{
    qDebug() << "[SphericalGeometry]   computeHeadingRequest: ";
    emit computeHeadingRequest(from.lat(), from.lng(), to.lat(), to.lng());
}


void googleMaps::SphericalGeometry::setDistanceResult(const qreal aDistanceResult)
{
    this->m_distanceResult = aDistanceResult;
    emit distanceResultReceived();
}

qreal googleMaps::SphericalGeometry::getDistanceResult() const
{
    return this->m_distanceResult;
}

void googleMaps::SphericalGeometry::setPositionResult(const googleMaps::LatLng aPositionResult)
{
    this->m_positionResult = aPositionResult;
}

googleMaps::LatLng googleMaps::SphericalGeometry::getPositionResults() const
{
    return this->m_positionResult;
}

