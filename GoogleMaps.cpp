#include "GoogleMaps.h"
#include <QDebug>


googleMaps::GoogleMaps::GoogleMaps(QObject *parent):
    QObject(parent)
{
    m_transportReady = false;
    m_mapsKey = "";
}

googleMaps::GoogleMaps::~GoogleMaps()
{

    if (m_channel)
    {

    }
    if (m_geoCoder)
    {
        delete m_geoCoder;
    }
    if (m_sphericalGeometryService)
    {
        delete m_sphericalGeometryService;
    }
    if (m_map)
    {
        disconnect(m_map, SIGNAL(centerChanged(googleMaps::LatLng)), this, SIGNAL(centerChanged(googleMaps::LatLng)));
        disconnect(m_map, SIGNAL(zoom_changed(qreal)), this, SIGNAL(zoomChanged(qreal)));
        delete m_map;
    }
}

QWebChannel* googleMaps::GoogleMaps::getChannel() const
{
    return m_channel;
}

void googleMaps::GoogleMaps::setChannel(QWebChannel* chnl)
{
    qDebug() << "Setting channel " ;
    m_channel = chnl;
    m_transportReady = true;
    m_geoCoder = new googleMaps::Geocoder(this);
    m_sphericalGeometryService = new googleMaps::SphericalGeometry(this);
 //   m_elevationService = new googleMaps::ElevationService(this);
 //   m_maxZoomService = new googleMaps::MaxZoomService(this);
    m_map = new googleMaps::Map(this);
    m_channel->registerObject(QStringLiteral("Geocoder"), m_geoCoder);
 //   m_channel->registerObject(QStringLiteral("ElevationService"), m_elevationService);
    m_channel->registerObject(QStringLiteral("SphericalGeometry"), m_sphericalGeometryService);
 //   m_channel->registerObject(QStringLiteral("MaxZoom"), m_maxZoomService);
    m_channel->registerObject(QStringLiteral("Map"), m_map);
    connect(m_map, SIGNAL(centerChanged(googleMaps::LatLng)), this, SIGNAL(centerChanged(googleMaps::LatLng)));
    connect(m_map, SIGNAL(zoom_changed(qreal)), this, SIGNAL(zoomChanged(qreal)));
    if (m_mapsKey != "")
    {
        m_map->setMapsKey(m_mapsKey);
    }
    emit transportReady();
}

void googleMaps::GoogleMaps::setMapsKey(const QString key)
{
    qDebug() << "[GoogleMaps] key set " << key;
    m_mapsKey = key;
}

QString googleMaps::GoogleMaps::getMapKey() const
{
    return m_mapsKey;
}

bool googleMaps::GoogleMaps::isConnected()
{
   return m_transportReady;
}

void googleMaps::GoogleMaps::centerMapAt(googleMaps::LatLng newCenter)
{
    qDebug() << "[GoogleMaps] centerMapAt " << newCenter.lat() << "  " << newCenter.lng();
    m_map->centerMapAt(newCenter);
}

void googleMaps::GoogleMaps::addMarker(MarkerOptions option)
{
    if (m_map)
    {
         qDebug() << "[GoogleMaps] addMarker " << option.getPosition().toString();
        m_map->addMarker(option);
        emit markerCreated(option);
    }
}

void googleMaps::GoogleMaps::clearMarker(googleMaps::LatLng position)
{
    if (m_map)
    {
        qDebug() << "[GoogleMaps] clearMarker " << position.toString();
        m_map->clearMarker(position);
        emit markerCleared();
    }
}

void googleMaps::GoogleMaps::clearMarkers()
{
    if (m_map)
    {
        m_map->clearMarkers();
    }
}

googleMaps::Marker googleMaps::GoogleMaps::createMarker(const googleMaps::MarkerOptions options)
{
    return googleMaps::Map::createMarker(options);
}

void googleMaps::GoogleMaps::addPolygon(googleMaps::PolygonOptions options)
{
    if (m_map)
    {
        qDebug() << "[GoogleMaps] addPolygon ";
        m_map->addPolygon(options);
    }
}

void googleMaps::GoogleMaps::clearPolygon(googleMaps::PolygonOptions options)
{
    if (m_map)
    {
        qDebug() << "[GoogleMaps] clearPolygon ";
        m_map->clearPolygon(options);
    }
}

void googleMaps::GoogleMaps::clearPolygons()
{
    if (m_map)
    {
        qDebug() << "[GoogleMaps] clearPolygons ";
        m_map->clearPolygons();
    }

}

void googleMaps::GoogleMaps::computeArea(const QList<googleMaps::LatLng>& path)
{
    //qDebug() << "[GoogleMaps] computeArea " << path.size();
    m_sphericalGeometryService->computeArea(path);
    connect(m_sphericalGeometryService, SIGNAL(distanceResultReceived(qreal)), this, SLOT(handleDistanceResults(qreal)));
}

void googleMaps::GoogleMaps::computeDistanceBetween(const googleMaps::LatLng& from, const googleMaps::LatLng& to)
{
    //qDebug() << "[GoogleMaps] computeDistanceBetween ";
    m_sphericalGeometryService->computeDistanceBetween(from, to);
    connect(m_sphericalGeometryService, SIGNAL(distanceResultReceived(qreal)), this, SLOT(handleDistanceResults(qreal)));
}

