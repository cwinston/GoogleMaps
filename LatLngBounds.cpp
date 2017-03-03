#include <exception>
using namespace std;

#include <QDebug>
#include <QtMath>
#include "LatLngBounds.h"
#include "LatLng.h"

googleMaps::LatLngBounds::LatLngBounds(googleMaps::LatLng se, googleMaps::LatLng nw, QObject* parent):m_nwPoint(nw), m_sePoint(se)
{
    setParent(parent);
    m_validator = QBitArray(9);
}

googleMaps::LatLngBounds::LatLngBounds(QObject* parent)
{
    setParent(parent);
    m_validator = QBitArray(9);
}

//copy constructor
googleMaps::LatLngBounds::LatLngBounds(const LatLngBounds& rhs)
{
    m_sePoint = rhs.getSouthEast();
    m_nwPoint = rhs.getNorthWest();
    m_swPoint = rhs.getSouthWest();
    m_nePoint = rhs.getNorthEast();
    m_centerPoint = rhs.getCenter();
    m_east = rhs.getEast();
    m_west = rhs.getWest();
    m_north = rhs.getNorth();
    m_south = rhs.getSouth();
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
    m_east = rhs.getEast();
    m_west = rhs.getWest();
    m_north = rhs.getNorth();
    m_south = rhs.getSouth();
    return *this;
}

bool googleMaps::LatLngBounds::setNWPoint(const googleMaps::LatLng nwPoint)
{
    //qreal bit2Set = qPow(2, ECardinalPositions::POS_NORTH_WEST);
   // qDebug() << "[LatLngBounds] set position " << cardinalToText(POS_NORTH_WEST) <<   "    val " << POS_NORTH_WEST << "    - " << bit2Set;
    if (nwPoint.isValidLatLng(nwPoint))
    {
       m_nwPoint = nwPoint;
       m_validator.setBit(POS_NORTH_WEST, true);
       emit boundsChanged(ECardinalPositions::POS_NORTH_WEST);
       if (isValid())
       {
           emit boundsValidityChanged(true);
       }
       return true;
    }
    else
    {
         m_validator.setBit(POS_NORTH_WEST, false);
         return false;
    }
}

bool googleMaps::LatLngBounds::setSEPoint(const googleMaps::LatLng sePoint)
{
  //  qreal bit2Set = qPow(2, ECardinalPositions::POS_SOUTH_EAST);
   // qDebug() << "[LatLngBounds] set position " << cardinalToText(POS_SOUTH_EAST) <<   "    val " << POS_SOUTH_EAST << "    - " << bit2Set;
    if (LatLng::isValidLatLng(sePoint))
    {
        m_sePoint = sePoint;
        m_validator.setBit(POS_SOUTH_EAST, true);
        emit boundsChanged(ECardinalPositions::POS_SOUTH_EAST);
        if (isValid())
        {
            emit boundsValidityChanged(true);
        }
        return true;
    }
    else
    {
        m_validator.setBit(POS_SOUTH_EAST, true);
        return false;
    }
}

bool googleMaps::LatLngBounds::setNEPoint(const googleMaps::LatLng nePoint)
{
   // qreal bit2Set = qPow(2, ECardinalPositions::POS_NORTH_EAST);
    //qDebug() << "[LatLngBounds] set position " << cardinalToText(POS_NORTH_EAST) <<  "    val " << POS_NORTH_EAST <<  "    - " << bit2Set;
    if (LatLng::isValidLatLng(nePoint))
    {
        m_nePoint = nePoint;
        m_validator.setBit(POS_NORTH_EAST, true);
        emit boundsChanged(ECardinalPositions::POS_NORTH_EAST);
        if (isValid())
        {
            emit boundsValidityChanged(true);
        }
        return true;
    }
    else
    {
        m_validator.setBit(POS_NORTH_EAST, false);
        return false;
    }
}

