#include <exception>
using namespace std;

#include "GeocoderComponentRestrictions.h"
googleMaps::GeocoderComponentRestrictions::GeocoderComponentRestrictions(QObject *parent) {
}

googleMaps::GeocoderComponentRestrictions::~GeocoderComponentRestrictions() {

}

googleMaps::GeocoderComponentRestrictions::GeocoderComponentRestrictions(const GeocoderComponentRestrictions& rhs)
{
   m_administrativeArea = rhs.getAdministrativeArea();
   m_country = rhs.getCountry();
   m_route = rhs.getRoute();
   m_locality = rhs.getLocality();
   m_postalCode = rhs.getPostalCode();
}

//assignment operator
googleMaps::GeocoderComponentRestrictions& googleMaps::GeocoderComponentRestrictions::operator=(const GeocoderComponentRestrictions &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_administrativeArea = rhs.getAdministrativeArea();
    m_country = rhs.getCountry();
    m_route = rhs.getRoute();
    m_locality = rhs.getLocality();
    m_postalCode = rhs.getPostalCode();
    return *this;
}


void googleMaps::GeocoderComponentRestrictions::setAdministrativeArea(QString aAdministrativeArea) {
    this->m_administrativeArea = aAdministrativeArea;
}

QString googleMaps::GeocoderComponentRestrictions::getAdministrativeArea() const {
    return this->m_administrativeArea;
}

void googleMaps::GeocoderComponentRestrictions::setCountry(QString aCountry) {
    this->m_country = aCountry;
}

QString googleMaps::GeocoderComponentRestrictions::getCountry() const  {
    return this->m_country;
}

void googleMaps::GeocoderComponentRestrictions::setLocality(const QString aLocality) {
    this->m_locality = aLocality;
}

QString googleMaps::GeocoderComponentRestrictions::getLocality() const  {
    return this->m_locality;
}

void googleMaps::GeocoderComponentRestrictions::setPostalCode(const QString aPostalCode) {
    this->m_postalCode = aPostalCode;
}

QString googleMaps::GeocoderComponentRestrictions::getPostalCode() const {
    return this->m_postalCode;
}

void googleMaps::GeocoderComponentRestrictions::setRoute(const QString aRoute) {
    this->m_route = aRoute;
}

QString googleMaps::GeocoderComponentRestrictions::getRoute() const {
    return this->m_route;
}

