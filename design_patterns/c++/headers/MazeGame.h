#include "create/abstract_factory/MazeFactory.h"
#include "create/prototype/MazePrototypeFactory.h"
#include "Maze.h"
/********************** Use Abstract Factory **********************/

class MazeGame {
public:
    Maze* createMaze(MazeFactory&);

    // Prototype implement Abstract Factory.

    Maze* createMaze(MazePrototypeFactory&);
};
