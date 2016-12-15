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

void googleMaps::MapOptions::updateBackgroundColor(QString backgroundColor) {
    this->m_backgroundColor = backgroundColor;
}

QString googleMaps::MapOptions::getBackgroundColor() const
{
    return this->m_backgroundColor;
}

void googleMaps::MapOptions::updateCenter(googleMaps::LatLng center) {
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

void googleMaps::MapOptions::updateDisableDoubleClickZoom(bool disableDoubleClickZoom)
{
    this->m_disableDoubleClickZoom = disableDoubleClickZoom;
}

bool googleMaps::MapOptions::isDisableDoubleClickZoom() const{
    return this->m_disableDoubleClickZoom;
}

void googleMaps::MapOptions::updateDraggable(bool draggable)
{
    this->m_draggable = draggable;
}

bool googleMaps::MapOptions::isDraggable() const
{
    return this->m_draggable;
}

void googleMaps::MapOptions::updateMapTypeControl(bool mapTypeControl)
{
    this->m_mapTypeControl = mapTypeControl;
}

bool googleMaps::MapOptions::hasMapTypeControl() const
{
    return this->m_mapTypeControl;
}

void googleMaps::MapOptions::updateMapTypeId(googleMaps::EMapTypeID mapTypeId)
{
    this->m_mapTypeId = mapTypeId;
}

googleMaps::EMapTypeID googleMaps::MapOptions::getMapTypeId() const
{
    return this->m_mapTypeId;
}

void googleMaps::MapOptions::updateMaxZoom(int maxZoom) {
    this->m_maxZoom = maxZoom;
}

int googleMaps::MapOptions::getMaxZoom() const {
    return this->m_maxZoom;
}

void googleMaps::MapOptions::updateMinZoom(int minZoom) {
    this->m_minZoom = minZoom;
}

int googleMaps::MapOptions::getMinZoom() const
{
    return this->m_minZoom;
}

void googleMaps::MapOptions::updateZoom(int zoom)
{
    this->m_zoom = zoom;
}

int googleMaps::MapOptions::getZoom() const
{
    return this->m_zoom;
}

void googleMaps::MapOptions::updateZoomControl(bool zoomControl)
{
    this->m_zoomControl = zoomControl;
}

bool googleMaps::MapOptions::hasZoomControl() const
{
    return this->m_zoomControl;
}

void googleMaps::MapOptions::updateClickableIcons(bool clickableIcons)
{
    this->m_clickableIcons = clickableIcons;
}

bool googleMaps::MapOptions::hasClickableIcons() const
{
    return this->m_clickableIcons;
}

void googleMaps::MapOptions::updateFullscreenControl(bool fullscreenControl)
{
    this->m_fullscreenControl = fullscreenControl;
}

bool googleMaps::MapOptions::hasFullscreenControl() const
{
    return this->m_fullscreenControl;
}

void googleMaps::MapOptions::updateHeading(qreal heading)
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

void googleMaps::MapOptions::updateRotateControlPosition(int rotateControlPosition)
{
    this->m_rotateControlPosition = rotateControlPosition;
}

int googleMaps::MapOptions::getRotateControlPosition() const
{
    return this->m_rotateControlPosition;
}

void googleMaps::MapOptions::updateFullscreenControlPosition(int fullscreenControlPosition)
{
    this->m_fullscreenControlPosition = fullscreenControlPosition;
}

int googleMaps::MapOptions::getFullscreenControlPosition() const
{
    return this->m_fullscreenControlPosition;
}

void googleMaps::MapOptions::updateZoomControlPosition(int zoomControlPosition) {
    this->m_zoomControlPosition = zoomControlPosition;
}

int googleMaps::MapOptions::getZoomControlPosition() const {
    return this->m_zoomControlPosition;
}
