#include <exception>
using namespace std;

#include <QDebug>
#include "GeocoderGeometry.h"
#include "LatLngBounds.h"
#include "LatLng.h"


googleMaps::GeocoderGeometry::GeocoderGeometry(QObject *parent)
{
    setParent(parent);
}

googleMaps::GeocoderGeometry::GeocoderGeometry(const GeocoderGeometry& rhs)
{
    m_bounds = rhs.getBounds();
    m_viewport = rhs.getViewport();
    m_location = rhs.getLocation();
    m_locationType = rhs.getLocationType();
}

//assignment operator
googleMaps::GeocoderGeometry& googleMaps::GeocoderGeometry::operator=(const GeocoderGeometry &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }

    m_bounds = rhs.getBounds();
    m_viewport = rhs.getViewport();
    m_location = rhs.getLocation();
    m_locationType = rhs.getLocationType();
    return *this;
}

googleMaps::GeocoderGeometry::~GeocoderGeometry()
{

}

void googleMaps::GeocoderGeometry::setBounds(const googleMaps::LatLngBounds aBounds)
{
    this->m_bounds = aBounds;
}

googleMaps::LatLngBounds googleMaps::GeocoderGeometry::getBounds() const
{
    return this->m_bounds;
}

void googleMaps::GeocoderGeometry::setLocation(const googleMaps::LatLng aLocation)
{
    this->m_location = aLocation;
}

googleMaps::LatLng googleMaps::GeocoderGeometry::getLocation() const
{
    return this->m_location;
}

void googleMaps::GeocoderGeometry::setLocationType(const googleMaps::EGeocoderLocationType locationType)
{
    this->m_locationType = locationType;
}

googleMaps::EGeocoderLocationType googleMaps::GeocoderGeometry::getLocationType() const
{
    return this->m_locationType;
}

void googleMaps::GeocoderGeometry::setViewport(const googleMaps::LatLngBounds aViewport)
{
    this->m_viewport = aViewport;
}

googleMaps::LatLngBounds googleMaps::GeocoderGeometry::getViewport() const
{
    return this->m_viewport;
}

void googleMaps::GeocoderGeometry::deserialize(const QVariantMap& data)
{
     qDebug() << "[GeocoderGeometry] parse geometry result " << data << "\n";
      qDebug() << "[GeocoderGeometry]  geometry keys " << data.keys() << "\n";
      for (auto geomKey : data.keys())
      {
          if (geomKey == GEO_GEOMETRY_BOUNDS)
          {
                m_bounds.deserialize(data[geomKey].toMap());
          }
          else if (geomKey == GEO_GEOMETRY_LOCATION)
          {
               qDebug() << "[GeocoderGeometry]  parse location " << data[geomKey] << "\n";
              m_location.deserialize(data[geomKey].toMap());

          }
          else if (geomKey == GEO_GEOMETRY_VIEWPORT)
          {
               qDebug() << "[GeocoderGeometry]  parse viewport " << data[geomKey] << "\n";
              m_viewport.deserialize(data[geomKey].toMap());

          }
          else if (geomKey == GEO_GEOMETRY_LOC_TYPE)
          {
              QString locType = data[geomKey].toString();
              if (locType == GEO_LOCATION_APPROX)
              {
                  m_locationType = APPROXIMATE;
              }
              else if (locType == GEO_LOCATION_GEOMETRIC_CENTER)
              {
                  m_locationType = GEOMETRIC_CENTER;
              }
              else if (locType == GEO_LOCATION_RANGE_INTERPOLATED)
              {
                  m_locationType = RANGE_INTERPOLATED;
              }
              else if (locType == GEO_LOCATION_ROOFTOP)
              {
                  m_locationType = ROOFTOP;
              }

            qDebug() << "[GeocoderGeometry]  parse location type " << data[geomKey] << "\n";
          }
      }
}
