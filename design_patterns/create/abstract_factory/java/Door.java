public class Door implement MapSite {
    private Room mRoom1, mRoom2
    Door(Room room1, Room room2) {
        mRoom1 = room1;
        mRoom2 = room2;
    }

    @Overwrite
    public bool enter () {
        return true;
    }

    public Room otherSideFrom(Room from) {
        if (from == null) return null;
        if (from == mRoom1) {
            return mRoom2;
        } else if (from == mRoom2) {
            return mRoom1
        } else {
            return null;
        }
    }
}
