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
        enum ECardinalPositions;
}

namespace googleMaps
{

        enum ECardinalPositions
        {
            POS_NORTH = 0,
            POS_NORTH_EAST,
            POS_EAST,
            POS_SOUTH_EAST,
            POS_SOUTH,
            POS_SOUTH_WEST,
            POS_WEST,
            POS_NORTH_WEST,
            POS_CENTER

        };

        class LatLngBounds : public QObject
		{
            Q_OBJECT
            Q_PROPERTY(googleMaps::LatLng nwPoint READ getNorthWest WRITE setNWPoint NOTIFY boundsChanged)
            Q_PROPERTY(googleMaps::LatLng sePoint READ getSouthEast WRITE setSEPoint NOTIFY boundsChanged)
            Q_PROPERTY(googleMaps::LatLng nePoint READ getNorthEast WRITE setNEPoint NOTIFY boundsChanged)
            Q_PROPERTY(googleMaps::LatLng swPoint READ getSouthWest WRITE setSWPoint NOTIFY boundsChanged)
            Q_PROPERTY(googleMaps::LatLng northPoint READ getNorth WRITE setNorth NOTIFY boundsChanged)
            Q_PROPERTY(googleMaps::LatLng southPoint READ getSouth WRITE setSouth NOTIFY boundsChanged)
            Q_PROPERTY(googleMaps::LatLng eastPoint READ getEast WRITE setEast NOTIFY boundsChanged)
            Q_PROPERTY(googleMaps::LatLng westPoint READ getWest WRITE setWest NOTIFY boundsChanged)
            Q_PROPERTY(googleMaps::LatLng centerPoint READ getCenter WRITE setCenter NOTIFY boundsChanged)
            Q_ENUMS(ECardinalPositions)

            protected:
                googleMaps::LatLng m_nwPoint;
                googleMaps::LatLng m_sePoint;
                googleMaps::LatLng m_nePoint;
                googleMaps::LatLng m_swPoint;
                googleMaps::LatLng m_east;
                googleMaps::LatLng m_west;
                googleMaps::LatLng m_north;
                googleMaps::LatLng m_south;
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

                LatLng getEast() const;

                LatLng getNorth() const;

                googleMaps::LatLng getNorthEast() const;

                googleMaps::LatLng getNorthWest() const;

                LatLng getSouth() const;

                googleMaps::LatLng getSouthEast() const;

                googleMaps::LatLng getSouthWest() const;

                LatLng getWest() const;

                QString toString();


                void setNWPoint(const googleMaps::LatLng nwPoint);
                void setSWPoint(const googleMaps::LatLng swPoint);
                void setSEPoint(const googleMaps::LatLng sePoint);
                void setNEPoint(const googleMaps::LatLng nePoint);
                void setEast(const googleMaps::LatLng east);
                void setNorth(const googleMaps::LatLng north);
                void setSouth(const googleMaps::LatLng south);
                void setWest(const googleMaps::LatLng west);
                void deserialize(const QVariantMap& data);

            signals:
                void boundsChanged(googleMaps::ECardinalPositions position);

		};
}

Q_DECLARE_METATYPE(googleMaps::LatLngBounds)

#endif
