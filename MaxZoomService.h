#include <exception>
using namespace std;

#ifndef __MaxZoomService_h__
#define __MaxZoomService_h__

#include "MaxZoomResult.h"
#include "LatLng.h"

namespace googleMaps
{
	class MaxZoomResult;
	class LatLng;
	class MaxZoomService;
}

namespace googleMaps
{

    enum MaxZoomStatus
    {
        OK,
        MAXZOOM_ERROR
    };

    class MaxZoomService : public QObject
	{
        Q_OBJECT
        protected:
            googleMaps::MaxZoomResult m_results;

        public:
            explicit MaxZoomService(QObject* parent = 0);

            void getMaxZoomAtLatLng(googleMaps::LatLng latLng);

            void setResults(const googleMaps::MaxZoomResult results);

            googleMaps::MaxZoomResult getResults() const;
	};
}

#endif
