#ifndef GOOGLEMAPS_PLUGIN_H
#define GOOGLEMAPS_PLUGIN_H

#include <QQmlExtensionPlugin>

class GoogleMapsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // GOOGLEMAPS_PLUGIN_H
