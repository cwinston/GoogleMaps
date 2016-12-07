#include <exception>
using namespace std;

#include "Map.h"
//#include "MapTypeRegistry.h"
#include "MapOptions.h"
#include "LatLngBounds.h"
#include "LatLng.h"
//#include "MouseEvent.h"
//#include "AbstractGoogleMapsService.h"

googleMaps::Map::Map(QObject *parent)
{
    setParent(parent);
}

googleMaps::Map::~Map()
{

}

googleMaps::Map::Map(googleMaps::MapOptions options) {
}

googleMaps::Map::Map(const googleMaps::Map &rhs, QObject* parent)
{
}

void googleMaps::Map::updateBounds(googleMaps::LatLngBounds latLngBounds)
{

}

void googleMaps::Map::fitBounds(googleMaps::LatLngBounds bounds) {
	throw "Not yet implemented";
}

googleMaps::LatLngBounds googleMaps::Map::getBounds() {
	throw "Not yet implemented";
}

googleMaps::LatLng googleMaps::Map::getCenter() {
	throw "Not yet implemented";
}

googleMaps::EMapTypeID googleMaps::Map::getMapTypeId() {
	throw "Not yet implemented";
}

int googleMaps::Map::getZoom() {
	throw "Not yet implemented";
}

void googleMaps::Map::updateCenter(googleMaps::LatLng latlng) {
	throw "Not yet implemented";
}

void googleMaps::Map::panToBound(googleMaps::LatLngBounds latLngBounds) {
	throw "Not yet implemented";
}

void googleMaps::Map::updateMapTypeId(googleMaps::EMapTypeID mapTypeId) {
	throw "Not yet implemented";
}

void googleMaps::Map::updateZoom(int zoom) {
	throw "Not yet implemented";
}

void googleMaps::Map::updateOptions(googleMaps::MapOptions options) {
	throw "Not yet implemented";
}

void googleMaps::Map::panMapTo(googleMaps::LatLng latLng) {
	throw "Not yet implemented";
}

int googleMaps::Map::getTilt() {
	throw "Not yet implemented";
}

void googleMaps::Map::updateTilt(int tilt) {
	throw "Not yet implemented";
}


//void googleMaps::Map::setMapTypes(googleMaps::MapTypeRegistry mapTypes) {
//	this->_mapTypes = mapTypes;
//}

//googleMaps::MapTypeRegistry googleMaps::Map::getMapTypes() {
//	return this->_mapTypes;
//}

