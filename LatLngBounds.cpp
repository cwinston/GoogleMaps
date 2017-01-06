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
}

void googleMaps::LatLngBounds::setSEPoint(const googleMaps::LatLng sePoint)
{
    m_sePoint = sePoint;
}

void googleMaps::LatLngBounds::setNEPoint(const googleMaps::LatLng nePoint)
{
    m_nePoint = nePoint;
}

void googleMaps::LatLngBounds::setSWPoint(const googleMaps::LatLng swPoint)
{
    m_swPoint = swPoint;
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

qreal& googleMaps::LatLngBounds::getEast()  {
    return m_east;
}

qreal& googleMaps::LatLngBounds::getNorth()  {
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

qreal& googleMaps::LatLngBounds::getSouth()
{
    return m_south;
}

googleMaps::LatLng googleMaps::LatLngBounds::getSouthEast() const
{
    return LatLng(m_south,m_east);
}

googleMaps::LatLng googleMaps::LatLngBounds::getSouthWest() const
{
    return LatLng(m_south,m_west);
}

qreal& googleMaps::LatLngBounds::getWest() const
{
	throw "Not yet implemented";
}

bool googleMaps::LatLngBounds::intersects(googleMaps::LatLngBounds aParam0)
{
	throw "Not yet implemented";
}

bool googleMaps::LatLngBounds::isEmpty()
{
	throw "Not yet implemented";
}

bool googleMaps::LatLngBounds::isLargerThan(googleMaps::LatLngBounds aParam0)
{
	throw "Not yet implemented";
}

QString googleMaps::LatLngBounds::toString()
{
	throw "Not yet implemented";
}

void googleMaps::LatLngBounds::setEast(qreal east)
{
    m_east = east;
}

void googleMaps::LatLngBounds::setNorth(qreal north)
{
    m_north = north;
}

void googleMaps::LatLngBounds::setSouth(qreal south)
{
    m_south = south;
}

void googleMaps::LatLngBounds::setWest(qreal west)
{
    m_west = west;
}

void googleMaps::LatLngBounds::deserialize(const QVariantMap& data)
{
    qDebug() << "[LatLngBounds] parse bounds result " << data << "\n";
     qDebug() << "[LatLngBounds]  bounds keys " << data.keys() << "\n";
     for (auto cPoint : data.keys())
     {
         if (cPoint == CARDINAL_EAST)
         {
             m_east = data[cPoint].toDouble();
         }
         else if (cPoint == CARDINAL_NORTH)
         {
             m_north = data[cPoint].toDouble();
         }
         else if (cPoint == CARDINAL_SOUTH)
         {
             m_south = data[cPoint].toDouble();
         }
         else if (cPoint == CARDINAL_WEST)
         {
             m_west =  data[cPoint].toDouble();
         }
     }
     setNEPoint(LatLng(m_north, m_east));
     setSEPoint(LatLng(m_south, m_east));
     setNWPoint(LatLng(m_north, m_west));
     setSWPoint(LatLng(m_south, m_west));

}
