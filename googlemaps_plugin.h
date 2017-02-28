#ifndef GOOGLEMAPS_PLUGIN_H
#define GOOGLEMAPS_PLUGIN_H


#include <qqml.h>
#include "GeocoderRequest.h"
#include "GeocoderResult.h"
#include "LatLng.h"
#include "LatLngBounds.h"
#include "GeocoderComponentRestrictions.h"
#include "GeocoderAddressComponent.h"
#include "GeocoderGeometry.h"
#include "SphericalGeometry.h"
#include "MaxZoomService.h"
#include "Geocoder.h"
#include "ElevationService.h"
#include "GoogleMaps.h"
#include "Map.h"
#include "Marker.h"
#include "MarkerOptions.h"
#include "Size.h"
#include "Point.h"
#include "Polygon.h"
#include "PolygonOptions.h"


class GoogleMapsPlugin : public googleMaps::MapsInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "googleMaps.MapsInterface")

public:
    void registerTypes(const char *uri);
    virtual void computeArea(const QList<googleMaps::LatLng>& path);
    virtual void computeDistanceBetween(const googleMaps::LatLng& from, const googleMaps::LatLng& to);
    virtual void computeHeading(const googleMaps::LatLng& from, const googleMaps::LatLng& to);
    virtual void computeLength(const QList<googleMaps::LatLng>& path);
    virtual void computeOffset(const googleMaps::LatLng& from, const qreal& distance, const qreal& heading);
    virtual void computeOffsetOrigin(const googleMaps::LatLng& to, const qreal& distance, const qreal& heading);
    virtual void interpolate(googleMaps::LatLng& from, googleMaps::LatLng& to, qreal& fraction);
    virtual void centerMapAt(googleMaps::LatLng newCenter);
    virtual void getMaxZoomAtLatLng(googleMaps::LatLng latLng);
    virtual void geocodeName(QString location);
    virtual void geocodeLatLng(googleMaps::LatLng latLng);
    virtual void getElevationAlongPath(googleMaps::PathElevationRequest request);
    virtual void getElevationForLocations(googleMaps::LocationElevationRequest request);
    virtual void messageReceived(const QJsonObject& message);
   // virtual void handleGeocoderResults(QVariantList results, QString &status);
    //virtual void handleMaxZoomResults(googleMaps::MaxZoomResult result, int status);
    //virtual void handleElevationResults(QList<googleMaps::ElevationResult> results, int status);
};

#endif // GOOGLEMAPS_PLUGIN_H
