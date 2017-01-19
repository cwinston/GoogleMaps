import QtQuick 2.5
import QtWebEngine 1.3
import QtWebChannel 1.0
import GoogleMaps 1.0

Item
{
    signal connectionReady();
    signal mapReady();
    signal geocoderLocationsReceived(variant results);
    signal distanceResultsReceived(real distance);
    signal positionResultsReceived(LatLng position);
    property bool isMapReady: false;
    property string mapsKey: "";

    WebEngineView
    {
        id:webview
        width: parent.width
        height: parent.height
        url: "maptest.html?key="+mapsKey

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
             webview.loadHtml("https://maps.googleapis.com/maps/api/js?v=3&library=geometry&key="+mapsKey)
             webview.url = "maptest.html?key="+mapsKey;
             //webview.url = "https://maps.googleapis.com/maps/api/js?v=3&library=geometry&key="+mapsKey;
             console.log("map key "+mapsKey);
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

    }

    function geocodeName(locationName)
    {
        console.log("[GoogleMapsViewer]  computeOffset ")
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
        console.log("[GoogleMapsViewer]  computeOffset ")
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
