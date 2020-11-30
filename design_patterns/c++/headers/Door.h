#include "MapSite.h"
#include "Room.h"

#ifndef __HEADER_DOOR__
#define __HEADER_DOOR__

class Door : public MapSite {
public:
    Door(Room* = 0, Room* = 0);
    
    Room* otherSideFrom(Room*);

private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};

#endif
