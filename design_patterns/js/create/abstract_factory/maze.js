// best
const has = Object.prototype.hasOwnProperty; // cache the lookup once, in module scope.
const Direction = {
    SORTH: 0,
    NORTH: 1,
    EAST: 2,
    WEST: 3,
};

const CreateTag = {
    ROOM: 'room',
    WALL: 'wall',
    DOOR: 'door',
};

class MapSite {
    static enter() {
        return false;
    }
}

class Room extends MapSite {
    constructor(roomNo) {
        super();
        this.side = {};
        this.roomNo = roomNo;
    }

    getSide(direction) {
        if (has.call(this.side, direction)) {
            return this.side[direction];
        }
        return undefined;
    }

    setDide(direction, site) {
        if (has.call(this.side, direction)) {
            this.side[direction] = site;
        }
    }
}

class Wall extends MapSite {
}

class Door extends MapSite {
    constructor(room1, room2) {
        super();
        this.room1 = room1;
        this.room2 = room2;
    }

    otherSideFrom(room) {
        if (room === this.room1) {
            return this.room2;
        } if (room === this.room2) {
            return this.room1;
        }
        return undefined;
    }
}

class Maze {
    constructor() {
        this.rooms = [];
    }

    addRoom(room) {
        this.rooms.push(room);
        return this;
    }

    roomAt(num) {
        return this.rooms.forEach((room) => {
            if (room.num === num) return room;
            return undefined;
        });
    }
}


class MazeFactory {
    constructor() {
        this.parts = {};
    }

    made(partName) {
        if (has.call(this.parts, partName)) {
            return new this.parts[partName]();
        }
        return undefined;
    }

    addPart(name, partTemplate) {
        this.parts[name] = partTemplate;
        return this;
    }
}

class MazePrototypeFactory {
    constructor() {
        this.parts = {};
    }

    made(partName) {
        if (has.call(this.parts, partName)) {
            return new this.parts[partName]();
        }
        return undefined;
    }

    addPart(name, partTemplate) {
        this.parts[name] = partTemplate;
        return this;
    }
}

class MazeGame {
    createMaze(mazeFactory) {
        this.room1 = mazeFactory.made(CreateTag.ROOM);
        this.room2 = mazeFactory.made(CreateTag.ROOM);
        this.aDoor = mazeFactory.made(CreateTag.DOOR);
        return new Maze()
            .addRoom(this.room1)
            .addRoom(this.room2);
    }
}


const mazeFactory = new MazeFactory();

mazeFactory.addPart(CreateTag.ROOM, Room)
    .addPart(CreateTag.DOOR, Door)
    .addPart(CreateTag.WALL, Wall);
const mazeGame = new MazeGame();
const maze = mazeGame.createMaze(mazeFactory);
