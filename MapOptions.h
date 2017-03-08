#include <exception>
using namespace std;

#ifndef __MapOptions_h__
#define __MapOptions_h__

#include "LatLng.h"

#define MAP_BACKGROUND_COLOR "backgroundColor"
#define MAP_CENTER "center"
#define MAP_DISABLED_DEFAULT_UI "disableDefaultUI"
#define MAP_DISABLED_DOUBLECLICK    "disableDoubleClickZoom"
#define MAP_DRAGGABLE "draggable"
#define MAP_MAPTYPECONTROL "mapTypeControl"
#define MAP_MAPTYPEID "mapTypeId"
#define MAP_MAXZOOM "maxZoom"
#define MAP_MINZOOM "minZoom"
#define MAP_ZOOM "zoom"
#define MAP_ZOOMCONTROL "zoomControl"
#define MAP_CLICKABLE_ICONS "clickableIcons"
#define MAP_FULLSCREEN_CONTROL "fullscreenControl"
#define MAP_HEADING "heading"
#define MAP_ROTATE_CONTROL "rotateControl"
#define MAP_ROTATE_CONTROL_POSITION "rotateControlPosition"
#define MAP_FULLSCREEN_CONTROL_POSITION "fullscreenControlPosition"
#define MAP_ZOOMCONTROL_POSITION "zoomControlPosition"

namespace googleMaps
{
	class LatLng;
    enum E_MapTypeId;
	class MapOptions;
}

namespace googleMaps
{

    enum EMapTypeID
    {
        MAP_HYBRID = 0,
        MAP_ROADMAP,
        MAP_SATELITE,
        MAP_TERRAIN,
    };

    class MapOptions : public QObject
	{
        Q_OBJECT
        Q_ENUMS(EMapTypeID)
        protected:
            QString m_backgroundColor;
            googleMaps::LatLng m_center;
            bool m_disableDefaultUI;
            bool m_disableDoubleClickZoom;
            bool m_draggable;
            bool m_mapTypeControl;
            googleMaps::EMapTypeID m_mapTypeId;
            int m_maxZoom;
            int m_minZoom;
            int m_zoom;
            bool m_zoomControl;
            bool m_clickableIcons;
            bool m_fullscreenControl;
            qreal m_heading;
            bool m_rotateControl;
            int m_rotateControlPosition;
            int m_fullscreenControlPosition;
            int m_zoomControlPosition;

        public:
            explicit MapOptions(QObject* parent = 0);
            //copy constructor
            MapOptions(const MapOptions& rhs);
            //assignment operator
            MapOptions& operator=(const MapOptions &rhs);
            Q_INVOKABLE QString getBackgroundColor() const;
            Q_INVOKABLE googleMaps::LatLng getCenter() const;
            Q_INVOKABLE bool isDisableDefaultUI() const;
            Q_INVOKABLE bool isDisableDoubleClickZoom() const;
            Q_INVOKABLE bool isDraggable() const;
            Q_INVOKABLE bool hasMapTypeControl() const;
            Q_INVOKABLE googleMaps::EMapTypeID getMapTypeId() const;
            Q_INVOKABLE int getMaxZoom() const;
            Q_INVOKABLE int getMinZoom() const;
            Q_INVOKABLE int getZoom() const;
            Q_INVOKABLE int getFullscreenControlPosition() const;
            Q_INVOKABLE int getZoomControlPosition() const;
            Q_INVOKABLE bool hasZoomControl() const;
            Q_INVOKABLE bool hasClickableIcons() const;
            Q_INVOKABLE bool hasFullscreenControl() const;
            Q_INVOKABLE qreal getHeading() const;
            Q_INVOKABLE bool hasRotateControl() const;
            Q_INVOKABLE int getRotateControlPosition() const;
            QVariantMap serialize() const;

        public slots:
            void updateZoomControlPosition(const int zoomControlPosition);
            void updateFullscreenControlPosition(const int fullscreenControlPosition);
            void updateRotateControlPosition(const int rotateControlPosition);
            void updateRotateControl(const bool rotateControl);
            void updateHeading(const qreal heading);
            void updateFullscreenControl(const bool fullscreenControl);
            void updateClickableIcons(const bool clickableIcons);
            void updateZoomControl(const bool zoomControl);
            void updateZoom(const int zoom);
            void updateMinZoom(const int minZoom);
            void updateMaxZoom(const int maxZoom);
            void updateMapTypeId(const googleMaps::EMapTypeID mapTypeId);
            void updateMapTypeControl(const bool mapTypeControl);
            void updateDraggable(const bool draggable);
            void updateDisableDoubleClickZoom(const bool disableDoubleClickZoom);
            void updateDisableDefaultUI(const bool disableDefaultUI);
            void updateCenter(const googleMaps::LatLng center);
            void updateBackgroundColor(const QString backgroundColor);


	};
}

Q_DECLARE_METATYPE(googleMaps::MapOptions)

#endif
