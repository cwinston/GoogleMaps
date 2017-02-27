#include <exception>
using namespace std;

#ifndef __PolygonOptions_h__
#define __PolygonOptions_h__

#include "LatLng.h"

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
            bool isClickable() const;
            bool isDraggable() const;
            bool isEditable() const;
            QString getFillColor() const;
            qreal getFillOpacity() const;
            QString getStrokeColor() const;
            qreal getStrokeOpacity() const;
            qreal getStrokeWeight() const;
            bool isVisible() const;
            qreal getZIndex() const;
            QList<googleMaps::LatLng> getPath() const;
	};
}
Q_DECLARE_METATYPE(googleMaps::PolygonOptions)

#endif
