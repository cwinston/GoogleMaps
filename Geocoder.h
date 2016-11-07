#include <exception>
using namespace std;

#ifndef __Geocoder_h__
#define __Geocoder_h__
#include <QObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include "qtutils.h"
#include "GeocoderResult.h"
#include "GeocoderRequest.h"
#include "LatLng.h"
//#include "AbstractGoogleMapsService.h"


namespace googleMaps
{
    class GeocoderResult;
    class GeocoderRequest;
     enum GeocoderStatus;
    class LatLng;
    class Geocoder;
    //class AbstractGoogleMapsService;
}

namespace googleMaps
{
    enum EGeocoderStatus
    {
        GEOCODER_ERROR = 0,
        GEOCODER_INVALID_REQUEST,
        GEOCODER_OK,
        GEOCODER_OVER_QUERY_LIMIT,
        GEOCODER_REQUEST_DENIED,
        GEOCODER_UNKNOWN_ERROR,
        ZERO_RESULTS
    };

    class Geocoder : public QObject
    {
        Q_OBJECT
          Q_PROPERTY(QVariantList results READ getResults NOTIFY resultsChanged)
          Q_PROPERTY(googleMaps::GeocoderRequest request READ getLastRequest NOTIFY requestChanged)
       // Q_PROPERTY(googleMaps::GeocoderResult result READ getResult)
      //  Q_PROPERTY(googleMaps::GeocoderRequest request READ getLastRequest)
       // Q_ENUMS(EGeocoderStatus)
        protected:
            QVariantList m_results;
            googleMaps::GeocoderRequest m_lastRequest;

        public:
            explicit Geocoder(QObject* parent = 0);
            Geocoder(const googleMaps::Geocoder &rhs, QObject* parent = 0);
            static googleMaps::GeocoderRequest createGeocoderRequest(const QString& location);
            static googleMaps::GeocoderRequest createGeocoderRequest(const googleMaps::LatLng& latLng);
            void geocode(googleMaps::GeocoderRequest aRequest);
            QVariantList getResults() const;
            GeocoderRequest getLastRequest();


        signals:
            void geocodeResultReceived(QVariantList results, QString& status);
            void sendGeocoderRequest(googleMaps::GeocoderRequest request);
            void requestChanged(googleMaps::GeocoderRequest request);
            void resultsChanged(googleMaps::GeocoderResult result);
            void test(QString msg);

        public slots:
            Q_INVOKABLE void setRequestResults(QVariantList results, QString status);
    };

}

Q_DECLARE_METATYPE(googleMaps::Geocoder)
#endif
