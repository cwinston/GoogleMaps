#include <exception>
using namespace std;

#ifndef __PolygonOptions_h__
#define __PolygonOptions_h__

#include "LatLng.h"

#define POLYGON_CLICKABLE "clickable"
#define POLYGON_DRAGGABLE "draggable"
#define POLYGON_EDITABLE "editable"
#define POLYGON_VISIBLE "visible"
#define POLYGON_FILLCOLOR "fillColor"
#define POLYGON_STROKECOLOR "strokeColor"
#define POLYGON_STROKEOPACITY "strokeOpacity"
#define POLYGON_STROKEWEIGHT "strokeWeight"
#define POLYGON_FILLOPACITY "fillOpacity"
#define POLYGON_ZINDEX "zIndex"
#define POLYGON_PATH "path"

namespace googleMaps
{
	class LatLng;
	class PolygonOptions;
}

namespace googleMaps
{
    class PolygonOptions : public QObject
    {
        Q_OBJECT
        protected:
            bool m_clickable;
            bool m_draggable;
            bool m_editable;
            bool m_visible;
            QString m_fillColor;
            QString m_strokeColor;
            qreal m_strokeOpacity;
            qreal m_strokeWeight;
            qreal m_fillOpacity;
            qreal m_zIndex;
            QList<googleMaps::LatLng> m_path;

        public:
            explicit PolygonOptions(QObject* parent = 0);
            //copy constructor
            PolygonOptions(const PolygonOptions& rhs);
            //assignment operator
            PolygonOptions& operator=(const PolygonOptions &rhs);
            Q_INVOKABLE bool isClickable() const;
            Q_INVOKABLE bool isDraggable() const;
            Q_INVOKABLE bool isEditable() const;
            Q_INVOKABLE QString getFillColor() const;
            Q_INVOKABLE qreal getFillOpacity() const;
            Q_INVOKABLE QString getStrokeColor() const;
            Q_INVOKABLE qreal getStrokeOpacity() const;
            Q_INVOKABLE qreal getStrokeWeight() const;
            Q_INVOKABLE bool isVisible() const;
            Q_INVOKABLE qreal getZIndex() const;
            Q_INVOKABLE QList<LatLng> getPath() const;
            QVariantMap serialize() const;

        public slots:
            void setClickable(const bool clickable);
            void setDraggable(const bool draggable);
            void setEditable(const bool editable);
            void setFillColor(const QString fillColor);
            void setFillOpacity(const qreal fillOpacity);
            void setStrokeColor(const QString strokeColor);
            void setStrokeOpacity(const qreal strokeOpacity);
            void setStrokeWeight(const qreal strokeWeight);
            void setVisible(const bool visible);
            void setZIndex(const qreal zIndex);
            void setPath(const QList<googleMaps::LatLng> path);

        private:
            static QVariant serializePath(const QList<LatLng> &list );
	};
}
Q_DECLARE_METATYPE(googleMaps::PolygonOptions)

#endif
