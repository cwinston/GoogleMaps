#include <exception>
using namespace std;
#include <QObject>
#include "LatLngValidator.h"

#ifndef __LatLng_h__
#define __LatLng_h__

#define GEO_LAT "lat"
#define GEO_LNG "lng"
#define DIRECTION_NORTH "North"
#define DIRECTION_SOUTH "South"
#define DIRECTION_EAST "East"
#define DIRECTION_WEST "West"

namespace googleMaps
{
    class LatLng;
    class LatLngValidator;
    enum ECardinalPoints;
}

namespace googleMaps
{
        enum ECardinalPoints
        {
            DIR_NORTH = 0,
            DIR_EAST = 90,
            DIR_SOUTH = 180,
            DIR_WEST = 270
        };

        class LatLng : public QObject
		{
            Q_OBJECT
            Q_PROPERTY(qreal lat READ lat WRITE setLat NOTIFY latChanged)
            Q_PROPERTY(qreal lng READ lng WRITE setLng NOTIFY lngChanged)
            Q_ENUMS(ECardinalPoints)
            public:
                explicit LatLng(QObject* parent = 0);
                LatLng(qreal lat, qreal lng);
                //copy constructor
                LatLng(const LatLng& rhs);
                //assignment operator
                LatLng& operator=(const LatLng &rhs);
                virtual ~LatLng();
                static bool isValidLatLng(const LatLng &position);
                void setLat(const qreal lat);
                void setLng(const qreal lng);
                Q_INVOKABLE qreal lat() const;
                Q_INVOKABLE qreal lng() const;
                QString toString() const;
                QJsonObject toJSON();
                void deserialize(const QVariantMap& data);
                void deserialize(const QVariant& data);
                void reset();
                static QString directionToText(const googleMaps::ECardinalPoints dir);

             protected:
                qreal m_lat;
                qreal m_lng;
             signals:
                void latChanged(qreal m_lat);
                void lngChanged(qreal m_lng);
           //  public slots:
		};
}

Q_DECLARE_METATYPE(googleMaps::LatLng)

#endif
