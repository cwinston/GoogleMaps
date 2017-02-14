#include <exception>
using namespace std;

#ifndef __LatLngValidator_h__
#define __LatLngValidator_h__

#include <QRegExpValidator>

namespace googleMaps
{
	class LatLngValidator;
}

namespace googleMaps
{
    class LatLngValidator: public QRegExpValidator
	{
        public:
            LatLngValidator(QObject* parent = 0);
	};
}

#endif
