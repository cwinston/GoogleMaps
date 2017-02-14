TEMPLATE = lib
QT += qml quick webchannel webengine webenginewidgets
CONFIG += qt plugin c++11 debug static

TARGET = GoogleMapsPlugin
uri = GoogleMaps

# Input
SOURCES += \
    googlemaps_plugin.cpp \
    ElevationResult.cpp \
    ElevationService.cpp \
    GeoAddressComponentsModel.cpp \
    Geocoder.cpp \
    GeocoderAddressComponent.cpp \
    GeocoderComponentRestrictions.cpp \
    GeocoderGeometry.cpp \
    GeocoderRequest.cpp \
    GeocoderResult.cpp \
    LatLng.cpp \
    LatLngBounds.cpp \
    LocationElevationRequest.cpp \
    MaxZoomResult.cpp \
    MaxZoomService.cpp \
    PathElevationRequest.cpp \
    SphericalGeometry.cpp \
    GoogleMaps.cpp \
    Map.cpp \
    MapOptions.cpp \
    Marker.cpp \
    MarkerOptions.cpp \
    Point.cpp \
    Size.cpp \
    LatLngValidator.cpp

HEADERS += \
    googlemaps_plugin.h \
    ElevationResult.h \
    ElevationService.h \
    GeoAddressComponentsModel.h \
    Geocoder.h \
    GeocoderAddressComponent.h \
    GeocoderComponentRestrictions.h \
    GeocoderGeometry.h \
    GeocoderRequest.h \
    GeocoderResult.h \
    LatLng.h \
    LatLngBounds.h \
    LocationElevationRequest.h \
    MaxZoomResult.h \
    MaxZoomService.h \
    PathElevationRequest.h \
    SphericalGeometry.h \
    qtutils.h \
    GoogleMaps.h \
    Map.h \
    MapOptions.h \
    Marker.h \
    MarkerOptions.h \
    Point.h \
    Size.h \
    LatLngValidator.h


pluginfiles.files += \
    qmldir \
    GoogleMapViewer.qml \


RESOURCES += qml.qrc

DISTFILES = qmldir

DESTDIR = ../../plugins/googleMaps

qml.files = *.qml
qml.path = $$DESTDIR
target.path = /googleMaps
pluginfiles.path += $$[QT_INSTALL_QML]/qml/qmlextensionplugins/imports/GoogleMaps

OTHER_FILES += qmldir

INSTALLS += target qml pluginfiles


qmldir.files = qmldir

# Copy the qmldir file to the same folder as the plugin binary
cpqmldir.files = qmldir
cpqmldir.path = $$DESTDIR
COPIES += cpqmldir


unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
