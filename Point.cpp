#include <exception>
using namespace std;

#include "Point.h"

googleMaps::Point::Point(QObject *parent)
{
    m_x = 0;
    m_y = 0;
    setParent(parent);
}

googleMaps::Point::Point(qreal xVal, qreal yVal)
{
    m_x = xVal;
    m_y = yVal;
}

googleMaps::Point::Point(const Point& rhs)
{
    m_x = rhs.getX();
    m_y = rhs.getY();
}

googleMaps::Point& googleMaps::Point::operator=(const Point &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_x = rhs.getX();
    m_y = rhs.getY();
    return *this;
}

bool googleMaps::Point::operator==(const Point &rhs)
{
    if ((rhs.getX() == m_x) && (rhs.getY() == m_y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool googleMaps::Point::equals(const Point other)
{
    if ((other.getX() == m_x) && (other.getY() == m_y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

QString googleMaps::Point::toString() {
	throw "Not yet implemented";
}

void googleMaps::Point::setX(const qreal x)
{
    this->m_x = x;
    emit pointChanged();
}

qreal googleMaps::Point::getX() const
{
    return this->m_x;
}

void googleMaps::Point::setY(const qreal y)
{
    this->m_y = y;
    emit pointChanged();
}

qreal googleMaps::Point::getY() const
{
    return this->m_y;
}

