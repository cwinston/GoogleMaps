#include "googlemaps_plugin.h"
#include <qqml.h>

void GoogleMapsPlugin::registerTypes(const char *uri)
{
    // @uri google.maps
    Q_ASSERT(uri == QLatin1String("GoogleMaps"));
    qmlRegisterType<googleMaps::GeocoderComponentRestrictions>(uri, 1, 0, "GeocoderComponentRestrictions");
    qmlRegisterType<googleMaps::GeocoderAddressComponent>(uri, 1, 0, "GeocoderAddressComponent");
    qmlRegisterType<googleMaps::GeocoderGeometry>(uri, 1, 0, "GeocoderGeometry");
    qmlRegisterType<googleMaps::GeocoderRequest>(uri, 1, 0, "GeocoderRequest");
    qmlRegisterType<googleMaps::GeocoderResult>(uri, 1, 0, "GeocoderResult");
    qmlRegisterType<googleMaps::LatLng>(uri, 1, 0, "LatLng");
    qmlRegisterType<googleMaps::LatLngBounds>(uri, 1, 0, "LatLngBounds");
    qmlRegisterType<googleMaps::SphericalGeometry>(uri, 1, 0, "SphericalGeometry");
    qmlRegisterType<googleMaps::MaxZoomService>(uri, 1, 0, "MaxZoomService");
    qmlRegisterType<googleMaps::Geocoder>(uri, 1, 0, "Geocoder");
    qmlRegisterType<googleMaps::ElevationService>(uri, 1, 0, "ElevationService");
    qmlRegisterType<googleMaps::GoogleMaps>(uri, 1, 0, "GoogleMaps");
    qmlRegisterType<googleMaps::Map>(uri, 1, 0, "Map");
    qmlRegisterType<googleMaps::MapOptions>(uri, 1, 0, "MapOptions");
    qmlRegisterType<googleMaps::Marker>(uri, 1, 0, "Marker");
    qmlRegisterType<googleMaps::MarkerOptions>(uri, 1, 0, "MarkerOptions");
    qmlRegisterType<googleMaps::Size>(uri, 1, 0, "Size");
    qmlRegisterType<googleMaps::Point>(uri, 1, 0, "Point");
}

