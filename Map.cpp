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
}

googleMaps::Map::~Map()
{

}

googleMaps::Map::Map(googleMaps::MapOptions options) {
}

googleMaps::Map::Map(const googleMaps::Map &rhs)
{
}

void googleMaps::Map::updateBounds(QVariant latLngBounds)
{
    m_bounds = latLngBounds;
}

void googleMaps::Map::fitBounds(googleMaps::LatLngBounds bounds) {
	throw "Not yet implemented";
}

QVariant googleMaps::Map::getBounds() const
{
    return QVariant(m_bounds);
}

QVariant googleMaps::Map::getCenter() const
{
    return QVariant(m_mapCenter);
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
    m_mapCenter = latlng;
    emit centerOnLocation(latlng);
}

void googleMaps::Map::panToBound(googleMaps::LatLngBounds latLngBounds)
{
	throw "Not yet implemented";
}

void googleMaps::Map::updateMapTypeId(googleMaps::EMapTypeID mapTypeId)
{
    m_mapTypeID = mapTypeId;
}

void googleMaps::Map::updateZoom(int zoom)
{
    qDebug() <<  "[Map] update zoom  "  << zoom;
    m_zoom = zoom;
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

googleMaps::MapTypeRegistry& googleMaps::Map::getMapTypes()
{
    return this->m_mapTypes;
}



