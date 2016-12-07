#include <exception>
using namespace std;

#include "Size.h"

googleMaps::Size::Size(QObject* parent)
{
    setParent(parent);
}

googleMaps::Size::Size(const googleMaps::Size& rhs)
{
    m_height = rhs.getHeight();
    m_width = rhs.getWidth();
}

googleMaps::Size& googleMaps::Size::operator=(const Size &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_height = rhs.getHeight();
    m_width = rhs.getWidth();
    return *this;
}

googleMaps::Size::Size(qreal width, qreal height)
{
    m_width = width;
    m_height = height;
}

bool googleMaps::Size::equals(googleMaps::Size other) {
	throw "Not yet implemented";
}

QString googleMaps::Size::toString() {
	throw "Not yet implemented";
}

void googleMaps::Size::setHeight(qreal height) {
    this->m_height = height;
}

qreal googleMaps::Size::getHeight() const
{
    return m_height;
}

void googleMaps::Size::setWidth(qreal width)
{
    this->m_width = width;
}

qreal googleMaps::Size::getWidth() const
{
    return this->m_width;
}

