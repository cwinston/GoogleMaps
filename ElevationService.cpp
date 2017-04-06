#include <exception>
using namespace std;

#include "ElevationService.h"
#include "PathElevationRequest.h"
#include "LocationElevationRequest.h"
#include "ElevationResult.h"
#include "LatLng.h"


googleMaps::ElevationService::ElevationService(QObject *parent)
{
    setParent(parent);
    m_requestType = "";
}

googleMaps::ElevationService::ElevationService(const googleMaps::ElevationService& rhs)
{
    m_pathRequest = rhs.getLastPathElevationRequest();
    m_locationRequest = rhs.getLastLocationElevationRequest();
}

void googleMaps::ElevationService::getElevationAlongPath(const PathElevationRequest request)
{
    m_pathRequest = request;
    m_requestType = PATH_REQUEST;
    emit requestElevationPath(request);
}

void googleMaps::ElevationService::getElevationForLocations(const googleMaps::LocationElevationRequest request)
{
    m_locationRequest = request;
    m_requestType = LOCATION_REQUEST;
    emit requestElevation4Location(request);
}

void googleMaps::ElevationService::updateElevationResults(QVariantList results, QString status)
{
    // first need to determine the number of results.
    m_results = results;
    emit elevationResultsReceived(results, status);
}

googleMaps::PathElevationRequest googleMaps::ElevationService::createPathElevationRequest(QList<googleMaps::LatLng> paths, qreal samples)
{
    googleMaps::PathElevationRequest request = googleMaps::PathElevationRequest();
    request.importPath(paths);
    request.setSamples(samples);
    return request;
}

googleMaps::LocationElevationRequest googleMaps::ElevationService::createLocationElevationRequest(QList<googleMaps::LatLng> locations)
{
    googleMaps::LocationElevationRequest request = googleMaps::LocationElevationRequest();
    for (auto location : locations)
    {
        request.addLocation(location);
    }
    return request;
}

googleMaps::PathElevationRequest googleMaps::ElevationService::getLastPathElevationRequest() const
{
    return m_pathRequest;
}

googleMaps::LocationElevationRequest googleMaps::ElevationService::getLastLocationElevationRequest() const
{
    return m_locationRequest;
}

QVariantList& googleMaps::ElevationService::getElevationResults()
{
    return m_results;
}
