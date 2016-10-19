#ifndef GOOGLEMAPS_PLUGIN_H
#define GOOGLEMAPS_PLUGIN_H

#include <QQmlExtensionPlugin>
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


class GoogleMapsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // GOOGLEMAPS_PLUGIN_H
