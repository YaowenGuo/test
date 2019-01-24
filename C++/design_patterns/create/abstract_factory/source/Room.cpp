#include "../include/Room.h"
#include "../include/MapSite.h"

Room::Room(int roomNo) {
    _roomNumber = roomNo;
}

MapSite* Room::getSide(Direction direction) const {
    return _sider[direction];
}

void Room::setSide(Direction direction, MapSite* mapSite) {
    _sider[direction] = mapSite;
}
