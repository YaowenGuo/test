#ifndef DESIGN_PATTERNS_MAZE_PROTOTYPE_FACTORY_H
#define DESIGN_PATTERNS_MAZE_PROTOTYPE_FACTORY_H
#include "../../Room.h"
#include "../../Door.h"
#include "../../Maze.h"
#include "../../Wall.h"

/**
 * 该类并不是 Prototype 的部件，而是使用 Prototype 实现的 Abstract Factory.
 * 对比 Abstract Factory 的 MazeFactory 和其子类，减少了类的定义。
 */

class MazePrototypeFactory {
public:
  MazePrototypeFactory(Maze*, Wall*, Room*, Door*);

  Maze* makeMaze() const;

  Room* makeRoom() const;

  Wall* makeWall() const;

  Door* makeDoor() const;

private:
  Room* _prototypeRoom;
  Maze* _prototypeMaze;
  Wall* _prototypeWall;
  Door* _prototypeDoor;
};

#endif // DESIGN_PATTERNS_MAZE_PROTOTYPE_FACTORY_H
