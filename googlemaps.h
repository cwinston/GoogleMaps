#ifndef GOOGLEMAPS_H
#define GOOGLEMAPS_H

#include <QQuickItem>

class GoogleMaps : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(GoogleMaps)

public:
    GoogleMaps(QQuickItem *parent = 0);
    ~GoogleMaps();
};

#endif // GOOGLEMAPS_H
