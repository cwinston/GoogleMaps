#include <exception>
using namespace std;

#ifndef __MapOptions_h__
#define __MapOptions_h__

#include "LatLng.h"

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
            MapOptions(const MapOptions& options);
            void setBackgroundColor(QString backgroundColor);
            QString getBackgroundColor();
            void setCenter(googleMaps::LatLng center);
            googleMaps::LatLng getCenter();
            void setDisableDefaultUI(bool disableDefaultUI);
            bool isDisableDefaultUI();
            void setDisableDoubleClickZoom(bool disableDoubleClickZoom);
            bool isDisableDoubleClickZoom();
            void setDraggable(bool draggable);
            bool isDraggable();
            void setMapTypeControl(bool mapTypeControl);
            bool isMapTypeControl();
            void setMapTypeId(googleMaps::EMapTypeID mapTypeId);
            googleMaps::EMapTypeID getMapTypeId();
            void setMaxZoom(int maxZoom);
            int getMaxZoom();

            int getMinZoom();

            int getZoom();
            int getFullscreenControlPosition();
            int getZoomControlPosition();
            bool isZoomControl();
            bool isClickableIcons();
            bool isFullscreenControl();
            qreal getHeading();
            bool isRotateControl();
            int getRotateControlPosition();

        public slots:
            void setZoomControlPosition(int zoomControlPosition);
            void setFullscreenControlPosition(int fullscreenControlPosition);
            void setRotateControlPosition(int rotateControlPosition);
            void setRotateControl(bool rotateControl);
            void setHeading(qreal heading);
            void setFullscreenControl(bool fullscreenControl);
            void setClickableIcons(bool clickableIcons);
            void setZoomControl(bool zoomControl);
            void setZoom(int zoom);
            void setMinZoom(int minZoom);


	};
}

Q_DECLARE_METATYPE(googleMaps::MapOptions)

#endif
