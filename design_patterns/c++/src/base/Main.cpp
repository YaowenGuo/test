#include <iostream>
#include "../../headers/Maze.h"
#include "../../headers/create/abstract_factory/MazeFactory.h"
#include "../../headers/MazeGame.h"

#include "../../headers/create/abstract_factory/BombedMazeFactory.h"

using namespace std;

int main() {
  MazeGame game;
  MazeFactory mazeFactory;
  Maze* maze = game.createMaze(mazeFactory);
  cout << "End." << endl;

  // AbstractFactory
  BombedMazeFactory factory;
  maze = game.createMaze(factory);
  cout << "Abstract Factory end." << endl;

  return 0;
}
