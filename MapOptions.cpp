#include <exception>
using namespace std;

#include "MapOptions.h"
#include "LatLng.h"

googleMaps::MapOptions::MapOptions(QObject* parent)
{
    setParent(parent);
}

void googleMaps::MapOptions::setBackgroundColor(QString backgroundColor) {
    this->m_backgroundColor = backgroundColor;
}

QString googleMaps::MapOptions::getBackgroundColor() {
    return this->m_backgroundColor;
}

void googleMaps::MapOptions::setCenter(googleMaps::LatLng center) {
    this->m_center = center;
}

googleMaps::LatLng googleMaps::MapOptions::getCenter() {
    return this->m_center;
}

void googleMaps::MapOptions::setDisableDefaultUI(bool disableDefaultUI) {
    this->m_disableDefaultUI = disableDefaultUI;
}

bool googleMaps::MapOptions::isDisableDefaultUI() {
    return this->m_disableDefaultUI;
}

void googleMaps::MapOptions::setDisableDoubleClickZoom(bool disableDoubleClickZoom) {
    this->m_disableDoubleClickZoom = disableDoubleClickZoom;
}

bool googleMaps::MapOptions::isDisableDoubleClickZoom() {
    return this->m_disableDoubleClickZoom;
}

void googleMaps::MapOptions::setDraggable(bool draggable) {
    this->m_draggable = draggable;
}

bool googleMaps::MapOptions::isDraggable() {
    return this->m_draggable;
}

void googleMaps::MapOptions::setMapTypeControl(bool mapTypeControl) {
    this->m_mapTypeControl = mapTypeControl;
}

bool googleMaps::MapOptions::isMapTypeControl() {
    return this->m_mapTypeControl;
}

void googleMaps::MapOptions::setMapTypeId(googleMaps::EMapTypeID mapTypeId) {
    this->m_mapTypeId = mapTypeId;
}

googleMaps::EMapTypeID googleMaps::MapOptions::getMapTypeId() {
    return this->m_mapTypeId;
}

void googleMaps::MapOptions::setMaxZoom(int maxZoom) {
    this->m_maxZoom = maxZoom;
}

int googleMaps::MapOptions::getMaxZoom() {
    return this->m_maxZoom;
}

void googleMaps::MapOptions::setMinZoom(int minZoom) {
    this->m_minZoom = minZoom;
}

int googleMaps::MapOptions::getMinZoom() {
    return this->m_minZoom;
}

void googleMaps::MapOptions::setZoom(int zoom) {
    this->m_zoom = zoom;
}

int googleMaps::MapOptions::getZoom() {
    return this->m_zoom;
}

void googleMaps::MapOptions::setZoomControl(bool zoomControl) {
    this->m_zoomControl = zoomControl;
}

bool googleMaps::MapOptions::isZoomControl() {
    return this->m_zoomControl;
}

void googleMaps::MapOptions::setClickableIcons(bool clickableIcons) {
    this->m_clickableIcons = clickableIcons;
}

bool googleMaps::MapOptions::isClickableIcons() {
    return this->m_clickableIcons;
}

void googleMaps::MapOptions::setFullscreenControl(bool fullscreenControl) {
    this->m_fullscreenControl = fullscreenControl;
}

bool googleMaps::MapOptions::isFullscreenControl() {
    return this->m_fullscreenControl;
}

void googleMaps::MapOptions::setHeading(qreal heading) {
    this->m_heading = heading;
}

qreal googleMaps::MapOptions::getHeading() {
    return this->m_heading;
}

void googleMaps::MapOptions::setRotateControl(bool rotateControl) {
    this->m_rotateControl = rotateControl;
}

bool googleMaps::MapOptions::isRotateControl() {
    return this->m_rotateControl;
}

void googleMaps::MapOptions::setRotateControlPosition(int rotateControlPosition) {
    this->m_rotateControlPosition = rotateControlPosition;
}

int googleMaps::MapOptions::getRotateControlPosition() {
    return this->m_rotateControlPosition;
}

void googleMaps::MapOptions::setFullscreenControlPosition(int fullscreenControlPosition) {
    this->m_fullscreenControlPosition = fullscreenControlPosition;
}

int googleMaps::MapOptions::getFullscreenControlPosition() {
    return this->m_fullscreenControlPosition;
}

void googleMaps::MapOptions::setZoomControlPosition(int zoomControlPosition) {
    this->m_zoomControlPosition = zoomControlPosition;
}

int googleMaps::MapOptions::getZoomControlPosition() {
    return this->m_zoomControlPosition;
}

googleMaps::MapOptions::MapOptions(const MapOptions &options) {
    m_disableDefaultUI = false;
    m_disableDoubleClickZoom = false;
    m_draggable = true;
    m_mapTypeControl = true;
    m_zoomControl = true;
}

