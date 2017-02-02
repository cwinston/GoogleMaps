#include <exception>
using namespace std;

#include <QDebug>
#include "LatLngBounds.h"
#include "LatLng.h"

googleMaps::LatLngBounds::LatLngBounds(googleMaps::LatLng se, googleMaps::LatLng nw, QObject* parent):m_nwPoint(nw), m_sePoint(se) {
}

googleMaps::LatLngBounds::LatLngBounds(QObject* parent)
{
    setParent(parent);
}

//copy constructor
googleMaps::LatLngBounds::LatLngBounds(const LatLngBounds& rhs)
{
    m_sePoint = rhs.getSouthEast();
    m_nwPoint = rhs.getNorthWest();
    m_swPoint = rhs.getSouthWest();
    m_nePoint = rhs.getNorthEast();
    m_centerPoint = rhs.getCenter();
}

//assignment operator
googleMaps::LatLngBounds& googleMaps::LatLngBounds::operator=(const LatLngBounds &rhs)
{
    if(this == &rhs) {
        return *this;
    }
    m_sePoint = rhs.getSouthEast();
    m_nwPoint = rhs.getNorthWest();
    m_swPoint = rhs.getSouthWest();
    m_nePoint = rhs.getNorthEast();
    m_centerPoint = rhs.getCenter();
    return *this;
}

void googleMaps::LatLngBounds::setNWPoint(const googleMaps::LatLng nwPoint)
{
   m_nwPoint = nwPoint;
   emit nwPointChanged(true);
}

void googleMaps::LatLngBounds::setSEPoint(const googleMaps::LatLng sePoint)
{
    m_sePoint = sePoint;
    emit sePointChanged(true);
}

void googleMaps::LatLngBounds::setNEPoint(const googleMaps::LatLng nePoint)
{
    m_nePoint = nePoint;
    emit nePointChanged(true);
}

void googleMaps::LatLngBounds::setSWPoint(const googleMaps::LatLng swPoint)
{
    m_swPoint = swPoint;
    emit swPointChanged(true);
}

bool googleMaps::LatLngBounds::containsBounds(googleMaps::LatLngBounds bounds) {
	throw "Not yet implemented";
}

bool googleMaps::LatLngBounds::containsLatLng(googleMaps::LatLng location) {
	throw "Not yet implemented";
}


googleMaps::LatLng googleMaps::LatLngBounds::getCenter() const
{
    return m_centerPoint;
}

void googleMaps::LatLngBounds::setCenter(googleMaps::LatLng center)
{
    m_centerPoint = center;
}

googleMaps::LatLng googleMaps::LatLngBounds::getEast() const
{
    return m_east;
}

googleMaps::LatLng googleMaps::LatLngBounds::getNorth() const
{
    return m_north;
}

googleMaps::LatLng googleMaps::LatLngBounds::getNorthEast() const
{
    return m_nePoint;
}

googleMaps::LatLng googleMaps::LatLngBounds::getNorthWest() const
{
    return m_nwPoint;
}

googleMaps::LatLng googleMaps::LatLngBounds::getSouth() const
{
    return m_south;
}

googleMaps::LatLng googleMaps::LatLngBounds::getSouthEast() const
{
    return m_sePoint;
}

googleMaps::LatLng googleMaps::LatLngBounds::getSouthWest() const
{
    return m_swPoint;
}

QString googleMaps::LatLngBounds::toString()
{
	throw "Not yet implemented";
}

void googleMaps::LatLngBounds::setEast(const LatLng east)
{
    m_east = east;
    emit eastPointChanged(true);
}

void googleMaps::LatLngBounds::setNorth(const LatLng north)
{
    m_north = north;
    emit northPointChanged(true);
}

void googleMaps::LatLngBounds::setSouth(const LatLng south)
{
    m_south = south;
    emit southPointChanged(true);
}

void googleMaps::LatLngBounds::setWest(const LatLng west)
{
    m_west = west;
    emit westPointChanged(true);
}

googleMaps::LatLng googleMaps::LatLngBounds::getWest() const
{
    return m_west;
}

void googleMaps::LatLngBounds::deserialize(const QVariantMap& data)
{
    qDebug() << "[LatLngBounds] parse bounds result " << data << "\n";
     qDebug() << "[LatLngBounds]  bounds keys " << data.keys() << "\n";
     qreal eastPoint, westPoint, southPoint, northPoint;
     for (auto cPoint : data.keys())
     {
         if (cPoint == CARDINAL_EAST)
         {
             eastPoint = data[cPoint].toDouble();
         }
         else if (cPoint == CARDINAL_NORTH)
         {
             northPoint = data[cPoint].toDouble();
         }
         else if (cPoint == CARDINAL_SOUTH)
         {
             southPoint = data[cPoint].toDouble();
         }
         else if (cPoint == CARDINAL_WEST)
         {
             westPoint =  data[cPoint].toDouble();
         }
     }
     setNEPoint(LatLng(northPoint, eastPoint));
     setSEPoint(LatLng(southPoint, eastPoint));
     setNWPoint(LatLng(northPoint, westPoint));
     setSWPoint(LatLng(southPoint, westPoint));

}
