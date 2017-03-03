#include <exception>
using namespace std;

#ifndef __MapType_h__
#define __MapType_h__

#include "Size.h"

namespace googleMaps
{
	class Size;
	class MapType;
}

namespace googleMaps
{
	class MapType
	{
		protected: QString _alt;
		protected: int _maxZoom;
		protected: int _minZoom;
		protected: QString _name;
		protected: int _radius;
		protected: string _projection;
		protected: googleMaps::Size _tileSize;

		public: void setAlt(QString alt);

		public: QString getAlt();

		public: void setMaxZoom(int maxZoom);

		public: int getMaxZoom();

		public: void setMinZoom(int minZoom);

		public: int getMinZoom();

		public: void setName(QString name);

		public: QString getName();

		public: void setTileSize(googleMaps::Size tileSize);

		public: googleMaps::Size getTileSize();

		public: MapType();
	};
}

#endif
