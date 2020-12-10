//
// Created by Albert on 2020/12/9.
//

#ifndef DESIGN_PATTERNS_C_HEADERS_CREATE_BUILDER_MAZEBUILDER_H
#define DESIGN_PATTERNS_C_HEADERS_CREATE_BUILDER_MAZEBUILDER_H
#include "../../Maze.h"

class MazeBuilder {
public:
  virtual void buildMaze() { }
  virtual void buildRoom(int room) { }
  virtual void buildDoor(int roomFrom, int roomTo) { }
  virtual Maze* getMaze() { return 0; }
protected:
  MazeBuilder();
};

#endif //DESIGN_PATTERNS_C_HEADERS_CREATE_BUILDER_MAZEBUILDER_H
