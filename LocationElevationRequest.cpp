#include <exception>
using namespace std;

#include "LocationElevationRequest.h"
#include "LatLng.h"

googleMaps::LocationElevationRequest::LocationElevationRequest(QObject *parent)
{
    setParent(parent);
}

//copy constructor
googleMaps::LocationElevationRequest::LocationElevationRequest(const LocationElevationRequest& rhs)
{
    m_locations = rhs.getLocations();
}

googleMaps::LocationElevationRequest& googleMaps::LocationElevationRequest::operator=(const googleMaps::LocationElevationRequest rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_locations = rhs.getLocations();
    return *this;
}

googleMaps::LocationElevationRequest::~LocationElevationRequest()
{
}

void googleMaps::LocationElevationRequest::addLocation(googleMaps::LatLng location)
{
    m_locations.append(location.serialize());
    emit locationsChanged();
}

void googleMaps::LocationElevationRequest::clearLocations()
{
    m_locations.clear();
    emit locationsChanged();
}

QVariantList googleMaps::LocationElevationRequest::getLocations() const
{
    return this->m_locations;
}

void googleMaps::LocationElevationRequest::updateLocations(const QVariantList locations)
{
    m_locations = locations;
    emit locationsChanged();
}

