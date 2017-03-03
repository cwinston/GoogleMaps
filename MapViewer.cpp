#include <exception>
using namespace std;

#include "MapViewer.h"
#include <QWebChannelAbstractTransport>
#include <QWebChannel>
#include <QtWebEngine/QtWebEngine>
#include <QJsonDocument>
#include "Geocoder.h"
#include "SphericalGeometry.h"
#include "MaxZoomService.h"
#include "ElevationService.h"
#include "LatLng.h"
#include "GeocoderResult.h"
#include "ElevationResult.h"

googleMaps::MapViewer::MapViewer(QWidget *parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

     //setFlag(ItemHasContents, true);

    qDebug() << "starting mapViewer ";

    QWebEnginePage* mapPage = page();
    m_geoCoder = new googleMaps::Geocoder();
   // m_channel->registerObject(QStringLiteral("Geocoder"), m_geoCoder);

  //  qDebug() << "channel transport " << m_channel << m_geoCoder;

}



void googleMaps::MapViewer::computeArea(const QList<googleMaps::LatLng>& path) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::computeDistanceBetween(const googleMaps::LatLng& from, const googleMaps::LatLng& to) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::computeHeading(const googleMaps::LatLng& from, const googleMaps::LatLng& to) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::computeLength(const QList<googleMaps::LatLng>& path) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::computeOffset(const googleMaps::LatLng& from, const qreal& distance, const qreal& heading) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::computeOffsetOrigin(const googleMaps::LatLng& to, const qreal& distance, const qreal& heading) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::interpolate(googleMaps::LatLng& from, googleMaps::LatLng& to, qreal& fraction) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::getMaxZoomAtLatLng(googleMaps::LatLng latLng) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::geocode(QString& location)
{
    googleMaps::GeocoderRequest request = googleMaps::Geocoder::createGeocoderRequest(location);
    connect(m_geoCoder, SIGNAL(geocodeResultReceived(QList<googleMaps::GeocoderResult>&,QString&)), this, SLOT(handleGeocoderResults(QList<googleMaps::GeocoderResult>&,QString&)));
    m_geoCoder->geocode(request);
}


void googleMaps::MapViewer::geocode(googleMaps::LatLng& latLng) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::getElevationAlongPath(googleMaps::PathElevationRequest request) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::getElevationForLocations(googleMaps::LocationElevationRequest request) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::messageReceived(const QJsonObject& message)
{
     QJsonDocument doc(message);

    QString strJson(doc.toJson(QJsonDocument::Compact));
    //QVariantMap messageMap = message.toVariantMap();
    qDebug() << " Json message received " << strJson;
}

void googleMaps::MapViewer::updateGeocoderResults(QList<googleMaps::GeocoderResult>& results, QString& status)
{
    qDebug() << "[MapViewer] handleGeocoderResults " << results.size();
    if (results.size() == 1)
    {
        emit geoCoderResponseReceived(results.at(0));
    }
    else if (results.size() > 1)
    {
        emit selectGeoLocationRequest(results);
    }
}

void googleMaps::MapViewer::updateDistanceResults(qreal distance) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::updatePositionResults(googleMaps::LatLng position) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::updateMaxZoomResults(googleMaps::MaxZoomResult result, int status) {
	throw "Not yet implemented";
}

void googleMaps::MapViewer::updateElevationResults(QList<googleMaps::ElevationResult> results, int status) {
	throw "Not yet implemented";
}

