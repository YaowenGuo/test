public class Room implement MapSite {
    int mRoomNo;
    MapSite[] mSide
    public Room(int num) {
        mRoomNo = num;
        side = new MazeSite[4];
    }

    public bool enter() {
        return true;
    }

    public void setSide(Direction direction, MapSite site) {
        switch(direction) {
            case East:
                mSide[0] = side;
                break;
            case South:
                mSide[1] = side;
                break;
            case East:
                mSide[2] = side;
                break;
            case North:
                mSide[3] = side;
                break;
        }
    }

    public MapSide getSide(Diretion direction) {
        switch(direction) {
            case East:
                return mSide[0];
                break;
            case South:
                return mSide[1];
                break;
            case East:
                return mSide[2];
                break;
            case North:
                return mSide[3];
                break;
            default:
                return null;
                break;
        }
    }

}
