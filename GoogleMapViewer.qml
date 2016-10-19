import QtQuick 2.5
import QtWebEngine 1.3
import QtWebChannel 1.0
import GoogleMaps 1.0

Item
{
    WebEngineView
    {
        id:webview
        width: parent.width
        height: parent.height
        url: "maptest.html"

         onLoadingChanged: {
             console.log("  loading changed  isloading  "+loading)

             console.log("  channel ready?   "+mapController.connectionMade)
             console.log("  webChannel transports  "+webChannel.transports[0]);
             if (!mapController.connectionMade)
             {
                mapController.channel = webview.webChannel;
             }
         }

         onLoadProgressChanged: {
              console.log("  loadProgress  "+webview.loadProgress)
         }
    }

    GoogleMaps
    {
        id:mapController

    }

    function geocode(location)
    {
        mapController.geocode(location);
    }
}
