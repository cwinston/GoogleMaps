#include <exception>
using namespace std;

#include "MarkerOptions.h"
#include "Point.h"
#include "LatLng.h"

googleMaps::MarkerOptions::MarkerOptions(QObject* parent)
{
    m_clickable = true;
    m_crossOnDrag = true;
    m_draggable = true;
    m_label = "center";
    m_opacity = 1;
    m_visible = true;
}

googleMaps::MarkerOptions::MarkerOptions(const MarkerOptions& rhs)
{
    m_anchorPoint = rhs.getAnchorPoint();
    m_clickable = rhs.isClickable();
    m_crossOnDrag = rhs.isCrossOnDrag();
    m_draggable = rhs.isDraggable();
    m_label = rhs.getLabel();
    m_icon = rhs.getIcon();
    m_opacity = rhs.getOpacity();
    m_position = rhs.getPosition();
    m_title = rhs.getTitle();
    m_visible = rhs.isVisible();
    m_zIndex = rhs.getZIndex();
}

//assignment operator
googleMaps::MarkerOptions& googleMaps::MarkerOptions::operator=(const MarkerOptions &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_anchorPoint = rhs.getAnchorPoint();
    m_clickable = rhs.isClickable();
    m_crossOnDrag = rhs.isCrossOnDrag();
    m_draggable = rhs.isDraggable();
    m_label = rhs.getLabel();
    m_icon = rhs.getIcon();
    m_opacity = rhs.getOpacity();
    m_position = rhs.getPosition();
    m_title = rhs.getTitle();
    m_visible = rhs.isVisible();
    m_zIndex = rhs.getZIndex();
    return *this;
}

void googleMaps::MarkerOptions::setAnchorPoint(googleMaps::Point anchorPoint)
{
    this->m_anchorPoint = anchorPoint;
}

googleMaps::Point googleMaps::MarkerOptions::getAnchorPoint() const
{
    return this->m_anchorPoint;
}

void googleMaps::MarkerOptions::setClickable(bool clickable)
{
    this->m_clickable = clickable;
}

bool googleMaps::MarkerOptions::isClickable() const
{
    return this->m_clickable;
}

void googleMaps::MarkerOptions::setCrossOnDrag(bool crossOnDrag)
{
    this->m_crossOnDrag = crossOnDrag;
}

bool googleMaps::MarkerOptions::isCrossOnDrag() const
{
    return this->m_crossOnDrag;
}

void googleMaps::MarkerOptions::setDraggable(bool draggable)
{
    this->m_draggable = draggable;
}

bool googleMaps::MarkerOptions::isDraggable() const
{
    return this->m_draggable;
}

void googleMaps::MarkerOptions::setLabel(QString label)
{
    this->m_label = label;
}

QString googleMaps::MarkerOptions::getLabel() const
{
    return this->m_label;
}

void googleMaps::MarkerOptions::setIcon(QString icon)
{
    this->m_icon = icon;
}

QString googleMaps::MarkerOptions::getIcon() const
{
    return this->m_icon;
}

void googleMaps::MarkerOptions::setOpacity(qreal opacity)
{
    this->m_opacity = opacity;
}

qreal googleMaps::MarkerOptions::getOpacity() const
{
    return this->m_opacity;
}

void googleMaps::MarkerOptions::setPosition(googleMaps::LatLng position)
{
    this->m_position = position;
}

googleMaps::LatLng googleMaps::MarkerOptions::getPosition() const
{
    return this->m_position;
}

void googleMaps::MarkerOptions::setTitle(QString title)
{
    this->m_title = title;
}

QString googleMaps::MarkerOptions::getTitle() const
{
    return this->m_title;
}

void googleMaps::MarkerOptions::setVisible(bool visible)
{
    this->m_visible = visible;
}

bool googleMaps::MarkerOptions::isVisible() const
{
    return this->m_visible;
}

void googleMaps::MarkerOptions::setZIndex(qreal zIndex)
{
    this->m_zIndex = zIndex;
}

qreal googleMaps::MarkerOptions::getZIndex() const
{
    return this->m_zIndex;
}

