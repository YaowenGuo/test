#include <iostream>
#include "../../headers/Maze.h"
#include "../../headers/MazeFactory.h"
#include "../../headers/MazeGame.h"

using namespace std;


int main() {
    MazeGame mazeGame;
    MazeFactory mazeFactory;
    Maze* maze = mazeGame.createMaze(mazeFactory);
    cout << "End" << endl;

    return 0;
}
