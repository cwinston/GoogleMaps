#include <exception>
#include <string>
using namespace std;

#ifndef __Marker_h__
#define __Marker_h__

#include "LatLng.h"
#include "MarkerOptions.h"

namespace googleMaps
{
	class LatLng;
	class Marker;
    class MarkerOptions;
}

namespace googleMaps
{
    class Marker : public QObject
	{
        Q_OBJECT
        //protected: googleMaps::Point _anchorPoint;
        protected:
            MarkerOptions m_options;

        public:
            explicit Marker(QObject* parent = 0);
            googleMaps::Marker::Marker(const Marker& rhs);
            Marker(MarkerOptions opts);
            googleMaps::Marker& googleMaps::Marker::operator=(const Marker &rhs);
            bool getDraggable();
            bool getClickable();
            googleMaps::LatLng getPosition();
            void setClickable(bool clickable);
            void setDraggable(bool draggable);
            void setLabel(QString label);
            QString getLabel();
            void setPosition(googleMaps::LatLng position);
            void setTitle(QString title);
            QString getTitle();
            void setVisible(bool visible);
            bool isVisible();
            void setZIndex(int zIndex);
            int getZIndex();
            void setOptions(MarkerOptions opts);
            MarkerOptions getOptions() const;

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

#endif
