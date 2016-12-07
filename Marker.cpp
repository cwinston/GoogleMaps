#include <exception>
#include <string>
using namespace std;

#include "Marker.h"
#include "MarkerOptions.h"
#include "LatLng.h"

googleMaps::Marker::Marker(QObject *parent)
{
    setParent(parent);
}

googleMaps::Marker::Marker(MarkerOptions opts)
{
    setOptions(opts);
}

//copy constructor
googleMaps::Marker::Marker(const Marker& rhs)
{
    m_options = rhs.getOptions();
}

//assignment operator
googleMaps::Marker& googleMaps::Marker::operator=(const Marker &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_options = rhs.getOptions();
    return *this;
}


void googleMaps::Marker::setOptions(googleMaps::MarkerOptions opts)
{
    m_options = opts;
}

googleMaps::MarkerOptions googleMaps::Marker::getOptions() const
{
    return m_options;
}

bool googleMaps::Marker::getDraggable()
{
    return m_options.isDraggable();
}

bool googleMaps::Marker::getClickable()
{
    return m_options.isClickable();
}

googleMaps::LatLng googleMaps::Marker::getPosition()
{
    return m_options.getPosition();
}

void googleMaps::Marker::setClickable(bool clickable)
{
    m_options.setClickable(clickable);
}

void googleMaps::Marker::setDraggable(bool draggable)
{
    m_options.setDraggable( draggable);
}

void googleMaps::Marker::setLabel(QString label)
{
    m_options.setLabel(label);
}

QString googleMaps::Marker::getLabel()
{
    return m_options.getLabel();
}

void googleMaps::Marker::setPosition(googleMaps::LatLng position)
{
    m_options.setPosition( position);
}

void googleMaps::Marker::setTitle(QString title)
{
    m_options.setTitle( title);
}

QString googleMaps::Marker::getTitle()
{
    return m_options.getTitle();
}

void googleMaps::Marker::setVisible(bool visible)
{
    m_options.setVisible( visible);
}

bool googleMaps::Marker::isVisible()
{
    return m_options.isVisible();
}

void googleMaps::Marker::setZIndex(int zIndex)
{
    m_options.setZIndex( zIndex);
}

int googleMaps::Marker::getZIndex()
{
    return m_options.getZIndex();
}

