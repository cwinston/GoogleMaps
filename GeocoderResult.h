#include <exception>
using namespace std;
#include <QObject>


#ifndef __GeocoderResult_h__
#define __GeocoderResult_h__

#include "qtutils.h"
#include "GeocoderAddressComponent.h"
#include "GeocoderGeometry.h"
#include <QStringListModel>
#include "GeoAddressComponentsModel.h"

#define GEO_ADDRESS_COMPONENTS "address_components"
#define GEO_FORMATTED_ADDRESS "formatted_address"
#define GEO_GEOMETRY  "geometry"
#define GEO_PARTIAL_MATCH "partial_match"
#define GEO_PLACE_ID "place_id"
#define GEO_TYPES "types"
#define GEO_ADDY_LONG_NAME "long_name"
#define GEO_ADDY_SHORT_NAME  "short_name"


namespace googleMaps
{
    class GeocoderAddressComponent;
     class GeoAddressComponentsModel;
    class GeocoderGeometry;
    class GeocoderResult;

}

namespace googleMaps
{

    /**
     *
     * street_address indicates a precise street address.
     * route indicates a named route (such as "US 101").
     * intersection indicates a major intersection, usually of two major roads.
     * political indicates a political entity. Usually, this type indicates a polygon of some civil administration.
     * country indicates the national political entity, and is typically the highest order type returned by the Geocoder.
     * administrative_area_level_1 indicates a first-order civil entity below the country level. Within the United States, these administrative levels are states. Not all nations exhibit these administrative levels.
     * administrative_area_level_2 indicates a second-order civil entity below the country level. Within the United States, these administrative levels are counties. Not all nations exhibit these administrative levels.
     * administrative_area_level_3 indicates a third-order civil entity below the country level. This type indicates a minor civil division. Not all nations exhibit these administrative levels.
     * administrative_area_level_4 indicates a fourth-order civil entity below the country level. This type indicates a minor civil division. Not all nations exhibit these administrative levels.
     * administrative_area_level_5 indicates a fifth-order civil entity below the country level. This type indicates a minor civil division. Not all nations exhibit these administrative levels.
     * colloquial_area indicates a commonly-used alternative name for the entity.
     * locality indicates an incorporated city or town political entity.
     * sublocality indicates a first-order civil entity below a locality. For some locations may receive one of the additional types: sublocality_level_1 through to sublocality_level_5. Each sublocality level is a civil entity. Larger numbers indicate a smaller geographic area.
     * neighborhood indicates a named neighborhood.
     * premise indicates a named location, usually a building or collection of buildings with a common name
     * subpremise indicates a first-order entity below a named location, usually a singular building within a collection of buildings with a common name.
     * postal_code indicates a postal code as used to address postal mail within the country.
     * natural_feature indicates a prominent natural feature.
     * airport indicates an airport.
     * park indicates a named park.
     *
     */
    class GeocoderResult : public QObject
    {
        Q_OBJECT
       // Q_PROPERTY(QObject addressComponents READ getAddressComponents WRITE setAddressComponents NOTIFY addressComponentsChanged)
        Q_PROPERTY(QString formattedAddress READ getFormattedAddress WRITE setFormattedAddress NOTIFY formattedAddressChanged)
        Q_PROPERTY(GeocoderGeometry geometry READ getGeometry WRITE setGeometry NOTIFY geometryChanged)
        Q_PROPERTY(bool partialMatch READ isPartialMatch WRITE setPartialMatch NOTIFY partialMatchChanged)
        Q_PROPERTY(QString placeID READ getPlaceID WRITE setPlaceID NOTIFY placeIDChanged)
        Q_PROPERTY(QStringList postcodeLocalities READ getPostcodeLocalities WRITE setPostcodeLocalities NOTIFY postcodeLocalitiesChanged)
        Q_PROPERTY(QStringList types READ getTypes WRITE setTypes NOTIFY typeChanged)

        protected:
            QList<googleMaps::GeocoderAddressComponent> m_addressComponents;
            QString m_formattedAddress;
            googleMaps::GeocoderGeometry m_geometry;
            bool m_partialMatch;
            QString m_placeID;
            QStringList m_postcodeLocalities;
            QStringList m_types;

        public:
            explicit GeocoderResult(QObject* parent = 0);
            //copy constructor
            GeocoderResult(const GeocoderResult& rhs);            //assignment operator
            GeocoderResult& operator=(const GeocoderResult &rhs);
            virtual ~GeocoderResult();
            void setAddressComponents(const QList<googleMaps::GeocoderAddressComponent> addressComponents);
            QList<googleMaps::GeocoderAddressComponent> getAddressComponents() const;
            void setFormattedAddress(const QString aFormattedAddress);
            QString getFormattedAddress() const ;
            void setGeometry(const googleMaps::GeocoderGeometry aGeometry);
            GeocoderGeometry getGeometry() const;
            void setPartialMatch(const  bool aPartialMatch);
            bool isPartialMatch() const ;
            void setPlaceID(const QString aPlaceID);
            QString getPlaceID() const ;
            void setPostcodeLocalities(const QList<QString> aPostcodeLocalities);
            QStringList getPostcodeLocalities() const ;
            void setTypes(const QStringList types);
            QStringList getTypes() const ;
            void parseIncomingData(const QVariant& data);
            void deserialize(const QVariantMap& data);


        signals:
            void addressComponentsChanged(bool modified);
            void formattedAddressChanged(bool modified);
            void geometryChanged(bool modified);
            void placeIDChanged(bool modified);
            void partialMatchChanged(bool modified);
            void postcodeLocalitiesChanged(bool modified);
            void typeChanged(bool modified);
    };

}

Q_DECLARE_METATYPE(googleMaps::GeocoderResult)

#endif
