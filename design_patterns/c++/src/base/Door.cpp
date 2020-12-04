#include "../../headers//Door.h"

Door::Door(Room* from, Room* to) {
    _room1 = from;
    _room2 = to;
    _isOpen = true;
}

Room* Door::otherSideFrom(Room* from) {
    if (from == _room1 && _isOpen) {
        return _room2;
    }
    if (from == _room2 && _isOpen) {
        return _room1;
    }
    return 0;
}


