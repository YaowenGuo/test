#ifndef DESIGN_PATTERNS_MAZE_PROTOTYPE_FACTORY_H
#define DESIGN_PATTERNS_MAZE_PROTOTYPE_FACTORY_H

#include "../../Door.h"
#include "../../Maze.h"
#include "../../Wall.h"

template<class MAZE, class WALL, class ROOM, class DOOR>
class MazePrototypeFactory {
public:
  MazePrototypeFactory(MAZE*, WALL*, ROOM*, DOOR*);

  MAZE* makeMaze() const;

  ROOM* makeRoom() const;

  WALL* makeWall() const;

  DOOR* makeDoor() const;

private:
  Room* _prototypeRoom;
  Maze* _prototypeMaze;
  Wall* _prototypeWall;
  Door* _prototypeDoor;
};




#endif // DESIGN_PATTERNS_MAZE_PROTOTYPE_FACTORY_H
