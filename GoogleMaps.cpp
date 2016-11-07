#include "GoogleMaps.h"
#include <QDebug>

googleMaps::GoogleMaps::GoogleMaps(QObject *parent):
    QObject(parent)
{
    m_transportReady = false;
}

googleMaps::GoogleMaps::~GoogleMaps()
{
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
    m_elevationService = new googleMaps::ElevationService(this);
   // m_maxZoomService = new googleMaps::MaxZoomService(this);
    m_channel->registerObject(QStringLiteral("Geocoder"), m_geoCoder);
    m_channel->registerObject(QStringLiteral("ElevationService"), m_elevationService);
    m_channel->registerObject(QStringLiteral("SphericalGeometry"), m_sphericalGeometryService);
 //   m_channel->registerObject(QStringLiteral("MaxZoom"), m_maxZoomService);
    emit transportReady();
}

bool googleMaps::GoogleMaps::isConnected()
{
   return m_transportReady;
}

void googleMaps::GoogleMaps::computeArea(const QList<googleMaps::LatLng>& path)
{
    m_sphericalGeometryService->computeArea(path);
}

void googleMaps::GoogleMaps::computeDistanceBetween(const googleMaps::LatLng& from, const googleMaps::LatLng& to) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::computeHeading(const googleMaps::LatLng& from, const googleMaps::LatLng& to) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::computeLength(const QList<googleMaps::LatLng>& path) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::computeOffset(const googleMaps::LatLng& from, const qreal& distance, const qreal& heading) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::computeOffsetOrigin(const googleMaps::LatLng& to, const qreal& distance, const qreal& heading) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::interpolate(googleMaps::LatLng& from, googleMaps::LatLng& to, qreal& fraction) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::getMaxZoomAtLatLng(googleMaps::LatLng latLng) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::geocodeName(QString location)
{
    googleMaps::GeocoderRequest request = googleMaps::Geocoder::createGeocoderRequest(location);
    //     disconnect(m_viewer, SIGNAL(geoCoderResponseReceived(googleMaps::GeocoderResult&)), this, SLOT(handleGeoLocationReceived(googleMaps::GeocoderResult&)));
    //     disconnect(m_viewer, SIGNAL(selectGeoLocationRequest(QList<googleMaps::GeocoderResult>&)), this, SLOT(handleSelectGeoLocationRequest(QList<googleMaps::GeocoderResult>&)));
    connect(m_geoCoder, SIGNAL(geocodeResultReceived(QVariantList,QString&)), this, SLOT(handleGeocoderResults(QVariantList,QString&)));
    m_geoCoder->geocode(request);
}


void googleMaps::GoogleMaps::geocodeLatLng(googleMaps::LatLng latLng) {
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
    qDebug() << "[GoogleMaps] handleGeocoderResults " << results.size();
    emit geoLocationsReceived();
}

void googleMaps::GoogleMaps::handleDistanceResults(qreal distance) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handlePositionResults(googleMaps::LatLng position) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleMaxZoomResults(googleMaps::MaxZoomResult result, int status) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleElevationResults(QList<googleMaps::ElevationResult> results, int status) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleAreaComputed(qreal area) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleHeadingComputed(qreal heding) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleDistanceComputed(qreal distance) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleGeoLocationReceived(googleMaps::GeocoderResult &result) {
    qDebug() << "[GeoWorldBuilder]   GeoLocation Received ";
//     disconnect(m_viewer, SIGNAL(geoCoderResponseReceived(googleMaps::GeocoderResult&)), this, SLOT(handleGeoLocationReceived(googleMaps::GeocoderResult&)));
//     disconnect(m_viewer, SIGNAL(selectGeoLocationRequest(QList<googleMaps::GeocoderResult>&)), this, SLOT(handleSelectGeoLocationRequest(QList<googleMaps::GeocoderResult>&)));
}

void googleMaps::GoogleMaps::handleSelectGeoLocationRequest(QList<googleMaps::GeocoderResult>& results)
{
    qDebug() << "[GeoWorldBuilder] need2  SelectGeoLocationRequest ";
//    disconnect(m_viewer, SIGNAL(geoCoderResponseReceived(googleMaps::GeocoderResult&)), this, SLOT(handleGeoLocationReceived(googleMaps::GeocoderResult&)));
//    disconnect(m_viewer, SIGNAL(selectGeoLocationRequest(QList<googleMaps::GeocoderResult>&)), this, SLOT(handleSelectGeoLocationRequest(QList<googleMaps::GeocoderResult>&)));
}

void googleMaps::GoogleMaps::handleLengthComputed(qreal length) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleOffsetComputed(googleMaps::LatLng offset) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleOffsetOriginComputed(googleMaps::LatLng offsetOrigin) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handlePositionInterpolated(googleMaps::LatLng originOffset) {
    throw "Not yet implemented";
}

void googleMaps::GoogleMaps::handleMaxZoomReceived(qreal zoomLevel) {
    throw "Not yet implemented";
}

QVariantList googleMaps::GoogleMaps::getGeoCoderResults()
{
    return m_geoCoder->getResults();
}
