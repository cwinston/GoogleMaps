#include <exception>
#include <QObject>
using namespace std;

#ifndef __Size_h__
#define __Size_h__

namespace googleMaps
{
	class Size;
}

namespace googleMaps
{
    class Size : public QObject
	{
        protected:
            qreal m_height;
            qreal m_width;

        public:
            Size(QObject* parent = 0);
            Size(qreal width, qreal height);
            Size(const googleMaps::Size& rhs);
            //assignment operator
            Size& operator=(const Size &rhs);
            bool equals(googleMaps::Size other);
            QString toString();
            void setHeight(qreal height);
            qreal getHeight() const;
            void setWidth(qreal width);
            qreal getWidth() const;
	};
}

#endif
