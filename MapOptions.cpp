#include <exception>
using namespace std;

#include "MapOptions.h"
#include "LatLng.h"

googleMaps::MapOptions::MapOptions(QObject* parent)
{
    setParent(parent);
    m_disableDefaultUI = false;
    m_disableDoubleClickZoom = false;
    m_draggable = true;
    m_mapTypeControl = true;
    m_zoomControl = true;
}

//copy constructor
googleMaps::MapOptions::MapOptions(const MapOptions& rhs)
{
   m_backgroundColor = rhs.getBackgroundColor();
   m_center = rhs.getCenter();
   m_disableDefaultUI = rhs.isDisableDefaultUI();
   m_disableDoubleClickZoom = rhs.isDisableDoubleClickZoom();
   m_draggable = rhs.isDraggable();
   m_mapTypeControl = rhs.hasMapTypeControl();
   m_mapTypeId = rhs.getMapTypeId();
   m_maxZoom = rhs.getMaxZoom();
   m_minZoom = rhs.getMinZoom();
   m_zoom = rhs.getZoom();
   m_zoomControl = rhs.hasZoomControl();
   m_clickableIcons = rhs.hasClickableIcons();
   m_fullscreenControl = rhs.hasFullscreenControl();
   m_heading = rhs.getHeading();
   m_rotateControl = rhs.hasRotateControl();
   m_rotateControlPosition = rhs.getRotateControlPosition();
   m_fullscreenControlPosition = rhs.getFullscreenControlPosition();
   m_zoomControlPosition = rhs.getZoomControlPosition();
}

//assignment operator
googleMaps::MapOptions& googleMaps::MapOptions::operator=(const googleMaps::MapOptions &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_backgroundColor = rhs.getBackgroundColor();
    m_center = rhs.getCenter();
    m_disableDefaultUI = rhs.isDisableDefaultUI();
    m_disableDoubleClickZoom = rhs.isDisableDoubleClickZoom();
    m_draggable = rhs.isDraggable();
    m_mapTypeControl = rhs.hasMapTypeControl();
    m_mapTypeId = rhs.getMapTypeId();
    m_maxZoom = rhs.getMaxZoom();
    m_minZoom = rhs.getMinZoom();
    m_zoom = rhs.getZoom();
    m_zoomControl = rhs.hasZoomControl();
    m_clickableIcons = rhs.hasClickableIcons();
    m_fullscreenControl = rhs.hasFullscreenControl();
    m_heading = rhs.getHeading();
    m_rotateControl = rhs.hasRotateControl();
    m_rotateControlPosition = rhs.getRotateControlPosition();
    m_fullscreenControlPosition = rhs.getFullscreenControlPosition();
    m_zoomControlPosition = rhs.getZoomControlPosition();
    return *this;
}

void googleMaps::MapOptions::updateBackgroundColor(const QString backgroundColor)
{
    this->m_backgroundColor = backgroundColor;
}

QString googleMaps::MapOptions::getBackgroundColor() const
{
    return this->m_backgroundColor;
}

void googleMaps::MapOptions::updateCenter(const LatLng center)
{
    this->m_center = center;
}

googleMaps::LatLng googleMaps::MapOptions::getCenter() const
{
    return this->m_center;
}

void googleMaps::MapOptions::updateDisableDefaultUI(bool disableDefaultUI)
{
    this->m_disableDefaultUI = disableDefaultUI;
}

bool googleMaps::MapOptions::isDisableDefaultUI() const
{
    return this->m_disableDefaultUI;
}

void googleMaps::MapOptions::updateDisableDoubleClickZoom(const bool disableDoubleClickZoom)
{
    this->m_disableDoubleClickZoom = disableDoubleClickZoom;
}

bool googleMaps::MapOptions::isDisableDoubleClickZoom() const{
    return this->m_disableDoubleClickZoom;
}

void googleMaps::MapOptions::updateDraggable(const bool draggable)
{
    this->m_draggable = draggable;
}

bool googleMaps::MapOptions::isDraggable() const
{
    return this->m_draggable;
}

void googleMaps::MapOptions::updateMapTypeControl(const bool mapTypeControl)
{
    this->m_mapTypeControl = mapTypeControl;
}

bool googleMaps::MapOptions::hasMapTypeControl() const
{
    return this->m_mapTypeControl;
}

void googleMaps::MapOptions::updateMapTypeId(const EMapTypeID mapTypeId)
{
    this->m_mapTypeId = mapTypeId;
}

