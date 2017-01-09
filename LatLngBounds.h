#include <exception>
using namespace std;

#ifndef __LatLngBounds_h__
#define __LatLngBounds_h__

#include "LatLng.h"

#define CARDINAL_EAST "east"
#define CARDINAL_WEST "west"
#define CARDINAL_SOUTH "south"
#define CARDINAL_NORTH "north"

namespace googleMaps
{

		class LatLng;
		class LatLngBounds;
}

namespace googleMaps
{

        class LatLngBounds : public QObject
		{
            Q_OBJECT
            Q_PROPERTY(googleMaps::LatLng nwPoint READ getNorthWest WRITE setNWPoint NOTIFY nwPointChanged)
            Q_PROPERTY(googleMaps::LatLng sePoint READ getSouthEast WRITE setSEPoint NOTIFY sePointChanged)
            Q_PROPERTY(googleMaps::LatLng nePoint READ getNorthEast WRITE setNEPoint NOTIFY nePointChanged)
            Q_PROPERTY(googleMaps::LatLng swPoint READ getSouthWest WRITE setSWPoint NOTIFY swPointChanged)
            Q_PROPERTY(googleMaps::LatLng centerPoint READ getCenter WRITE setCenter NOTIFY centerChanged)

            protected:
                googleMaps::LatLng m_nwPoint;
                googleMaps::LatLng m_sePoint;
                googleMaps::LatLng m_nePoint;
                googleMaps::LatLng m_swPoint;
                qreal m_east;
                qreal m_west;
                qreal m_north;
                qreal m_south;
                googleMaps::LatLng m_centerPoint;


            public:
                explicit LatLngBounds(QObject *parent = 0);
                LatLngBounds(googleMaps::LatLng se, googleMaps::LatLng nw, QObject *parent = 0);
                //copy constructor
                LatLngBounds(const LatLngBounds& rhs);

                //assignment operator
                googleMaps::LatLngBounds& operator=(const LatLngBounds &rhs);

                bool containsBounds(googleMaps::LatLngBounds bounds);

                bool containsLatLng(googleMaps::LatLng location);

                googleMaps::LatLng getCenter() const;

                void setCenter(const googleMaps::LatLng center);

                qreal& getEast();

                qreal& getNorth();

                googleMaps::LatLng getNorthEast() const;

                googleMaps::LatLng getNorthWest() const;

                qreal &getSouth();

                googleMaps::LatLng getSouthEast() const;

                googleMaps::LatLng getSouthWest() const;

                qreal& getWest() const;

                bool intersects(googleMaps::LatLngBounds aParam0);

                bool isEmpty();

                bool isFullLat();

                bool isFullLng();

                bool isLargerThan(googleMaps::LatLngBounds aParam0);

                googleMaps::LatLng toSpan();

                QString toString();

                void Union(googleMaps::LatLngBounds aParam0);

                void setNWPoint(const googleMaps::LatLng nwPoint);

                void setSWPoint(const googleMaps::LatLng swPoint);

                void setSEPoint(const googleMaps::LatLng sePoint);

                void setNEPoint(const googleMaps::LatLng nePoint);
                void setEast(qreal east);

                void setNorth(qreal north);
                void setSouth(qreal south);
                void setWest(qreal west);
                void deserialize(const QVariantMap& data);

            signals:
                void nwPointChanged(bool modified);
                void sePointChanged(bool modified);
                void nePointChanged(bool modified);
                void swPointChanged(bool modified);
                void centerChanged(bool modified);

		};
}

Q_DECLARE_METATYPE(googleMaps::LatLngBounds)

#endif
