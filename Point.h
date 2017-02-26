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
            bool googleMaps::Point::operator==(const Point &rhs);
            bool equals(const googleMaps::Point other);
            QString toString();           
            qreal getX() const;
            qreal getY() const;

        public slots:
            void setY(const qreal y);
            void setX(const qreal x);

        signals:
           void pointChanged();
	};
}

Q_DECLARE_METATYPE(googleMaps::Point)

#endif
