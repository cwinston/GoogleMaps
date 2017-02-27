#include <exception>
using namespace std;

#include "Polygon.h"
#include "PolygonOptions.h"

googleMaps::Polygon::Polygon(QObject* parent)
{
    setParent(parent);
    m_options = PolygonOptions();
}

googleMaps::Polygon::Polygon(googleMaps::PolygonOptions opt)
{
    m_options = opt;
}

void googleMaps::Polygon::updateOptions(googleMaps::PolygonOptions options)
{
    this->m_options = options;
    emit optionsChanged();
}

googleMaps::Polygon::Polygon(const Polygon& rhs)
{
    m_options = rhs.getOptions();
}

//assignment operator
googleMaps::Polygon& googleMaps::Polygon::operator=(const Polygon &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_options = rhs.getOptions();
    return *this;
}

googleMaps::PolygonOptions googleMaps::Polygon::getOptions() const
{
    return this->m_options;
}


void googleMaps::Polygon::updateClickable(const bool clickable)
{
    m_options.setClickable(clickable);
    emit clickableChanged();
}

void googleMaps::Polygon::updateDraggable(const bool draggable)
{
    m_options.setDraggable(draggable);
    emit draggableChanged();
}

void googleMaps::Polygon::updateEditable(const bool editable)
{
    m_options.setEditable(editable);
    emit editableChanged();
}

void googleMaps::Polygon::updateFillColor(const QString fillColor)
{
    m_options.setFillColor(fillColor);
    emit fillColorChanged();
}

void googleMaps::Polygon::updateFillOpacity(const qreal fillOpacity)
{
    m_options.setFillOpacity(fillOpacity);
    emit fillOpacityChanged();
}

void googleMaps::Polygon::updateStrokeColor(const QString strokeColor)
{
    m_options.setStrokeColor(strokeColor);
    emit strokeColorChanged();
}

void googleMaps::Polygon::updateStrokeOpacity(const qreal strokeOpacity)
{
    m_options.setStrokeOpacity(strokeOpacity);
    emit strokeOpacityChanged();
}

void googleMaps::Polygon::updateStrokeWeight(const qreal strokeWeight)
{
   m_options.setStrokeWeight(strokeWeight);
   emit strokeWeightChanged();
}

void googleMaps::Polygon::updateVisible(const bool visible)
{
    m_options.setVisible(visible);
    emit visibleChanged();
}

void googleMaps::Polygon::updateZIndex(const qreal zIndex)
{
    m_options.setZIndex(zIndex);
    emit zIndexChanged();
}

void googleMaps::Polygon::updatePath(const QList<googleMaps::LatLng> path)
{
    m_options.setPath(path);
}

bool googleMaps::Polygon::isClickable() const
{
    return m_options.isClickable();
}

bool googleMaps::Polygon::isDraggable() const
{
    return m_options.isDraggable();
}

bool googleMaps::Polygon::isEditable() const
{
    return m_options.isEditable();
}

QString googleMaps::Polygon::getFillColor() const
{
    return m_options.getFillColor();
}

qreal googleMaps::Polygon::getFillOpacity() const
{
    return m_options.getFillOpacity();
}

QString googleMaps::Polygon::getStrokeColor() const
{
    return m_options.getStrokeColor();
}

qreal googleMaps::Polygon::getStrokeOpacity() const
{
    return m_options.getStrokeOpacity();
}

qreal googleMaps::Polygon::getStrokeWeight() const
{
    return m_options.getStrokeWeight();
}

bool googleMaps::Polygon::isVisible() const
{
    return m_options.isVisible();
}

qreal googleMaps::Polygon::getZIndex() const
{
    return m_options.getZIndex();
}

QList<googleMaps::LatLng> googleMaps::Polygon::getPath() const
{
    return m_options.getPath();
}
