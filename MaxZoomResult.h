#include <exception>
using namespace std;
#include <QObject>

#ifndef __MaxZoomResult_h__
#define __MaxZoomResult_h__


namespace googleMaps
{
    //
	class MaxZoomResult;
    enum MaxZoomStatus;
}

namespace googleMaps
{
    class MaxZoomResult : public QObject
	{
        Q_OBJECT
        protected:
            qreal m_zoom;
            googleMaps::MaxZoomStatus m_status;

        public:
            MaxZoomResult(QObject* parent = 0);
            MaxZoomResult(const MaxZoomResult& rhs);
            MaxZoomResult& operator=(const MaxZoomResult &rhs);
            void setZoom(const qreal aZoom);
            qreal getZoom() const;
            void setStatus(const googleMaps::MaxZoomStatus aStatus);
            googleMaps::MaxZoomStatus getStatus() const;
	};
}

#endif
