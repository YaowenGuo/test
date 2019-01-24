#include "Room.h"

#ifndef __HEADER_MAZE__
#define __HEADER_MAZE__
/**
* Maze class is consist of MazeSite.
*/

class Maze {
public:

    void addRoom(Room*);
    /*
    * Find the room by room number.
    * @param roomNum room number.
    * return The room with input number, It will be null if on such a room.
    */
    Room* roomNo(int roomNum) const;

private:
    // ...
};

#endif
