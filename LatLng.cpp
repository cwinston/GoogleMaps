    #include <exception>
    using namespace std;
    #include <QDebug>
    #include "LatLng.h"

    googleMaps::LatLng::LatLng(QObject *parent):m_lat(-1), m_lng(-1)
    {
        setParent(parent);
    }

    googleMaps::LatLng::LatLng(const qreal lat, const qreal lng):m_lat(lat), m_lng(lng)
    {
    }

    //copy constructor
    googleMaps::LatLng::LatLng(const LatLng& rhs)
    {
        m_lat = rhs.lat();
        m_lng = rhs.lng();

    }

    //assignment operator
    googleMaps::LatLng& googleMaps::LatLng::operator=(const LatLng &rhs)
    {
        if(this == &rhs)
        {
            return *this;
        }
        m_lat = rhs.lat();
        m_lng = rhs.lng();
        return *this;
    }

    googleMaps::LatLng::~LatLng()
    {
    }

    qreal googleMaps::LatLng::lat() const
    {
        return m_lat;
    }

    qreal googleMaps::LatLng::lng() const
    {
        return m_lng;
    }

    void googleMaps::LatLng::setLat(const qreal lat)
    {
        m_lat = lat;
        emit latChanged(lat);
    }

    void googleMaps::LatLng::setLng(const qreal lng)
    {
        m_lng = lng;
        emit lngChanged(lng);
    }

    QString googleMaps::LatLng::toString() const
    {
        QString latlngStr = "("+QString::number(m_lat)+", "+QString::number(m_lng)+")";
        return latlngStr;
    }

    bool googleMaps::LatLng::isValidLatLng(const googleMaps::LatLng& position)
    {
        LatLngValidator* validator = new LatLngValidator();
        QString posStr = position.toString();
        int pos = 0;
        qDebug() << "[LatLng] posStr " <<  posStr;
        int validState = static_cast<int>(validator->validate(posStr, pos));
        qDebug() << "[LatLng] state   " << QString::number(validState);
        if ((position.lat() >= -90.00) && (position.lat() <= 90.00))
        {
            if ((position.lng() >= -180.00) && (position.lng() <= 180.00))
            {
                if (validState == 2)
                {
                    qDebug() << "[LatLng] latitude & longitude is valid ";
                    return true;
                }
            }
        }
        return false;
    }

    void  googleMaps::LatLng::deserialize(const QVariantMap& data)
    {
        qDebug() << "[LatLng] parse latLng result " << data << "\n";
         qDebug() << "[LatLng]  latLng keys " << data.keys() << "\n";
         for (auto locPoint : data.keys())
         {
             if (locPoint == GEO_LAT)
             {
                 m_lat = data[locPoint].toDouble();
             }
             else if (locPoint == GEO_LNG)
             {
                m_lng = data[locPoint].toDouble();
             }
         }
         qDebug() << "[LatLng]  lat  " << m_lat << "   lng "<< m_lng << "\n";
         isValidLatLng(*this);
    }


    void  googleMaps::LatLng::deserialize(const QVariant& data)
    {
         qDebug() << "[LatLng] parse latLng result " << data << "\n";
         qDebug() << "[LatLng]  latLng keys " << data.toMap().keys() << "\n";
         for (auto locPoint : data.toMap().keys())
         {
             if (locPoint == GEO_LAT)
             {
                 m_lat = data.toMap()[locPoint].toDouble();
             }
             else if (locPoint == GEO_LNG)
             {
                m_lng = data.toMap()[locPoint].toDouble();
             }
         }
         isValidLatLng(*this);
    }

    void googleMaps::LatLng::reset()
    {
        m_lat = -1;
        m_lng = -1;
    }


    QString googleMaps::LatLng::directionToText(const googleMaps::ECardinalPoints dir)
    {
        QString cardPos;
        switch(dir)
        {
            case DIR_EAST:
                cardPos = DIRECTION_EAST;
            break;
            case DIR_NORTH:
                cardPos = DIRECTION_NORTH;
                break;
            case DIR_SOUTH:
                cardPos = DIRECTION_SOUTH;
                break;
              case DIR_WEST:
                cardPos = DIRECTION_WEST;
                break;
        }
        return cardPos;
    }
