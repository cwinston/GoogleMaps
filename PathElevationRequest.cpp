#include <exception>
using namespace std;

#include "PathElevationRequest.h"
#include "LatLng.h"

googleMaps::PathElevationRequest::PathElevationRequest(QObject *parent)
{
    setParent(parent);
    m_samples = 0;
}

googleMaps::PathElevationRequest::~PathElevationRequest() {

}

googleMaps::PathElevationRequest::PathElevationRequest(const PathElevationRequest& rhs)
{
    m_path = rhs.getPath();
    m_samples = rhs.getSamples();
}

googleMaps::PathElevationRequest& googleMaps::PathElevationRequest::operator=(const googleMaps::PathElevationRequest rhs)
{
    return  *this;
}

void googleMaps::PathElevationRequest::importPath(const QList<googleMaps::LatLng> path)
{
    if (m_path.size() > 0)
    {
        m_path.clear();
    }
    for (auto location : path)
    {
        m_path.append(location.serialize());
    }
    emit pathChanged();
}

QVariantList googleMaps::PathElevationRequest::getPath() const
{
    return this->m_path;
}


void googleMaps::PathElevationRequest::setSamples(qreal samples)
{
    this->m_samples = samples;
    emit samplesChanged();
}

qreal googleMaps::PathElevationRequest::getSamples() const {
    return this->m_samples;
}

