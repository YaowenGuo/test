#include "../include/Maze.h"
#include "../include/Room.h"
#include "../include/Door.h"
#include "../include/Wall.h"
/******************* Abstract Factory ***********************/
#ifndef __HEADER_MAZE_FACTORY__
#define __HEADER_MAZE_FACTORY__

class MazeFactory {

public:
    Maze* makeMaze() const;
    Wall* makeWall() const;
    Room* makeRoom(int number) const;
    Door* makeDoor(Room*, Room*) const;
};

#endif
