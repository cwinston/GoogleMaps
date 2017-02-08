import QtQuick 2.5
import QtWebEngine 1.3
import QtWebChannel 1.0
import GoogleMaps 1.0

Item
{
    signal connectionReady();
    signal mapReady();
    signal geocoderLocationsReceived(variant results);
    signal distanceResultReceived(variant distance);
    signal positionResultReceived(variant position);
    signal mapZoomChanged(variant level);
    signal mapCenterChanged(variant position);
    signal mapBoundsChanged(variant bounds);
    property bool isMapReady: false;
    property string mapsKey: "";

    WebEngineView
    {
        id:webview
        width: parent.width
        height: parent.height
        url: "maptest.html"

         onLoadingChanged: {
             console.log("  loading changed  isloading  "+loading);
             if (!mapController.connectionMade)
             {
                 console.log("  channel ready?   "+mapController.connectionMade)
                 console.log("  webChannel transports  "+webChannel.transports[0]);
                mapController.channel = webview.webChannel;
             }
         }

         onLoadProgressChanged: {
              console.log("  loadProgress  "+webview.loadProgress)
             if ((webview.loadProgress == 100) && !isMapReady)
             {
                 console.log("map ready ");
                 isMapReady = true;
                 mapReady();
             }
         }

         Component.onCompleted:
         {
             webview.url = "maptest.html?key="+mapsKey;
             mapController.setMapsKey(mapsKey);
         }
    }

    GoogleMaps
    {
        id:mapController

        onTransportReady:
        {
            connectionReady();
        }

        onGeoLocationsReceived:
        {
            geocoderLocationsReceived(mapController.geocoderResults);
        }

        onDistanceResultsReceived:
        {
            distanceResultsReceived(mapController.distanceResult);
        }

        onPositionResultsReceived:
        {
            console.log("position result in  "+mapController.positionResult)
            positionResultReceived(mapController.positionResult);
        }

        onCenterChanged:
        {
            console.log("[MAPVIEWER] center changed "+position);
            mapCenterChanged(position);
        }

        onZoomChanged:
        {
            console.log("[MAPVIEWER] zoom changed "+zoomLevel);
            mapZoomChanged(zoomLevel);
        }

        onBoundsChanged:
        {
            console.log("[MAPVIEWER] bounds changed "+bounds);
            mapBoundsChanged(bounds);
        }

    }

    function geocodeName(locationName)
    {
        mapController.geocodeName(locationName);

    }

    function geocodeLocation(location)
    {
        mapController.geocodeLatLng(location);
    }

    function computeArea(path)
    {
        mapController.computeArea(path);
    }

    function computeDistanceBetween(from, to)
    {
        mapController.computeDistanceBetween(from, to);
    }

    function computeLength(path)
    {
        mapController.computeLength(path);
    }

    function computeHeading(from, to)
    {
        mapController.computeHeading(from, to)
    }

    function computeOffset(from, distance, heading)
    {
        //console.log("[GoogleMapsViewer]  computeOffset ")
        mapController.computeOffset(from, distance, heading);
    }

    function computeOffsetOrigin(to, distance, heading)
    {
        mapController.computeOffsetOrigin(to, distance, heading);
    }

    function interpolate(from, to, fraction)
    {
        mapController.interpolate(from, to, fraction);
    }

    function centerMapAt(location)
    {
        console.log("[GMV] centerMapAt  "+location);
        mapController.centerMapAt(location);
    }
}
