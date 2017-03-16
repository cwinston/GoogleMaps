/*
 *
 *  Needs to expose all the signals and slots from MapViewer
 *
 *
 *
 */

#ifndef GOOGLEMAPS_H
#define GOOGLEMAPS_H

#include <QObject>
#include <QQmlExtensionPlugin>
#include <QWebChannelAbstractTransport>
#include <QWebChannel>
#include <QTimer>
#include "GeocoderRequest.h"
#include "GeocoderComponentRestrictions.h"
#include "GeocoderAddressComponent.h"
#include "GeocoderGeometry.h"
#include "SphericalGeometry.h"
#include "MaxZoomService.h"
#include "Geocoder.h"
#include "LatLng.h"
#include "GeocoderResult.h"
#include "ElevationService.h"
#include "Map.h"

namespace googleMaps
{
    class GoogleMaps;
    class Geocoder;
    class LatLng;
    class Map;
    class SphericalGeometry;
    class ElevationService;
    class MaxZoomService;
    class PathElevationRequest;
    class LocationElevationRequest;
}


namespace googleMaps
{

    struct MapsInterface : public QQmlExtensionPlugin
    {
        virtual void computeArea(const QList<googleMaps::LatLng>& path) = 0;
        virtual void computeDistanceBetween(const googleMaps::LatLng& from, const googleMaps::LatLng& to) = 0;
        virtual void computeHeading(const googleMaps::LatLng& from, const googleMaps::LatLng& to) = 0;
        virtual void computeLength(const QList<googleMaps::LatLng>& path) = 0;
        virtual void computeOffset(const googleMaps::LatLng& from, const qreal& distance, const qreal& heading) = 0;
        virtual void computeOffsetOrigin(const googleMaps::LatLng& to, const qreal& distance, const qreal& heading) = 0;
        virtual void interpolate(googleMaps::LatLng& from, googleMaps::LatLng& to, qreal& fraction) = 0;
        virtual void centerMapAt(googleMaps::LatLng newCenter) = 0;
        virtual void getMaxZoomAtLatLng(googleMaps::LatLng latLng) = 0;
        virtual void geocodeName(QString location) = 0;
        virtual void geocodeLatLng(googleMaps::LatLng latLng) = 0;
        virtual void getElevationAlongPath(googleMaps::PathElevationRequest request) = 0;
        virtual void getElevationForLocations(googleMaps::LocationElevationRequest request) = 0;
        virtual void messageReceived(const QJsonObject& message) = 0;
      //  virtual void handleGeocoderResults(QVariantList results, QString &status) = 0;
      //  virtual void handleMaxZoomResults(googleMaps::MaxZoomResult result, int status) = 0;
      //  virtual void handleElevationResults(QList<googleMaps::ElevationResult> results, int status) = 0;
    };

