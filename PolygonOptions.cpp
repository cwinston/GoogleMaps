#include <exception>
using namespace std;

#include "PolygonOptions.h"
#include "LatLng.h"

googleMaps::PolygonOptions::PolygonOptions(QObject* parent)
{
    setParent(parent);
    m_clickable = true;
    m_draggable = true;
    m_editable = false;
    m_fillColor = "#000000";
    m_fillOpacity = 1.0;
    m_strokeColor = "#000000";
    m_strokeOpacity = 1.0;
    m_strokeWeight = 2.0;
    m_visible = true;
}

googleMaps::PolygonOptions::PolygonOptions(const PolygonOptions& rhs)
{
    m_clickable = rhs.isClickable();
    m_draggable = rhs.isDraggable();
    m_editable = rhs.isEditable();
    m_fillColor = rhs.getFillColor();
    m_fillOpacity = rhs.getFillOpacity();
    m_strokeColor = rhs.getStrokeColor();
    m_strokeOpacity = rhs.getStrokeOpacity();
    m_strokeWeight = rhs.getStrokeWeight();
    m_visible = rhs.isVisible();
    m_zIndex = rhs.getZIndex();
    m_path = rhs.getPath();
}

//assignment operator
googleMaps::PolygonOptions& googleMaps::PolygonOptions::operator=(const PolygonOptions &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_clickable = rhs.isClickable();
    m_draggable = rhs.isDraggable();
    m_editable = rhs.isEditable();
    m_fillColor = rhs.getFillColor();
    m_fillOpacity = rhs.getFillOpacity();
    m_strokeColor = rhs.getStrokeColor();
    m_strokeOpacity = rhs.getStrokeOpacity();
    m_strokeWeight = rhs.getStrokeWeight();
    m_visible = rhs.isVisible();
    m_zIndex = rhs.getZIndex();
    m_path = rhs.getPath();
    return *this;
}

QVariantMap googleMaps::PolygonOptions::serialize() const
{
    QVariantMap options;
    options.insert(POLYGON_CLICKABLE, m_clickable);
    options.insert(POLYGON_DRAGGABLE, m_draggable);
    options.insert(POLYGON_EDITABLE, m_editable);
    options.insert(POLYGON_FILLCOLOR, m_fillColor);
    options.insert(POLYGON_FILLOPACITY, m_fillOpacity);
    options.insert(POLYGON_STROKECOLOR, m_strokeColor);
    options.insert(POLYGON_STROKEOPACITY, m_strokeOpacity);
    options.insert(POLYGON_VISIBLE, m_visible);
    options.insert(POLYGON_ZINDEX, m_zIndex);
    options.insert(POLYGON_STROKEWEIGHT, m_strokeWeight);
    options.insert(POLYGON_PATH, serializePath(m_path));
    return options;
}

QVariant googleMaps::PolygonOptions::serializePath( const QList<googleMaps::LatLng> &list )
{
    QVariantList newList;
    foreach( const googleMaps::LatLng &item, list )
    {
        newList << QVariant(item.serialize());
    }

    return QVariant(newList);
}

void googleMaps::PolygonOptions::setClickable(const bool clickable)
{
    this->m_clickable = clickable;
}

bool googleMaps::PolygonOptions::isClickable() const
{
    return this->m_clickable;
}

void googleMaps::PolygonOptions::setDraggable(const bool draggable)
{
    this->m_draggable = draggable;
}

bool googleMaps::PolygonOptions::isDraggable() const
{
    return this->m_draggable;
}

void googleMaps::PolygonOptions::setEditable(const bool editable)
{
    this->m_editable = editable;
}

bool googleMaps::PolygonOptions::isEditable() const
{
    return this->m_editable;
}

void googleMaps::PolygonOptions::setFillColor(const QString fillColor)
{
    this->m_fillColor = fillColor;
}

QString googleMaps::PolygonOptions::getFillColor() const
{
    return this->m_fillColor;
}

void googleMaps::PolygonOptions::setFillOpacity(const qreal fillOpacity)
{
    this->m_fillOpacity = fillOpacity;
}

qreal googleMaps::PolygonOptions::getFillOpacity() const
{
    return this->m_fillOpacity;
}

void googleMaps::PolygonOptions::setStrokeColor(const QString strokeColor)
{
    this->m_strokeColor = strokeColor;
}

QString googleMaps::PolygonOptions::getStrokeColor() const
{
    return this->m_strokeColor;
}

void googleMaps::PolygonOptions::setStrokeOpacity(const qreal strokeOpacity)
{
    this->m_strokeOpacity = strokeOpacity;
}

qreal googleMaps::PolygonOptions::getStrokeOpacity()  const
{
    return this->m_strokeOpacity;
}

void googleMaps::PolygonOptions::setStrokeWeight(const qreal strokeWeight)
{
    this->m_strokeWeight = strokeWeight;
}

qreal googleMaps::PolygonOptions::getStrokeWeight()  const
{
    return this->m_strokeWeight;
}

void googleMaps::PolygonOptions::setVisible(const bool visible)
{
    this->m_visible = visible;
}

bool googleMaps::PolygonOptions::isVisible()  const
{
    return this->m_visible;
}

void googleMaps::PolygonOptions::setZIndex(const qreal zIndex)
{
    this->m_zIndex = zIndex;
}

qreal googleMaps::PolygonOptions::getZIndex()  const
{
    return this->m_zIndex;
}

void googleMaps::PolygonOptions::setPath(const QList<googleMaps::LatLng> path)
{
    this->m_path = path;
}

QList<googleMaps::LatLng> googleMaps::PolygonOptions::getPath()  const
{
    return m_path;
}

