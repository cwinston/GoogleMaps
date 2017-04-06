#include <exception>
using namespace std;

#ifndef __PathElevationRequest_h__
#define __PathElevationRequest_h__

#include "LatLng.h"

namespace googleMaps
{
	class LatLng;
	class PathElevationRequest;
}

namespace googleMaps
{
    class PathElevationRequest : public QObject
	{
        Q_OBJECT
        Q_PROPERTY(QVariantList path READ getPath NOTIFY pathChanged)
        Q_PROPERTY(qreal samples READ getSamples NOTIFY samplesChanged)
        protected:
            QVariantList m_path;
            qreal m_samples;

        public:
            PathElevationRequest(QObject *parent = 0);
            //copy constructor
            PathElevationRequest(const PathElevationRequest& rhs);
            virtual ~PathElevationRequest();
            googleMaps::PathElevationRequest& operator=(const googleMaps::PathElevationRequest rhs);
            void importPath(const QList<googleMaps::LatLng> path);
            QVariantList getPath() const;
            qreal getSamples() const;

        public slots:
            void setSamples(qreal samples);
            void setPath(QVariantList path);
            
        signals:
            void pathChanged();
            void samplesChanged();
	};
    Q_DECLARE_METATYPE(googleMaps::PathElevationRequest)
}

#endif
