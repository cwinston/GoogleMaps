#include <exception>
using namespace std;

#include "LatLngValidator.h"
#include <QRegExpValidator>
#include <QRegExp>

googleMaps::LatLngValidator::LatLngValidator(QObject* parent)
{
    setParent(parent);
    QRegExp  rx("^(\\()([-+]?)([\\d]{1,2})(((\\.)(\\d+)(,)))(\\s*)(([-+]?)([\\d]{1,3})((\\.)(\\d+))?(\\)))$");
    setRegExp(rx);
}

