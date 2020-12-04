#include "create/abstract_factory/MazeFactory.h"
#include "Maze.h"
/********************** Use Abstract Factory **********************/

class MazeGame {
public:
    Maze* createMaze(MazeFactory&);
};