    class GoogleMaps : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QWebChannel* channel READ getChannel WRITE setChannel NOTIFY transportReady)
        Q_PROPERTY(bool connectionMade READ isConnected NOTIFY transportReady)
        Q_PROPERTY(QVariantList geocoderResults READ getGeoCoderResults NOTIFY geoLocationsReceived)
        Q_PROPERTY(googleMaps::LatLng positionResult READ getPositionResult NOTIFY positionResultsReceived)
        Q_PROPERTY(qreal distnceResult READ getDistanceResult NOTIFY distanceResultsReceived)
        Q_PROPERTY(QString mapsKey READ getMapKey WRITE setMapsKey)

    public:
        explicit GoogleMaps(QObject *parent = 0);
        ~GoogleMaps();

        QWebChannel* getChannel() const;
        void setChannel(QWebChannel *chnl);
        bool isConnected();
        QVariantList getGeoCoderResults() const;
        qreal getDistanceResult() const;
        googleMaps::LatLng getPositionResult() const;
        QString getMapKey() const;

    protected:
        googleMaps::Geocoder* m_geoCoder;
        googleMaps::SphericalGeometry* m_sphericalGeometryService;
        googleMaps::MaxZoomService* m_maxZoomService;
        googleMaps::ElevationService* m_elevationService;
        googleMaps::Map* m_map;
        QWebChannel* m_channel;
        bool m_transportReady;
        QString m_mapsKey;



    signals:
            void distanceResultsReceived();
            void positionResultsReceived();
            void boundsChanged(googleMaps::LatLngBounds bounds);
            void centerChanged(googleMaps::LatLng position);
            void zoomChanged(qreal zoomLevel);
            void maxZoomReceived(qreal zoomLevel);
            void elevationResultsReceived(QList<googleMaps::ElevationResult> results);
            void sendMessage(const QJsonObject &message);
            void geoLocationsReceived();
            void transportReady();
            void markerCreated(googleMaps::Marker marker);
            void markersCleared();
            void markerCleared();
            void polygonCreated();
            void polygonCleared();

    public slots:
            /// <summary>
            ///
            /// Return Value:  number
            /// Return unit: meters
            /// Returns the area of a closed path. The computed area uses the same units as the radius. The radius defaults to the Earth's radius in meters, in which case the area is in square meters.
            /// </summary>
            void computeArea(const QList<googleMaps::LatLng>& path);

            /// <summary>
            ///
            /// Return Value:  number
            /// Returns the distance, in meters, between two LatLngs. You can optionally specify a custom radius. The radius defaults to the radius of the Earth.
            /// </summary>
            void computeDistanceBetween(const googleMaps::LatLng& from, const googleMaps::LatLng& to);

            /// <summary>
            ///
            /// Return Value:  number
            /// Returns the heading from one LatLng to another LatLng. Headings are expressed in degrees clockwise from North within the range [-180,180).
            /// </summary>
            void computeHeading(const googleMaps::LatLng& from, const googleMaps::LatLng& to);

            /// <summary>
            ///
            /// Return Value:  number
            /// Returns the length of the given path.
            /// </summary>
            void computeLength(const QList<googleMaps::LatLng>& path);

            /// <summary>
            ///
            /// Return Value:  LatLng
            /// Returns the LatLng resulting from moving a distance from an origin in the specified heading (expressed in degrees clockwise from north).
            /// </summary>
            void computeOffset(const googleMaps::LatLng from, const qreal distance, const qreal heading);

            /// <summary>
            /// Returns the location of origin when provided with a LatLng destination, meters travelled and original heading. Headings are expressed in degrees clockwise from North. This function returns null when no solution is available.
            /// </summary>
            void computeOffsetOrigin(const googleMaps::LatLng to, const qreal distance, const qreal heading);

            /// <summary>
            /// Returns the LatLng which lies the given fraction of the way between the origin LatLng and the destination LatLng.
            /// </summary>
            void interpolate(googleMaps::LatLng& from, googleMaps::LatLng& to, qreal& fraction);
            void centerMapAt(googleMaps::LatLng newCenter);
            void getMaxZoomAtLatLng(googleMaps::LatLng latLng);
            void geocodeName(QString location);
            void geocodeLatLng(googleMaps::LatLng latLng);
            void getElevationAlongPath(googleMaps::PathElevationRequest request);
            void getElevationForLocations(googleMaps::LocationElevationRequest request);
            void messageReceived(const QJsonObject& message);
            void handleGeocoderResults(QVariantList results, QString &status);
            void handleMaxZoomResults(googleMaps::MaxZoomResult result, int status);
            void handleElevationResults(QList<googleMaps::ElevationResult> results, int status);
            void setMapsKey(const QString key);
            void updateMapOptions(const googleMaps::MapOptions options);
            void addMarker(googleMaps::MarkerOptions option);
            void clearMarker(googleMaps::LatLng position);
            void clearMarkers();
            googleMaps::Marker createMarker(const googleMaps::MarkerOptions options = MarkerOptions());
            void addPolygon(googleMaps::PolygonOptions options);
            void clearPolygon(googleMaps::PolygonOptions options);
            void clearPolygons();
            void zoomInRequest();
            void zoomOutRequest();


        private slots:
            void handleMaxZoomReceived(qreal zoomLevel);
            void handleDistanceResults(qreal distance);
            void handlePositionResults(googleMaps::LatLng position);


    };
}
Q_DECLARE_INTERFACE(googleMaps::MapsInterface, "googleMaps.MapsInterface")
#endif // GOOGLEMAPS_H
