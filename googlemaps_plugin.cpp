#include "googlemaps_plugin.h"
#include "GeocoderRequest.h"
#include "GeocoderResult.h"
#include "LatLng.h"
#include "LatLngBounds.h"
#include "GeocoderComponentRestrictions.h"
#include "GeocoderAddressComponent.h"
#include "GeocoderGeometry.h"
#include "SphericalGeometry.h"
#include "MaxZoomService.h"

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
}

