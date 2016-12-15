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
            //copy constructor
            MapOptions(const MapOptions& rhs);
            //assignment operator
            MapOptions& operator=(const MapOptions &rhs);
            QString getBackgroundColor() const;
            googleMaps::LatLng getCenter() const;
            bool isDisableDefaultUI() const;
            bool isDisableDoubleClickZoom() const;
            bool isDraggable() const;
            bool hasMapTypeControl() const;
            googleMaps::EMapTypeID getMapTypeId() const;
            int getMaxZoom() const;
            int getMinZoom() const;
            int getZoom() const;
            int getFullscreenControlPosition() const;
            int getZoomControlPosition() const;
            bool hasZoomControl() const;
            bool hasClickableIcons() const;
            bool hasFullscreenControl() const;
            qreal getHeading() const;
            bool hasRotateControl() const;
            int getRotateControlPosition() const;

        public slots:
            void updateZoomControlPosition(int zoomControlPosition);
            void updateFullscreenControlPosition(int fullscreenControlPosition);
            void updateRotateControlPosition(int rotateControlPosition);
            void updateRotateControl(bool rotateControl);
            void updateHeading(qreal heading);
            void updateFullscreenControl(bool fullscreenControl);
            void updateClickableIcons(bool clickableIcons);
            void updateZoomControl(bool zoomControl);
            void updateZoom(int zoom);
            void updateMinZoom(int minZoom);
            void updateMaxZoom(int maxZoom);
            void updateMapTypeId(googleMaps::EMapTypeID mapTypeId);
            void updateMapTypeControl(bool mapTypeControl);
            void updateDraggable(bool draggable);
            void updateDisableDoubleClickZoom(bool disableDoubleClickZoom);
            void updateDisableDefaultUI(bool disableDefaultUI);
            void updateCenter(googleMaps::LatLng center);
            void updateBackgroundColor(QString backgroundColor);


	};
}

Q_DECLARE_METATYPE(googleMaps::MapOptions)

#endif
