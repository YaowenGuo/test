#include "../../../headers//MazeFactory.h"

Maze* MazeFactory::makeMaze() const {
    return new Maze;
}
Wall* MazeFactory::makeWall() const {
    return new Wall;
}
Room* MazeFactory::makeRoom(int number) const {
    return new Room(number);
}

Door* MazeFactory::makeDoor(Room* r1, Room* r2) const {
    return new Door(r1, r2);
}
