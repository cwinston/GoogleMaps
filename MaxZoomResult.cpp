#include <exception>
using namespace std;

#include "MaxZoomResult.h"


googleMaps::MaxZoomResult::MaxZoomResult(QObject *parent) : QObject(parent)
{
}

googleMaps::MaxZoomResult::MaxZoomResult(const MaxZoomResult& rhs)
{
    m_zoom = rhs.getZoom();
    m_status = rhs.getStatus();
}

googleMaps::MaxZoomResult& googleMaps::MaxZoomResult::operator=(const MaxZoomResult &rhs)
{
    if(this == &rhs) {
        return *this;
    }

    m_zoom = rhs.getZoom();
    m_status = rhs.getStatus();
    return *this;
}

void googleMaps::MaxZoomResult::setZoom(const qreal aZoom) {
    this->m_zoom = aZoom;
}

qreal googleMaps::MaxZoomResult::getZoom() const{
    return this->m_zoom;
}

void googleMaps::MaxZoomResult::setStatus(const googleMaps::MaxZoomStatus aStatus) {
    this->m_status = aStatus;
}

googleMaps::MaxZoomStatus googleMaps::MaxZoomResult::getStatus() const{
    return this->m_status;
}

