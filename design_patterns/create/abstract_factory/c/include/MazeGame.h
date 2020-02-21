#include "MazeFactory.h"

/********************** Use Abstract Factory **********************/

class MazeGame {
public:
    Maze* createMaze(MazeFactory&);
};
