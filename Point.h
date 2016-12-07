#include <exception>
#include <QObject>
using namespace std;

#ifndef __Point_h__
#define __Point_h__

namespace googleMaps
{
	class Point;
}

namespace googleMaps
{
    class Point : public QObject
	{
        Q_OBJECT
        protected:
            qreal m_x;
            qreal m_y;

        public:
            explicit Point(QObject* parent = 0);
            Point(const Point& rhs);
            Point(qreal xVal, qreal yVal);
            googleMaps::Point& googleMaps::Point::operator=(const Point &rhs);
            bool equals(googleMaps::Point other);
            QString toString();
            void setX(qreal x);
            qreal getX() const;
            void setY(const qreal y);
            qreal getY() const;
	};
}

#endif
