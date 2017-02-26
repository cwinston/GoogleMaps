#include <exception>
using namespace std;

#ifndef __MarkerOptions_h__
#define __MarkerOptions_h__

#include "Point.h"
#include "LatLng.h"

namespace googleMaps
{
	class Point;
	class LatLng;
	class MarkerOptions;
}

namespace googleMaps
{
    class MarkerOptions : public QObject
	{
        Q_OBJECT
        protected:
            googleMaps::Point m_anchorPoint;
            bool m_clickable;
            bool m_crossOnDrag;
            bool m_draggable;
            QString m_label;
            QString m_icon;
            qreal m_opacity;
            googleMaps::LatLng m_position;
            QString m_title;
            bool m_visible;
            qreal m_zIndex;

        public:
            explicit MarkerOptions(QObject* parent = 0);
            MarkerOptions(const MarkerOptions& rhs);
            //assignment operator
            MarkerOptions& operator=(const MarkerOptions &rhs);
            void setAnchorPoint(googleMaps::Point anchorPoint);
            googleMaps::Point getAnchorPoint() const;
            void setClickable(bool clickable);
            bool isClickable() const;
            void setCrossOnDrag(bool crossOnDrag);
            bool isCrossOnDrag() const;
            void setDraggable(bool draggable);
            bool isDraggable() const;
            void setLabel(QString label);
            QString getLabel() const;
            void setIcon(QString icon);
            QString getIcon() const;
            void setOpacity(qreal opacity);
            qreal getOpacity() const;
            void setPosition(googleMaps::LatLng position);
            googleMaps::LatLng getPosition() const;
            void setTitle(QString title);
            QString getTitle() const;
            void setVisible(bool visible);
            bool isVisible() const;
            void setZIndex(qreal zIndex);
            qreal getZIndex() const;
            void deserialize(const QVariantMap& data);
            void deserialize(const QVariant& data);

        signals:
            void click();
            void clickable_changed();
            void dblclick();
            void drag();
            void dragEnd();
            void draggable_changed();
            void dragStart();
            void rightclick();
            void position_changed();
            void visible_changed();
            void title_changed();
	};
}

Q_DECLARE_METATYPE(googleMaps::MarkerOptions)

#endif
