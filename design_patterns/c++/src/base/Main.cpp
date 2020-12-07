#include <iostream>
#include "../../headers/Maze.h"
#include "../../headers/create/abstract_factory/MazeFactory.h"
#include "../../headers/MazeGame.h"

#include "../../headers/create/abstract_factory/BombedMazeFactory.h"
#include "../../headers/create/prototype/MazePrototypeFactory.h"
using namespace std;

/*int main() {
  MazeGame game;
  MazeFactory mazeFactory;
  Maze* maze = game.createMaze(mazeFactory);
  cout << "End." << endl;

  // AbstractFactory
  BombedMazeFactory factory;
  maze = game.createMaze(factory);
  cout << "Abstract Factory end." << endl;

  return 0;
}*/

/**
 * Prototype
 */
int main() {
  MazeGame game;
  MazePrototypeFactory simpleMazeFactory(new Maze, new Wall, new Room(0), new Door);
  Maze* maze = game.createMaze(simpleMazeFactory);

  // Another type maze game.
  MazePrototypeFactory bombedMazeFactory(new Maze, new Wall, new Room(0), new Door);
  maze = game.createMaze(bombedMazeFactory);
  return 0;
}
