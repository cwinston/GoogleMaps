#include <exception>
using namespace std;
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include "Geocoder.h"
#include "GeocoderResult.h"
#include "GeocoderRequest.h"
#include "LatLng.h"
#include <QDebug>

googleMaps::Geocoder::Geocoder(QObject *parent) {
}

void googleMaps::Geocoder::geocode(const googleMaps::GeocoderRequest aRequest)
{
     qDebug() << "[GEOCODER] sending request " << aRequest.getAddress();
    emit sendGeocoderRequest(aRequest);
     emit test(aRequest.getAddress());
}

void googleMaps::Geocoder::setRequestResults(QVariantList results, QString status)
{
   // qDebug() << "[GEOCODER] set results " << results << "  num results " << results.size();
    m_results = results;
    emit geocodeResultReceived(results, status);
}

googleMaps::GeocoderRequest googleMaps::Geocoder::createGeocoderRequest(const QString& location)
{
    GeocoderRequest request = GeocoderRequest();
    request.setAddress(location);
    return request;
}

googleMaps::GeocoderRequest googleMaps::Geocoder::createGeocoderRequest(const googleMaps::LatLng& latLng)
{
    GeocoderRequest request = GeocoderRequest();
    request.setLocation(latLng);
    return request;
}

QVariantList googleMaps::Geocoder::getResults() const {
    return this->m_results;
}

googleMaps::GeocoderRequest googleMaps::Geocoder::getLastRequest()
{
    return m_lastRequest;
}