bool googleMaps::LatLngBounds::setSWPoint(const googleMaps::LatLng swPoint)
{
   // qreal bit2Set = qPow(2, ECardinalPositions::POS_SOUTH_WEST);
    //qDebug() << "[LatLngBounds] set position " << cardinalToText(POS_SOUTH_WEST) <<  "    val " << POS_SOUTH_WEST <<  "    - " << bit2Set;
    if (LatLng::isValidLatLng(swPoint))
    {
        m_swPoint = swPoint;
        m_validator.setBit(POS_SOUTH_WEST, true);
        emit boundsChanged(ECardinalPositions::POS_SOUTH_WEST);
        if (isValid())
        {
            emit boundsValidityChanged(true);
        }
        return true;
    }
    else
    {
        m_validator.setBit(POS_SOUTH_WEST, false);
        return false;
    }
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

bool googleMaps::LatLngBounds::setCenter(const googleMaps::LatLng center)
{
    //qreal bit2Set = qPow(2, ECardinalPositions::POS_CENTER);
    //qDebug() << "[LatLngBounds] set position " << cardinalToText(POS_CENTER) <<  "    val " << POS_CENTER <<  "    - " << bit2Set;
    if (LatLng::isValidLatLng(center))
    {
        m_centerPoint = center;
        m_validator.setBit(POS_CENTER, true);
        emit boundsChanged(ECardinalPositions::POS_CENTER);
        if (isValid())
        {
            emit boundsValidityChanged(true);
        }
        return true;
    }
    else
    {
        m_validator.setBit(POS_CENTER, false);
        return false;
    }
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

bool googleMaps::LatLngBounds::setEast(const LatLng east)
{
   // qreal bit2Set = qPow(2, ECardinalPositions::POS_EAST);
   // qDebug() << "[LatLngBounds] set position " << cardinalToText(POS_EAST) << "    val " << POS_EAST << "    - " << bit2Set;
    if (LatLng::isValidLatLng(east))
    {
        m_east = east;
        m_validator.setBit(POS_EAST, true);
        emit boundsChanged(ECardinalPositions::POS_EAST);
        if (isValid())
        {
            emit boundsValidityChanged(true);
        }
        return true;
    }
    else
    {
        m_validator.setBit(POS_EAST, false);
        return false;
    }
}

bool googleMaps::LatLngBounds::setNorth(const LatLng north)
{
   // qreal bit2Set = qPow(2, ECardinalPositions::POS_NORTH);
   // qDebug() << "[LatLngBounds] set position " << cardinalToText(POS_NORTH) <<  "    val " << POS_NORTH <<  "    - " << bit2Set;
    if (LatLng::isValidLatLng(north))
    {
        m_north = north;
        m_validator.setBit(POS_NORTH, true);
        emit boundsChanged(ECardinalPositions::POS_NORTH);
        if (isValid())
        {
            emit boundsValidityChanged(true);
        }
        return true;
    }
    else
    {
        m_validator.setBit(POS_NORTH, false);
        return false;
    }
}

bool googleMaps::LatLngBounds::setSouth(const LatLng south)
{
   // qreal bit2Set = qPow(2, ECardinalPositions::POS_SOUTH);
    //qDebug() << "[LatLngBounds] set position " << cardinalToText(POS_SOUTH) <<  "    val " << POS_SOUTH <<  "    - " << bit2Set;
    if (LatLng::isValidLatLng(south))
    {
        m_south = south;
        m_validator.setBit(POS_SOUTH, true);
        emit boundsChanged(ECardinalPositions::POS_SOUTH);
        if (isValid())
        {
            emit boundsValidityChanged(true);
        }
        return true;
    }
    else
    {
        m_validator.setBit(POS_SOUTH, false);
        return false;
    }

}

bool googleMaps::LatLngBounds::setWest(const LatLng west)
{
   // qreal bit2Set = qPow(2, ECardinalPositions::POS_WEST);
    //qDebug() << "[LatLngBounds] set position " << cardinalToText(POS_WEST) <<  "    val " << POS_WEST <<  "    - " << bit2Set;
    if (LatLng::isValidLatLng(west))
    {
        m_west = west;
        m_validator.setBit(POS_WEST, true);
        emit boundsChanged(ECardinalPositions::POS_WEST);
        if (isValid())
        {
            emit boundsValidityChanged(true);
        }
        return true;
    }
    else
    {
        m_validator.setBit(POS_WEST, false);
        return false;
    }
}

googleMaps::LatLng googleMaps::LatLngBounds::getWest() const
{
    return m_west;
}

void googleMaps::LatLngBounds::deserialize(const QVariantMap& data)
{
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
     if (isValid())
     {
         emit boundsValidityChanged(true);
     }
}

void googleMaps::LatLngBounds::invalidate()
{
    m_north.reset();
     m_validator.setBit(POS_NORTH, false);
    m_nePoint.reset();
     m_validator.setBit(POS_NORTH_EAST, false);
    m_nwPoint.reset();
     m_validator.setBit(POS_NORTH_WEST, false);
    m_sePoint.reset();
     m_validator.setBit(POS_SOUTH_EAST, false);
    m_swPoint.reset();
     m_validator.setBit(POS_SOUTH_WEST, false);
    m_east.reset();
     m_validator.setBit(POS_EAST, false);
    m_west.reset();
     m_validator.setBit(POS_WEST, false);
    m_south.reset();
     m_validator.setBit(POS_SOUTH, false);
    emit boundsValidityChanged(false);
}

QString googleMaps::LatLngBounds::cardinalToText(const googleMaps::ECardinalPositions pos)
{
    QString cardPos;
    switch(pos)
    {
        case googleMaps::ECardinalPositions::POS_CENTER:
            cardPos = CARDINAL_CENTER;
        break;
        case POS_EAST:
            cardPos = CARDINAL_EAST;
        break;
        case POS_NORTH:
            cardPos = CARDINAL_NORTH;
            break;
        case POS_NORTH_EAST:
            cardPos = CARDINAL_NE;
            break;
        case POS_NORTH_WEST:
            cardPos = CARDINAL_NW;
            break;
        case POS_SOUTH:
            cardPos = CARDINAL_SOUTH;
            break;
        case POS_SOUTH_EAST:
            cardPos = CARDINAL_SE;
            break;
        case POS_SOUTH_WEST:
            cardPos = CARDINAL_SW;
            break;
          case POS_WEST:
            cardPos = CARDINAL_WEST;
            break;
    }
    return cardPos;
}

QString googleMaps::LatLngBounds::cardinalToText(const int pos)
{
    QString cardPos;
    switch(pos)
    {
        case googleMaps::ECardinalPositions::POS_CENTER:
            cardPos = CARDINAL_CENTER;
        break;
        case POS_EAST:
            cardPos = CARDINAL_EAST;
        break;
        case POS_NORTH:
            cardPos = CARDINAL_NORTH;
            break;
        case POS_NORTH_EAST:
            cardPos = CARDINAL_NE;
            break;
        case POS_NORTH_WEST:
            cardPos = CARDINAL_NW;
            break;
        case POS_SOUTH:
            cardPos = CARDINAL_SOUTH;
            break;
        case POS_SOUTH_EAST:
            cardPos = CARDINAL_SE;
            break;
        case POS_SOUTH_WEST:
            cardPos = CARDINAL_SW;
            break;
          case POS_WEST:
            cardPos = CARDINAL_WEST;
            break;
    }
    return cardPos;
}


bool googleMaps::LatLngBounds::isValid() const
{
    bool flag;
    QBitArray comparitor(9);
    comparitor.fill(true);
    flag = (m_validator == comparitor)? true : false;
    qDebug() << "[LatLngBounds] isValid " << flag;
    return flag;
}

googleMaps::LatLng googleMaps::LatLngBounds::getPoint(const int pos)
{
    googleMaps::LatLng locPoint;
    switch(pos)
    {
        case googleMaps::ECardinalPositions::POS_CENTER:
            locPoint = m_centerPoint;
        break;
        case POS_EAST:
            locPoint = m_east;
        break;
        case POS_NORTH:
            locPoint = m_north;
            break;
        case POS_NORTH_EAST:
            locPoint = m_nePoint;
            break;
        case POS_NORTH_WEST:
            locPoint = m_nwPoint;
            break;
        case POS_SOUTH:
            locPoint = m_south;
            break;
        case POS_SOUTH_EAST:
            locPoint = m_sePoint;
            break;
        case POS_SOUTH_WEST:
            locPoint = m_swPoint;
            break;
          case POS_WEST:
            locPoint = m_west;
            break;
    }
    return locPoint;
}

QList<googleMaps::LatLng> googleMaps::LatLngBounds::exportPath()
{
    QList<googleMaps::LatLng> path;
    for ( int posIdx = POS_NORTH; posIdx != POS_CENTER; ++posIdx )
    {
        LatLng pos = getPoint(posIdx);
        path.push_back(pos);
    }
    return path;
}