void googleMaps::GoogleMaps::computeHeading(const googleMaps::LatLng& from, const googleMaps::LatLng& to)
{
    //qDebug() << "[GoogleMaps] computeHeading ";
    m_sphericalGeometryService->computeHeading(from, to);
    connect(m_sphericalGeometryService, SIGNAL(distanceResultReceived(QVariant)), this, SLOT(handleDistanceResults(QVariant)));
}

void googleMaps::GoogleMaps::computeLength(const QList<googleMaps::LatLng>& path)
{
    //qDebug() << "[GoogleMaps] computeLength " << path.size();
    m_sphericalGeometryService->computeLength(path);
    connect(m_sphericalGeometryService, SIGNAL(distanceResultReceived(qreal)), this, SLOT(handleDistanceResults(qreal)));
}

void googleMaps::GoogleMaps::computeOffset(const LatLng from, const qreal distance, const qreal heading)
{
    //qDebug() << "[GoogleMaps] computeOffset " ;
    connect(m_sphericalGeometryService, SIGNAL(positionResultReceived(googleMaps::LatLng)), this, SLOT(handlePositionResults(googleMaps::LatLng)));
    m_sphericalGeometryService->computeOffset(from, distance, heading);

}

void googleMaps::GoogleMaps::computeOffsetOrigin(const googleMaps::LatLng to, const qreal distance, const qreal heading)
{
    //qDebug() << "[GoogleMaps] computeOffsetOrigin " ;
    m_sphericalGeometryService->computeOffsetOrigin(to, distance, heading);
    connect(m_sphericalGeometryService, SIGNAL(positionResultReceived(googleMaps::LatLng)), this, SLOT(handlePositionResults(googleMaps::LatLng)));
}

void googleMaps::GoogleMaps::interpolate(googleMaps::LatLng& from, googleMaps::LatLng& to, qreal& fraction)
{
    //qDebug() << "[GoogleMaps] interpolate ";
    m_sphericalGeometryService->interpolate(from, to, fraction);
    connect(m_sphericalGeometryService, SIGNAL(positionResultReceived(googleMaps::LatLng)), this, SLOT(handlePositionResults(googleMaps::LatLng)));
}

void googleMaps::GoogleMaps::getMaxZoomAtLatLng(googleMaps::LatLng latLng) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::geocodeName(QString location)
{
    googleMaps::GeocoderRequest request = googleMaps::Geocoder::createGeocoderRequest(location);
    connect(m_geoCoder, SIGNAL(geocodeResultReceived(QVariantList,QString&)), this, SLOT(handleGeocoderResults(QVariantList,QString&)));
    m_geoCoder->geocode(request);
}

void googleMaps::GoogleMaps::geocodeLatLng(googleMaps::LatLng latLng)
{
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::getElevationAlongPath(googleMaps::PathElevationRequest request) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::getElevationForLocations(googleMaps::LocationElevationRequest request) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::messageReceived(const QJsonObject& message)
{
     QJsonDocument doc(message);

    QString strJson(doc.toJson(QJsonDocument::Compact));
    //QVariantMap messageMap = message.toVariantMap();
    qDebug() << " Json message received " << strJson;
}

void googleMaps::GoogleMaps::handleGeocoderResults(QVariantList results, QString& status)
{
//    qDebug() << "[GoogleMaps] handleGeocoderResults " << results.size();
    qDebug() << "[GeoWorldBuilder]   GeoLocation Received " << status;
    emit geoLocationsReceived();
}

void googleMaps::GoogleMaps::handleDistanceResults(qreal distance)
{
     qDebug() << "[GoogleMaps]   set Distance Result:  lat " << QString::number(distance);
    disconnect(m_sphericalGeometryService, SIGNAL(distanceResultReceived(qreal)), this, SLOT(handleDistanceResults(qreal)));
    emit distanceResultsReceived();
}

void googleMaps::GoogleMaps::handlePositionResults(LatLng position)
{
     qDebug() << "[GoogleMaps]   setPositionResult:  lat " << position.lat() << " lng  " << position.lng();
     disconnect(m_sphericalGeometryService, SIGNAL(positionResultReceived(googleMaps::LatLng)), this, SLOT(handlePositionResults(googleMaps::LatLng)));
    emit positionResultsReceived();
}

void googleMaps::GoogleMaps::handleMaxZoomResults(googleMaps::MaxZoomResult result, int status) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleElevationResults(QList<googleMaps::ElevationResult> results, int status) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleMaxZoomReceived(qreal zoomLevel) {
    throw "Not yet implemented";
}

QVariantList googleMaps::GoogleMaps::getGeoCoderResults() const
{
    return m_geoCoder->getResults();
}

qreal googleMaps::GoogleMaps::getDistanceResult() const
{
    return m_sphericalGeometryService->getDistanceResult();
}

googleMaps::LatLng googleMaps::GoogleMaps::getPositionResult() const
{
    return m_sphericalGeometryService->getPositionResults();
}

void googleMaps::GoogleMaps::zoomInRequest()
{
    m_map->sendZoomInRequest();
}

void googleMaps::GoogleMaps::zoomOutRequest()
{
    m_map->sendZoomOutRequest();
}
