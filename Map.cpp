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
    m_mapLoaded = false;
    m_markers = QList<googleMaps::Marker>();
}

googleMaps::Map::~Map()
{

}

googleMaps::Map::Map(const googleMaps::MapOptions options)
{
   updateOptions(options);
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

QVariantMap googleMaps::Map::getOptionsMap() const
{
     qDebug() <<  "[Map] getOptionsMap  ";
    return m_options.serialize();
}

void googleMaps::Map::startMap()
{
     qDebug() <<  "[Map] startMapView  " << m_mapLoaded;
    emit startMapView();
}

googleMaps::MapOptions googleMaps::Map::getOptions() const
{
    return m_options;
}

bool googleMaps::Map::getMapLoaded() const
{
    return m_mapLoaded;
}

void googleMaps::Map::updateMapLoaded(const bool loaded)
{
    qDebug() <<  "[Map] MapLoaded  ";
    m_mapLoaded = loaded;
    QVariantMap map;
    map = getOptionsMap();
    emit updateMapOptionsRequest(map);
}

void googleMaps::Map::updateBounds(const LatLngBounds latLngBounds)
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

QString googleMaps::Map::getMapTypeId() const
{
    return m_mapTypeID;
}

int googleMaps::Map::getZoom() const
{
    return m_zoom;
}

void googleMaps::Map::updateCenter(const QVariant latlng)
{
    m_mapCenter.deserialize(latlng);
    qDebug() << "[googleMaps::Map] centerMapAt " << m_mapCenter.lat() << "  " << m_mapCenter.lng();
    emit centerChanged(m_mapCenter);
}

void googleMaps::Map::centerMapAt(const LatLng latLng)
{
    m_mapCenter = latLng;
    qDebug() << "[googleMaps::Map] centerMapAt " << m_mapCenter.lat() << "  " << m_mapCenter.lng();
    emit centerOnLocation(m_mapCenter.lat(), m_mapCenter.lng());
}

void googleMaps::Map::panToBound(const LatLngBounds latLngBounds)
{
	throw "Not yet implemented";
}

void googleMaps::Map::updateMapTypeId(const QString mapTypeId)
{
    m_mapTypeID = mapTypeId;
     qDebug() <<  "[Map] updateMapType  " << m_mapLoaded;
    if (m_mapLoaded)
    {
        emit updateMapTypeRequest(mapTypeId);
    }
    emit maptypeid_changed();
}

void googleMaps::Map::updateZoom(const QVariant zoom)
{
    qDebug() <<  "[Map] update zoom  "  << zoom;
    m_zoom = zoom.toDouble();
}

void googleMaps::Map::updateOptions(googleMaps::MapOptions options)
{
    QVariantMap map;
    m_options = options;
     qDebug() <<  "[Map] updateOptions  " << m_mapLoaded;
    map = getOptionsMap();
    if (m_mapLoaded)
    {
        emit updateMapOptionsRequest(map);
    }
    emit optionsChanged();
}

void googleMaps::Map::panMapTo(googleMaps::LatLng latLng)
{
	throw "Not yet implemented";
}

int googleMaps::Map::getTilt() const
{
    return m_tilt;
}

void googleMaps::Map::updateTilt(const int tilt)
{
    m_tilt = tilt;
}


void googleMaps::Map::updateMapTypes(const MapTypeRegistry mapTypes)
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


void googleMaps::Map::addMarker(MarkerOptions options)
{
    qDebug() << "[googleMaps::Map] addMarker ";
    googleMaps::Marker marker = googleMaps::Marker(options);
    m_markers.push_back(marker);
    emit addMarkerRequest(options.serialize());
}

void googleMaps::Map::clearMarker(googleMaps::LatLng position)
{
    emit clearMarkerRequest(position.serialize());
}

void googleMaps::Map::clearMarkers()
{
    emit clearAllMarkersRequest();
}

googleMaps::Marker googleMaps::Map::createMarker(const MarkerOptions options)
{
    googleMaps::Marker marker = googleMaps::Marker();
    marker.setOptions(options);
    return marker;
}

void googleMaps::Map::addPolygon(googleMaps::PolygonOptions options)
{
    Polygon newPG = Polygon(options);
    m_polygons.push_back(newPG);
    emit addPolygonRequest(options.serialize());
}

void googleMaps::Map::clearPolygon(googleMaps::PolygonOptions options)
{

}

void googleMaps::Map::clearPolygons()
{
    emit clearPolygonsRequest();
}

void googleMaps::Map::sendZoomOutRequest()
{
    emit zoomOutRequest();
}

void googleMaps::Map::sendZoomInRequest()
{
    emit zoomInRequest();
}
