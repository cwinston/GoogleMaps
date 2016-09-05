TEMPLATE = lib
TARGET = GoogleMaps
QT += qml quick webchannel webengine
CONFIG += qt plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = GoogleMaps

# Input
SOURCES += \
    googlemaps_plugin.cpp \
    googlemaps.cpp \
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
    SphericalGeometry.cpp

HEADERS += \
    googlemaps_plugin.h \
    googlemaps.h \
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
    qtutils.h

DISTFILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
