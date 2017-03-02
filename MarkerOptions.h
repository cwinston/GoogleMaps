#include <exception>
using namespace std;

#ifndef __MarkerOptions_h__
#define __MarkerOptions_h__

#include "Point.h"
#include "LatLng.h"

#define MARKER_CLICKABLE "clickable"
#define MARKER_CROSSONDRAG "crossOnDrag"
#define MARKER_DRAGGABLE "draggable"
#define MARKER_LABEL    "label"
#define MARKER_ICON "icon"
#define MARKER_OPACITY "opacity"
#define MARKER_POSITION "position"
#define MARKER_TITLE "title"
#define MARKER_VISIBLE "visible"
#define MARKER_ZINDEX "zIndex"

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
        Q_PROPERTY(bool clickable READ isClickable WRITE setClickable NOTIFY clickable_changed)
        Q_PROPERTY(bool crossOnDrag READ isCrossOnDrag WRITE setCrossOnDrag NOTIFY crossOnDragChanged)
        Q_PROPERTY(bool draggable READ isDraggable WRITE setDraggable NOTIFY draggable_changed)
        Q_PROPERTY(QString label READ getLabel WRITE setLabel NOTIFY labelChanged)
        Q_PROPERTY(QString icon READ getIcon WRITE setIcon NOTIFY iconChanged)
        Q_PROPERTY(qreal opacity READ getOpacity WRITE setOpacity NOTIFY opacityChanged)
        Q_PROPERTY(googleMaps::LatLng position READ getPosition WRITE setPosition NOTIFY position_changed)
        Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY title_changed)
        Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visible_changed)
        Q_PROPERTY(qreal zIndex READ getZIndex WRITE setZIndex NOTIFY zIndexChanged)
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
            Q_INVOKABLE googleMaps::Point getAnchorPoint() const;
            Q_INVOKABLE bool isClickable() const;
            Q_INVOKABLE bool isCrossOnDrag() const;
            Q_INVOKABLE bool isDraggable() const;
            Q_INVOKABLE QString getLabel() const;
            Q_INVOKABLE QString getIcon() const;
            Q_INVOKABLE qreal getOpacity() const;
            Q_INVOKABLE googleMaps::LatLng getPosition() const;
            Q_INVOKABLE QString getTitle() const;
            Q_INVOKABLE bool isVisible() const;
            Q_INVOKABLE qreal getZIndex() const;
            void deserialize(const QVariantMap& data);
            void deserialize(const QVariant& data);
            QVariantMap serialize() const;

        public slots:
            void setZIndex(qreal zIndex);
            void setVisible(bool visible);
            void setTitle(QString title);
            void setPosition(googleMaps::LatLng position);
            void setOpacity(qreal opacity);
            void setIcon(QString icon);
            void setLabel(QString label);
            void setDraggable(bool draggable);
            void setCrossOnDrag(bool crossOnDrag);
            void setClickable(bool clickable);
            void setAnchorPoint(googleMaps::Point anchorPoint);

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
            void opacityChanged();
            void zIndexChanged();
            void iconChanged();
            void labelChanged();
            void crossOnDragChanged();
	};
}

Q_DECLARE_METATYPE(googleMaps::MarkerOptions)

#endif
