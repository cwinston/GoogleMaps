#include <exception>
using namespace std;

#include "MapType.h"
#include "Size.h"

void googleMaps::MapType::setAlt(QString alt) {
	this->_alt = alt;
}

QString googleMaps::MapType::getAlt() {
	return this->_alt;
}

void googleMaps::MapType::setMaxZoom(int maxZoom) {
	this->_maxZoom = maxZoom;
}

int googleMaps::MapType::getMaxZoom() {
	return this->_maxZoom;
}

void googleMaps::MapType::setMinZoom(int minZoom) {
	this->_minZoom = minZoom;
}

int googleMaps::MapType::getMinZoom() {
	return this->_minZoom;
}

void googleMaps::MapType::setName(QString name) {
	this->_name = name;
}

QString googleMaps::MapType::getName() {
	return this->_name;
}

void googleMaps::MapType::setTileSize(googleMaps::Size tileSize) {
	this->_tileSize = tileSize;
}

googleMaps::Size googleMaps::MapType::getTileSize() {
	return this->_tileSize;
}

googleMaps::MapType::MapType() {
	_radius = 6378137;
}

