#include <exception>
using namespace std;

#ifndef __Polygon_h__
#define __Polygon_h__

#include "PolygonOptions.h"

namespace googleMaps
{
	class PolygonOptions;
	class Polygon;
}

namespace googleMaps
{
    class Polygon : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(bool clickable READ isClickable WRITE updateClickable NOTIFY clickableChanged)
        Q_PROPERTY(bool draggable READ isDraggable WRITE updateDraggable NOTIFY draggableChanged)
        Q_PROPERTY(bool editable READ isEditable WRITE updateEditable NOTIFY editableChanged)
        Q_PROPERTY(bool visible READ isVisible WRITE updateVisible NOTIFY visibleChanged)

        Q_PROPERTY(QString fillColor READ getFillColor WRITE updateFillColor NOTIFY fillColorChanged)
        Q_PROPERTY(qreal fillOpacity READ getFillOpacity WRITE updateFillOpacity NOTIFY fillOpacityChanged)
        Q_PROPERTY(QString strokeColor READ getStrokeColor WRITE updateStrokeColor NOTIFY strokeColorChanged)
        Q_PROPERTY(qreal strokeOpacity READ getStrokeOpacity WRITE updateStrokeOpacity NOTIFY strokeOpacityChanged)
        Q_PROPERTY(qreal strokeOpacity READ getStrokeOpacity WRITE updateStrokeOpacity NOTIFY strokeOpacityChanged)
        Q_PROPERTY(qreal strokeWeight READ getStrokeWeight WRITE updateStrokeWeight NOTIFY strokeWeightChanged)
        Q_PROPERTY(qreal zIndex READ getZIndex WRITE updateZIndex NOTIFY zIndexChanged)
        protected:
            googleMaps::PolygonOptions m_options;

        public:
            explicit Polygon(QObject *parent = 0);
            Polygon(googleMaps::PolygonOptions opt);
            //copy constructor
            Polygon(const Polygon& rhs);
            //assignment operator
            Polygon& operator=(const Polygon &rhs);
            bool isClickable() const;
            bool isDraggable() const;
            bool isEditable() const;
            bool isVisible() const;
            QString getFillColor() const;
            qreal getFillOpacity() const;
            QString getStrokeColor() const;
            qreal getStrokeOpacity() const;
            qreal getStrokeWeight() const;           
            qreal getZIndex() const;
            QList<googleMaps::LatLng> getPath() const;
            googleMaps::PolygonOptions getOptions() const;

        public slots:
            void updateOptions(googleMaps::PolygonOptions options);
            void updateClickable(const bool clickable);
            void updateDraggable(const bool draggable);
            void updateEditable(const bool editable);
            void updateFillColor(const QString fillColor);
            void updateFillOpacity(const qreal fillOpacity);
            void updateStrokeColor(const QString strokeColor);
            void updateStrokeOpacity(const qreal strokeOpacity);
            void updateStrokeWeight(const qreal strokeWeight);
            void updateVisible(const bool visible);
            void updateZIndex(const qreal zIndex);
            void updatePath(const QList<googleMaps::LatLng> path);

        signals:
            void optionsChanged();
            void clickableChanged();
            void draggableChanged();
            void editableChanged();
            void visibleChanged();
            void fillColorChanged();
            void fillOpacityChanged();
            void strokeColorChanged();
            void strokeOpacityChanged();
            void strokeWeightChanged();
            void zIndexChanged();

	};
}

Q_DECLARE_METATYPE(googleMaps::Polygon)

#endif
