enum Direction {North, South, East, West};

class MapSite {
public:
    virtual void enter() = 0;
};

class Room : public MapSite {
public:
    Room(int roomNo);

    MapSite* getSide(Direction) const;
    void setSide(Direction, MapSite*);

    virtual void enter();

private:
    MapSite* _sider[4];
    int _roomNumber;
};


class Wall : public MapSite {
public:
    Wall();

    virtual void enter();
};

class Door : public MapSite {
public:
    Door(Room* = 0, Room* = 0);

    virtual void enter();
    Room* otherSideFrom(Room*);

private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};

/**
* Maze class is consist of MazeSiteg.
*/

class Maze {
public:
    Maze();

    void addRoom(Room*);
    /*
    * Find the room by room number.
    * @param roomNum room number.
    * return The room with input number, It will be null if on such a room.
    */
    Room* roomNo(int roomNum) const;

private:
    // ...
};


/******************* Abstract Factory ***********************/

class MazeFactory {
public:
    MazeFactory();

    virtual Maze* makeMaze() const {
        return new Maze;
    }
    virtual Wall* makeWall() const {
        return new Wall;
    }
    virtual Room* makeRoom(int number) const {
        return new Room(number);
    }
    virtual Door* makeDoor(Room* r1, Room* r2) {
        return new Door(r1, r2);
    }
};

/********************** Use Abstract Factory **********************/

class MazeGame {
public:
    Maze* createMaze(MazeFactory&);
};


Maze* MazeGame::createMaze(MazeFactory& factory) {
    Maze* aMaze = factory.makeMaze();
    Room* room1 = factory.makeRoom(1);
    Room* room2 = factory.makeRoom(2);
    Door* aDoor = factory.makeDoor(room1, room2);

    aMaze->addRoom(room1);
    aMaze->addRoom(room2);

    room1->setSide(North, factory.makeWall());
    room1->setSide(East, aDoor);
    room1->setSide(South, factory.makeWall());
    room1->setSide(West, factory.makeWall());
    
    room2->setSide(North, factory.makeWall());
    room2->setSide(East, factory.makeWall());
    room2->setSide(South, factory.makeWall());
    room2->setSide(West, aDoor);

    return aMaze;
}
