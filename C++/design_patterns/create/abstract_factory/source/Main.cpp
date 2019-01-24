#include <iostream>
#include "../include/MazeGame.h"
#include "../include/MazeFactory.h"
using namespace std;


int main() {
    MazeGame mazeGame;
    MazeFactory mazeFactory;
    Maze* maze = mazeGame.createMaze(mazeFactory);
    cout << "End" << endl;

    return 0;
}
