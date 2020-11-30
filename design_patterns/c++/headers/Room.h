#include "MapSite.h"

#ifndef __HEADER_ROOM__
#define __HEADER_ROOM__

class Room : public MapSite {
public:
    Room(int roomNo);

    MapSite* getSide(Direction) const;
    void setSide(Direction, MapSite*);

private:
    MapSite* _sider[4];
    int _roomNumber;
};

#endif