googleMaps::EMapTypeID googleMaps::MapOptions::getMapTypeId() const
{
    return this->m_mapTypeId;
}

void googleMaps::MapOptions::updateMaxZoom(const int maxZoom)
{
    this->m_maxZoom = maxZoom;
}

int googleMaps::MapOptions::getMaxZoom() const {
    return this->m_maxZoom;
}

void googleMaps::MapOptions::updateMinZoom(const int minZoom)
{
    this->m_minZoom = minZoom;
}

int googleMaps::MapOptions::getMinZoom() const
{
    return this->m_minZoom;
}

void googleMaps::MapOptions::updateZoom(const int zoom)
{
    this->m_zoom = zoom;
}

int googleMaps::MapOptions::getZoom() const
{
    return this->m_zoom;
}

void googleMaps::MapOptions::updateZoomControl(const bool zoomControl)
{
    this->m_zoomControl = zoomControl;
}

bool googleMaps::MapOptions::hasZoomControl() const
{
    return this->m_zoomControl;
}

void googleMaps::MapOptions::updateClickableIcons(const bool clickableIcons)
{
    this->m_clickableIcons = clickableIcons;
}

bool googleMaps::MapOptions::hasClickableIcons() const
{
    return this->m_clickableIcons;
}

void googleMaps::MapOptions::updateFullscreenControl(const bool fullscreenControl)
{
    this->m_fullscreenControl = fullscreenControl;
}

bool googleMaps::MapOptions::hasFullscreenControl() const
{
    return this->m_fullscreenControl;
}

void googleMaps::MapOptions::updateHeading(const qreal heading)
{
    this->m_heading = heading;
}

qreal googleMaps::MapOptions::getHeading() const
{
    return this->m_heading;
}

void googleMaps::MapOptions::updateRotateControl(bool rotateControl)
{
    this->m_rotateControl = rotateControl;
}

bool googleMaps::MapOptions::hasRotateControl() const
{
    return this->m_rotateControl;
}

void googleMaps::MapOptions::updateRotateControlPosition(const int rotateControlPosition)
{
    this->m_rotateControlPosition = rotateControlPosition;
}

int googleMaps::MapOptions::getRotateControlPosition() const
{
    return this->m_rotateControlPosition;
}

void googleMaps::MapOptions::updateFullscreenControlPosition(const int fullscreenControlPosition)
{
    this->m_fullscreenControlPosition = fullscreenControlPosition;
}

int googleMaps::MapOptions::getFullscreenControlPosition() const
{
    return this->m_fullscreenControlPosition;
}

void googleMaps::MapOptions::updateZoomControlPosition(const int zoomControlPosition)
{
    this->m_zoomControlPosition = zoomControlPosition;
}

int googleMaps::MapOptions::getZoomControlPosition() const
{
    return this->m_zoomControlPosition;
}

QVariantMap googleMaps::MapOptions::serialize() const
{
    QVariantMap options;
    options.insert(MAP_BACKGROUND_COLOR, m_backgroundColor);
    options.insert(MAP_CENTER, m_center.serialize());
    options.insert(MAP_DISABLED_DEFAULT_UI, m_disableDefaultUI);
    options.insert(MAP_DISABLED_DOUBLECLICK, m_disableDoubleClickZoom);
    options.insert(MAP_DRAGGABLE, m_draggable);
    options.insert(MAP_MAPTYPECONTROL, m_mapTypeControl);
    options.insert(MAP_MAPTYPEID, m_mapTypeId);
    options.insert(MAP_MAXZOOM, m_maxZoom);
    options.insert(MAP_MINZOOM, m_minZoom);
    options.insert(MAP_ZOOM, m_zoom);
    options.insert(MAP_ZOOMCONTROL, m_zoomControl);
    options.insert(MAP_CLICKABLE_ICONS, m_clickableIcons);
    options.insert(MAP_FULLSCREEN_CONTROL, m_fullscreenControl);
    options.insert(MAP_HEADING, m_heading);
    options.insert(MAP_ROTATE_CONTROL, m_rotateControl);
    options.insert(MAP_ROTATE_CONTROL_POSITION, m_rotateControlPosition);
    options.insert(MAP_FULLSCREEN_CONTROL_POSITION, m_fullscreenControlPosition);
    options.insert(MAP_ZOOMCONTROL_POSITION, m_zoomControlPosition);
    return options;
}
