public class MazeGame {
    public static Maze createMaze(MazeFactory factory) {
        Maze aMaze = factory.makeMaze();
        Room room1 = factory.makeRoom(1);
        Room room2 = factory.makeRoom(2);
        Door aDoor = factory.makeDoor(room1, room2);

        aMaze.addRoom(room1);
        aMaze.addRoom(room2);

        room1.setSide(North, factory.makeWall());
        room1.setSide(East, aDoor);  
        room1.setSide(Sorth, factory.makeWall());
        room1.setSide(Wast, factory.makeWall());
        
        room1.setSide(North, factory.makeWall());
        room1.setSide(East, factory.makeWall());
        room1.setSide(Sorth, factory.makeWall());
        room1.setSide(West, aDoor);
        
        return aMaze;
    }
}
