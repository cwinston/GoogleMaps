#include <exception>
using namespace std;

#include "GeocoderRequest.h"
#include "LatLngBounds.h"
#include "LatLng.h"

googleMaps::GeocoderRequest::GeocoderRequest(QObject *parent)
{
}

googleMaps::GeocoderRequest::~GeocoderRequest() {

}

googleMaps::GeocoderRequest::GeocoderRequest(const GeocoderRequest& rhs)
{
    m_address = rhs.getAddress();
    m_bounds = rhs.getBounds();
    m_region = rhs.getRegion();
    m_placeId = rhs.getPlaceId();
    m_location  = rhs.getLocation();
    m_componentRestrictions = rhs.getComponentRestrictions();
}

googleMaps::GeocoderRequest googleMaps::GeocoderRequest::operator =(const GeocoderRequest& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_address = rhs.getAddress();
    m_bounds = rhs.getBounds();
    m_region = rhs.getRegion();
    m_placeId = rhs.getPlaceId();
    m_location  = rhs.getLocation();
    m_componentRestrictions = rhs.getComponentRestrictions();
    return *this;
}

void googleMaps::GeocoderRequest::setAddress(const QString aAddress)
{
    this->m_address = aAddress;
}

QString googleMaps::GeocoderRequest::getAddress()  const
{
    return this->m_address;
}

void googleMaps::GeocoderRequest::setBounds(const googleMaps::LatLngBounds aBounds)
{
    this->m_bounds = aBounds;
}

googleMaps::LatLngBounds googleMaps::GeocoderRequest::getBounds()  const
{
    return this->m_bounds;
}

void googleMaps::GeocoderRequest::setRegion(QString aRegion)
{
    this->m_region = aRegion;
}

QString googleMaps::GeocoderRequest::getRegion() const
{
    return this->m_region;
}

void googleMaps::GeocoderRequest::setPlaceId(QString aPlaceId)
{
    this->m_placeId = aPlaceId;
}

QString googleMaps::GeocoderRequest::getPlaceId() const
{
    return this->m_placeId;
}

void googleMaps::GeocoderRequest::setLocation(const googleMaps::LatLng aLocation)
{
    this->m_location = aLocation;
}

googleMaps::LatLng googleMaps::GeocoderRequest::getLocation() const
{
    return this->m_location;
}

void googleMaps::GeocoderRequest::setComponentRestrictions(const GeocoderComponentRestrictions aComponentRestrictions)
{
    this->m_componentRestrictions = aComponentRestrictions;
}

googleMaps::GeocoderComponentRestrictions googleMaps::GeocoderRequest::getComponentRestrictions() const
{
    return this->m_componentRestrictions;
}

