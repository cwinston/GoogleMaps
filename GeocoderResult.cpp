#include <exception>
using namespace std;
#include <QDebug>
#include "GeocoderResult.h"
#include "GeocoderAddressComponent.h"
#include "GeocoderGeometry.h"
#include "GeoAddressComponentsModel.h"

googleMaps::GeocoderResult::GeocoderResult(QObject *parent) {
}

googleMaps::GeocoderResult::~GeocoderResult() {

}

googleMaps::GeocoderResult::GeocoderResult(const GeocoderResult& rhs)
{
    m_addressComponents = rhs.getAddressComponents();
    m_formattedAddress = rhs.getFormattedAddress();
    m_geometry = rhs.getGeometry();
    m_partialMatch = rhs.isPartialMatch();
    m_placeID = rhs.getPlaceID();
    m_postcodeLocalities = rhs.getPostcodeLocalities();
    m_types = rhs.getTypes();
}

googleMaps::GeocoderResult& googleMaps::GeocoderResult::operator=(const googleMaps::GeocoderResult &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    m_addressComponents = rhs.getAddressComponents();
    m_formattedAddress = rhs.getFormattedAddress();
    m_geometry = rhs.getGeometry();
    m_partialMatch = rhs.isPartialMatch();
    m_placeID = rhs.getPlaceID();
   // auto localities = rhs.getPostcodeLocalities();
    m_postcodeLocalities = rhs.getPostcodeLocalities();
    m_types = rhs.getTypes();
    return *this;
}

void googleMaps::GeocoderResult::parseIncomingData(const QVariant& data)
{
    QVariantMap  propertyMap = data.toMap();
   // qDebug() << "[GeocoderResult] parse data result " << propertyMap;// << "  num results " << results.size();

    for (auto resProp : propertyMap.keys())
    {
        qDebug() << "\n\n [GeocoderResult] key " << resProp << "\n " << propertyMap[resProp];
        if (resProp == GEO_ADDRESS_COMPONENTS)
        {
           GeocoderAddressComponent addyComponent;
           QVariantList components = propertyMap[resProp].toList();
           qDebug() << "[GeocoderResult] parse datacomponents result " << components.size() << "\n";
           for (auto component : components)
           {
               QVariantMap addyPropMap = component.toMap();
                qDebug() << "[GeocoderResult] addy datacomponents result " << addyPropMap[GEO_ADDY_LONG_NAME].toString();
                addyComponent.setLongName(addyPropMap[GEO_ADDY_LONG_NAME].toString());
                addyComponent.setShortName(addyPropMap[GEO_ADDY_SHORT_NAME].toString());
                addyComponent.setTypes(addyPropMap[GEO_TYPES].toStringList());
                m_addressComponents.push_back(addyComponent);

           }
          // m_addre
        }
        else if (resProp == GEO_FORMATTED_ADDRESS)
        {
            qDebug() << "[GeocoderResult] parse formatted addy result " << propertyMap[resProp] << "\n";
            m_formattedAddress = propertyMap[resProp].toString();
        }
        else if (resProp == GEO_GEOMETRY)
        {
             qDebug() << "[GeocoderResult] parse geometry result " << propertyMap[resProp] << "\n";
             m_geometry.deserialize(propertyMap[resProp].toMap());
        }
        else if (resProp == GEO_PARTIAL_MATCH)
        {
            qDebug() << "[GeocoderResult] parse partial match " << propertyMap[resProp] << "\n";
            m_partialMatch = propertyMap[resProp].toBool();
        }
        else if (resProp == GEO_PLACE_ID)
        {
            qDebug() << "[GeocoderResult] parse place id " << propertyMap[resProp] << "\n";
            m_placeID = propertyMap[resProp].toString();
        }
        else if (resProp == GEO_TYPES)
        {
            qDebug() << "[GeocoderResult] parse geo types " << propertyMap[resProp] << "\n";
            m_types = propertyMap[resProp].toStringList();
        }
    }
}

QList<googleMaps::GeocoderAddressComponent> googleMaps::GeocoderResult::getAddressComponents() const
{
    return this->m_addressComponents;
}

void googleMaps::GeocoderResult::setFormattedAddress(const QString aFormattedAddress)
{
    this->m_formattedAddress = aFormattedAddress;
}

QString googleMaps::GeocoderResult::getFormattedAddress() const
{
    return this->m_formattedAddress ;
}

void googleMaps::GeocoderResult::setGeometry(const googleMaps::GeocoderGeometry aGeometry)
{
    this->m_geometry = aGeometry;
}

googleMaps::GeocoderGeometry googleMaps::GeocoderResult::getGeometry() const
{
    return this->m_geometry;
}

void googleMaps::GeocoderResult::setPartialMatch(const bool aPartialMatch)
{
    this->m_partialMatch = aPartialMatch;
}

bool googleMaps::GeocoderResult::isPartialMatch() const
{
    return this->m_partialMatch;
}

void googleMaps::GeocoderResult::setPlaceID(const QString aPlaceID)
{
    this->m_placeID = aPlaceID;
}

QString googleMaps::GeocoderResult::getPlaceID() const
{
    return this->m_placeID;
}

QStringList googleMaps::GeocoderResult::getPostcodeLocalities() const
{
    return this->m_postcodeLocalities;
}

void googleMaps::GeocoderResult::setPostcodeLocalities(const QList<QString> aPostcodeLocalities)
{
    this->m_postcodeLocalities = aPostcodeLocalities;
}

void googleMaps::GeocoderResult::setTypes(const QStringList types)
{
    this->m_types = types;
}

QStringList googleMaps::GeocoderResult::getTypes() const
{
    return this->m_types;
}
