#include <exception>
using namespace std;

#ifndef __MapViewer_h__
#define __MapViewer_h__

#include <QWebChannelAbstractTransport>
#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QWebChannel>
#include <QDebug>
#include <QQuickItem>

#include <QWebEngineView>

namespace googleMaps
{
	class Geocoder;
	class SphericalGeometry;
	class MaxZoomService;
	class ElevationService;
	class LatLng;
	class GeocoderResult;
	// enum EGeocoderStatus;
	class ElevationResult;
    class MapViewer;
}

namespace googleMaps
{
    class MapViewer: public QWebEngineView
	{
        Q_OBJECT
        Q_DISABLE_COPY(MapViewer)

    protected slots:



	};
}
   // Q_DECLARE_METATYPE(googleMaps::MapViewer)

#endif
