#include <exception>
using namespace std;

#ifndef __Map_h__
#define __Map_h__

//#include "MapTypeRegistry.h"
#include <QMap>
#include <QVariant>
#include "MapOptions.h"
#include "LatLngBounds.h"
#include "LatLng.h"
#include "Size.h"

namespace googleMaps
{
	class MapTypeRegistry;
	class MapOptions;
	class LatLngBounds;
	class LatLng;
	class MouseEvent;
	// class AbstractGoogleMapsService;
	class Map;
    class Size;
}

namespace googleMaps
{
    
    enum EMapTypeControlStyle
    {
        MTCS_DEFAULT = 0,
        MTCS_DROPDOWN_MENU,
        MTCS_HORIZONTAL_BAR,
    };
    
    enum EControlPosition
    {
        ECP_BOTTOM_CENTER = 0,
        ECP_BOTTOM_LEFT,
        ECP_BOTTOM_RIGHT,
        ECP_LEFT_BOTTOM,
        ECP_LEFT_CENTER,
        ECP_LEFT_TOP,
        ECP_RIGHT_BOTTOM,
        ECP_RIGHT_CENTER,
        ECP_RIGHT_TOP,
        ECP_TOP_CENTER,
        ECP_TOP_LEFT,
        ECP_TOP_RIGHT,
    };

    class MapType: public QObject
    {
        Q_OBJECT
        protected:
            QString m_alt;
            int m_maxZoom;
            int m_minZoom;
            QString m_name;
            int m_radius;
            QString m_projection;
            googleMaps::Size m_tileSize;

        public:
            explicit MapType(QObject* parent = 0){m_radius = 6378137; setParent(parent);}
            void googleMaps::MapType::setAlt(QString alt) { this->m_alt = alt;  }
            QString googleMaps::MapType::getAlt() { return this->m_alt; }
            void googleMaps::MapType::setMaxZoom(int maxZoom) {this->m_maxZoom = maxZoom;}
            int googleMaps::MapType::getMaxZoom() {return this->m_maxZoom;}
            void googleMaps::MapType::setMinZoom(int minZoom) { this->m_minZoom = minZoom; }
            int googleMaps::MapType::getMinZoom() { return this->m_minZoom; }
            void googleMaps::MapType::setName(QString name) { this->m_name = name; }
            QString googleMaps::MapType::getName() { return this->m_name; }
            void googleMaps::MapType::setTileSize(googleMaps::Size tileSize) { this->m_tileSize = tileSize; }
            googleMaps::Size googleMaps::MapType::getTileSize() { return this->m_tileSize; }
    };


    class MapTypeRegistry: public QObject
    {
        Q_OBJECT
        protected:
            QMap<QString, googleMaps::MapType*> registry;
        public:
            explicit MapTypeRegistry(QObject* parent = 0) {setParent(parent);}
            void set(QString id, MapType* mapType) {registry[id] = mapType;}
            QMap<QString, googleMaps::MapType*> get() const {return registry;}
            MapTypeRegistry(const googleMaps::MapTypeRegistry& rhs)
            {
                for (auto key : rhs.get().keys())
                {
                    MapType*  type = rhs.get().value(key);
                    registry.insert(key, type);
                }
            }
            googleMaps::MapTypeRegistry& googleMaps::MapTypeRegistry::operator =(const googleMaps::MapTypeRegistry& rhs)
            {
                if(this == &rhs)
                {
                    return *this;
                }
                for (auto key : rhs.get().keys())
                {
                    MapType*  type = rhs.get().value(key);
                    registry.insert(key, type);
                }
                return *this;
            }

    };

    
    class Map: public QObject
	{
        Q_OBJECT
        Q_PROPERTY(googleMaps::LatLngBounds bounds READ getBounds NOTIFY boundsChanged WRITE updateBounds)
        Q_PROPERTY(googleMaps::LatLng center READ getCenter NOTIFY centerChanged WRITE centerMapAt)
        Q_PROPERTY(int zoom READ getZoom WRITE updateZoom NOTIFY zoom_changed)
        Q_PROPERTY(QString mapsKey READ getMapsKey NOTIFY mapsKeySet)

        protected:
            googleMaps::MapTypeRegistry m_mapTypes;
            googleMaps::LatLngBounds m_bounds;
            googleMaps::MapOptions m_options;
            googleMaps::LatLng m_mapCenter;
            googleMaps::EMapTypeID m_mapTypeID;
            int m_tilt;
            int m_zoom;
            QString m_mapsKey;

        public:
            explicit Map( QObject* parent = 0);
            Map(const MapOptions options);
            Map(const googleMaps::Map &rhs);
            //assignment operator
            googleMaps::Map& operator=(const googleMaps::Map &rhs);
            virtual ~Map();
            void fitBounds(googleMaps::LatLngBounds bounds);
            googleMaps::LatLngBounds getBounds() const;
            googleMaps::LatLng getCenter() const;
            googleMaps::MapOptions getOptions() const;
            googleMaps::EMapTypeID getMapTypeId() const;
            googleMaps::MapTypeRegistry getMapTypes() const;
            int getZoom() const;
            int getTilt() const;
            void panMapTo(googleMaps::LatLng latLng);
            void setMapsKey(const QString key);
            void setOptions(const googleMaps::MapOptions options);
            QString getMapsKey() const;

            
        public slots:
            void updateMapTypeId(googleMaps::EMapTypeID mapTypeId);
            void updateZoom(QVariant zoom);
            void updateCenter(QVariant latlng);
            void updateOptions(googleMaps::MapOptions options);
            void updateTilt(int tilt);
            void updateBounds(LatLngBounds latLngBounds);
            void centerMapAt(googleMaps::LatLng latLng);
            void panToBound(googleMaps::LatLngBounds latLngBounds);
            void updateMapTypes(googleMaps::MapTypeRegistry mapTypes);
            void startMap();

        signals:
            void boundsChanged(googleMaps::LatLngBounds latLngBounds);
            void centerChanged(googleMaps::LatLng position);
            void click(LatLng mapLocation);
            void dblclick(LatLng mapLocation);
            void drag();
            void dragend();
            void dragstart();
            void maptypeid_changed();
            void resize();
            void zoom_changed(qreal zoomLevel);
            void centerOnLocation(qreal lat, qreal lng);
            void mapsKeySet();
            void optionsChanged();
            void startMapView();

	};
}

Q_DECLARE_METATYPE(googleMaps::Map)

#endif
