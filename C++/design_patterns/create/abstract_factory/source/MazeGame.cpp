#include "../include/MazeGame.h"
#include "../include/Maze.h"
#include "../include/Room.h"
#include "../include/Door.h"
#include "../include/Wall.h"


Maze* MazeGame::createMaze(MazeFactory& factory) {
    Maze* aMaze = factory.makeMaze();
    Room* room1 = factory.makeRoom(1);
    Room* room2 = factory.makeRoom(2);
    Door* aDoor = factory.makeDoor(room1, room2);

    aMaze->addRoom(room1);
    aMaze->addRoom(room2);

    room1->setSide(North, factory.makeWall());
    room1->setSide(East, aDoor);
    room1->setSide(South, factory.makeWall());
    room1->setSide(West, factory.makeWall());

    room2->setSide(North, factory.makeWall());
    room2->setSide(East, factory.makeWall());
    room2->setSide(South, factory.makeWall());
    room2->setSide(West, aDoor);

    return aMaze;
}
