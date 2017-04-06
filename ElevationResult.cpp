#include <exception>
using namespace std;

#include "ElevationResult.h"
#include "LatLng.h"

googleMaps::ElevationResult::ElevationResult(QObject* parent)
{
    setParent(parent);
    m_elevation = 0;
    m_resolution = 0;
    m_location = LatLng();
}

googleMaps::ElevationResult::~ElevationResult() {

}

googleMaps::ElevationResult::ElevationResult(const googleMaps::ElevationResult& rhs)
{
    m_elevation = rhs.getElevation();
    m_location = rhs.getLocation();
    m_resolution = rhs.getResolution();
}

googleMaps::ElevationResult& googleMaps::ElevationResult::operator=(const googleMaps::ElevationResult& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_elevation = rhs.getElevation();
    m_location = rhs.getLocation();
    m_resolution = rhs.getResolution();
    return *this;
}

void googleMaps::ElevationResult::setElevation(qreal elevation)
{
    this->m_elevation = elevation;
    emit elevationChanged();
}

qreal googleMaps::ElevationResult::getElevation() const
{
    return this->m_elevation;
}

void googleMaps::ElevationResult::setLocation(googleMaps::LatLng location)
{
    this->m_location = location;
    emit locationChanged();
}

googleMaps::LatLng googleMaps::ElevationResult::getLocation() const
{
    return this->m_location;
}

void googleMaps::ElevationResult::setResolution(qreal resolution)
{
    this->m_resolution = resolution;
    emit resolutionChanged();
}

qreal googleMaps::ElevationResult::getResolution() const
{
    return this->m_resolution;
}

