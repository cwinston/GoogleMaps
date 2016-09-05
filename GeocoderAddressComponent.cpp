#include <exception>
#include <QVariant>
#include <QDebug>
#include "qtutils.h"
using namespace std;

#include "GeocoderAddressComponent.h"
googleMaps::GeocoderAddressComponent::GeocoderAddressComponent(QObject *parent)
{
    setParent(parent);
}

googleMaps::GeocoderAddressComponent::~GeocoderAddressComponent() {

}

googleMaps::GeocoderAddressComponent::GeocoderAddressComponent(const GeocoderAddressComponent& rhs)
{
    m_longName = rhs.getShortName();
    m_shortName = rhs.getShortName();
    m_types = rhs.getTypes();
}

//assignment operator
googleMaps::GeocoderAddressComponent& googleMaps::GeocoderAddressComponent::operator=(const GeocoderAddressComponent &rhs)
{
    if(this == &rhs) {
        return *this;
    }
    m_longName = rhs.getShortName();
    m_shortName = rhs.getShortName();
    m_types = rhs.getTypes();
    return *this;
}

void googleMaps::GeocoderAddressComponent::setLongName(const QString lname) {
    this->m_longName = lname;
}

QString googleMaps::GeocoderAddressComponent::getLongName() const
{
    return this->m_longName;
}

void googleMaps::GeocoderAddressComponent::setShortName(const QString sname)
{
    this->m_shortName = sname;
}

QString googleMaps::GeocoderAddressComponent::getShortName() const
{
    return this->m_shortName;
}

void googleMaps::GeocoderAddressComponent::setTypes(const QList<QString> aTypes)
{
    this->m_types = aTypes;
}

QList<QString> googleMaps::GeocoderAddressComponent::getTypes() const
{
    return this->m_types;
}

QVariantList googleMaps::GeocoderAddressComponent::exportTypes()
{
    return convert2VariantList(this->m_types);
}

void googleMaps::GeocoderAddressComponent::deserialize(const QVariant& data)
{
    QVariantMap addyPropMap = data.toMap();
     qDebug() << "[GeocoderResult] addy datacomponents result " << addyPropMap[GEO_ADDY_LONG_NAME].toString();
     setLongName(addyPropMap[GEO_ADDY_LONG_NAME].toString());
     setShortName(addyPropMap[GEO_ADDY_SHORT_NAME].toString());
     setTypes(addyPropMap[GEO_TYPES].toStringList());
}
