#include <exception>
using namespace std;
#include <QDebug>
#include "LatLng.h"

googleMaps::LatLng::LatLng(QObject *parent):m_lat(0), m_lng(0)
{
    setParent(parent);
}

googleMaps::LatLng::LatLng(const qreal lat, const qreal lng, QObject* parent):m_lat(lat), m_lng(lng)
{
    setParent(parent);
}

//copy constructor
googleMaps::LatLng::LatLng(const LatLng& rhs)
{
    m_lat = rhs.lat();
    m_lng = rhs.lng();
}

//assignment operator
googleMaps::LatLng& googleMaps::LatLng::operator=(const LatLng &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_lat = rhs.lat();
    m_lng = rhs.lng();
    return *this;
}

googleMaps::LatLng::~LatLng()
{
}

qreal googleMaps::LatLng::lat() const
{
    return m_lat;
}

qreal googleMaps::LatLng::lng() const
{
    return m_lng;
}

void googleMaps::LatLng::setLat(const qreal lat)
{
    m_lat = lat;
    emit lngChanged(lat);
}

void googleMaps::LatLng::setLng(const qreal lng)
{
    m_lng = lng;
    emit lngChanged(lng);
}

QString googleMaps::LatLng::toString() {
	throw "Not yet implemented";
}

void  googleMaps::LatLng::deserialize(const QVariantMap& data)
{
    qDebug() << "[LatLng] parse latLng result " << data << "\n";
     qDebug() << "[LatLng]  latLng keys " << data.keys() << "\n";
     for (auto locPoint : data.keys())
     {
         if (locPoint == GEO_LAT)
         {
             m_lat = data[locPoint].toDouble();
         }
         else if (locPoint == GEO_LNG)
         {
            m_lng = data[locPoint].toDouble();
         }
     }
     qDebug() << "[LatLng]  lat  " << m_lat << "   lng "<< m_lng << "\n";
}



