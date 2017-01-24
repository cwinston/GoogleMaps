#include <exception>
using namespace std;

#include "Map.h"
//#include "MapTypeRegistry.h"
#include "MapOptions.h"
#include "LatLngBounds.h"
#include "LatLng.h"
//#include "MouseEvent.h"
//#include "AbstractGoogleMapsService.h"
#include <QDebug>

googleMaps::Map::Map(QObject *parent)
{
    setParent(parent);
    m_mapsKey = "";
}

googleMaps::Map::~Map()
{

}

googleMaps::Map::Map(const googleMaps::MapOptions options)
{
   setOptions(options);
}

void googleMaps::Map::setOptions(const googleMaps::MapOptions options)
{
    m_options = options;
    emit optionsChanged();
}

googleMaps::Map::Map(const googleMaps::Map &rhs)
{
    m_mapTypes = rhs.getMapTypes();
    m_bounds = rhs.getBounds();
    m_options = rhs.getOptions();
    m_mapCenter = rhs.getCenter();
    m_mapTypeID = rhs.getMapTypeId();
    m_tilt = rhs.getTilt();
    m_zoom = rhs.getZoom();
    m_mapsKey = rhs.getMapsKey();
}

googleMaps::Map& googleMaps::Map::operator=(const googleMaps::Map &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_mapTypes = rhs.getMapTypes();
    m_bounds = rhs.getBounds();
    m_options = rhs.getOptions();
    m_mapCenter = rhs.getCenter();
    m_mapTypeID = rhs.getMapTypeId();
    m_tilt = rhs.getTilt();
    m_zoom = rhs.getZoom();
    m_mapsKey = rhs.getMapsKey();
    return *this;
}

void googleMaps::Map::setMapsKey(const QString key)
{
    qDebug() <<  "[Map] setMapsKey  "  << key;
    m_mapsKey = key;
}

QString googleMaps::Map::getMapsKey() const
{
    return m_mapsKey;
}

void googleMaps::Map::startMap()
{
     qDebug() <<  "[Map] startMapView  ";
    emit startMapView();
}

googleMaps::MapOptions googleMaps::Map::getOptions() const
{
    return m_options;
}

void googleMaps::Map::updateBounds(googleMaps::LatLngBounds latLngBounds)
{
    m_bounds = latLngBounds;
}

void googleMaps::Map::fitBounds(googleMaps::LatLngBounds bounds) {
	throw "Not yet implemented";
}

googleMaps::LatLngBounds googleMaps::Map::getBounds() const
{
    return m_bounds;
}

googleMaps::LatLng googleMaps::Map::getCenter() const
{
    return m_mapCenter;
}

googleMaps::EMapTypeID googleMaps::Map::getMapTypeId() const
{
    return m_mapTypeID;
}

int googleMaps::Map::getZoom() const
{
    return m_zoom;
}

void googleMaps::Map::updateCenter(QVariant latlng)
{
    m_mapCenter.deserialize(latlng);
    qDebug() << "[googleMaps::Map] centerMapAt " << m_mapCenter.lat() << "  " << m_mapCenter.lng();
    emit centerChanged(m_mapCenter);
}

void googleMaps::Map::centerMapAt(googleMaps::LatLng latLng)
{
    m_mapCenter = latLng;
    qDebug() << "[googleMaps::Map] centerMapAt " << m_mapCenter.lat() << "  " << m_mapCenter.lng();
    emit centerOnLocation(m_mapCenter.lat(), m_mapCenter.lng());
}

void googleMaps::Map::panToBound(googleMaps::LatLngBounds latLngBounds)
{
	throw "Not yet implemented";
}

void googleMaps::Map::updateMapTypeId(googleMaps::EMapTypeID mapTypeId)
{
    m_mapTypeID = mapTypeId;
}

void googleMaps::Map::updateZoom(QVariant zoom)
{
    qDebug() <<  "[Map] update zoom  "  << zoom;
    m_zoom = zoom.toDouble();
}

void googleMaps::Map::updateOptions(googleMaps::MapOptions options)
{
    m_options = options;
}

void googleMaps::Map::panMapTo(googleMaps::LatLng latLng)
{
	throw "Not yet implemented";
}

int googleMaps::Map::getTilt() const
{
    return m_tilt;
}

void googleMaps::Map::updateTilt(int tilt)
{
    m_tilt = tilt;
}


void googleMaps::Map::updateMapTypes(googleMaps::MapTypeRegistry mapTypes)
{
    for (auto key : mapTypes.get().keys())
    {
        MapType*  type = mapTypes.get().value(key);
        this->m_mapTypes.set(key, type);
    }
}

googleMaps::MapTypeRegistry googleMaps::Map::getMapTypes() const
{
    return this->m_mapTypes;
}



